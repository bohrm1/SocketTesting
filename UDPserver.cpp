#include <stdio.h>
#include <stdlib.h>

#include<string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <unistd.h> //included this for the close function

#include <netinet/in.h>
#define MAXLINE 1024



int main(int argc, char *argv[])
{
    const static int port_number = atoi(argv[1]);
    char *server_message = "Recieved messagewww";
    char buffer[MAXLINE];

    const int server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    // make socket call to get socket file descriptor
    if (server_socket < 0) {
        printf("Failed to create socket");
        exit(EXIT_FAILURE);
    };

    // instantiate the server and client address
    ::sockaddr_in server_address, client_address;
    auto serveraddr_ptr = &server_address;
    auto clientaddr_ptr = &client_address;
    
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = INADDR_ANY;

 
    if (::bind(server_socket, (sockaddr *)serveraddr_ptr, sizeof(server_address)) < 0) {
        printf("Failed to bind socket to address");
        exit(EXIT_FAILURE);
    }

    socklen_t client_address_length = sizeof(client_address);

    /* recvfrom() returns the length of the message written to the buffer pointed by 
    the buffer argument. \0 is the null termination character and it marks the end of 
    the string. I'm assuming thats the point of the buffer[n] line */
    int n = ::recvfrom(server_socket, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &client_address, &client_address_length);
    buffer[n] = '\0';
    printf("Client: %s \n", buffer);

    
    ::sendto(server_socket, (const char *)server_message, strlen(server_message), MSG_CONFIRM, (const struct sockaddr *)clientaddr_ptr, client_address_length);

    return 0;
}
