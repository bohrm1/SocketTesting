#include <stdio.h>
#include <stdlib.h>

#include<string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <unistd.h> //included this for the close function

#include <netinet/in.h>
#include "gflags/gflags.h"
constexpr int MAXLINE = 1024;



static bool ValidatePort(const char* flagname, int32_t value) {
   if (value > 0 && value < 32768)   // value is ok
     return true;
   printf("Invalid value for --%s: %d\n", flagname, (int)value);
   return false;
}

DEFINE_int32(port_number, 9002, "What port to listen on");
DEFINE_validator(port_number, &ValidatePort);

int main(int argc, char *argv[])
{
    gflags::SetVersionString("1.0");

    gflags::SetUsageMessage(
      "port_number"); 

    gflags::ParseCommandLineFlags(&argc, &argv, true);
    //const static int port_number = atoi(argv[1]);
    
    printf("Listening on port: %d \n", FLAGS_port_number);
    char *server_message = "Server message";
    char buffer[MAXLINE]; //take out macro 

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
    server_address.sin_port = htons(FLAGS_port_number);
    server_address.sin_addr.s_addr = INADDR_ANY;

 
    if (::bind(server_socket, (sockaddr *)serveraddr_ptr, sizeof(server_address)) < 0) {
        printf("Failed to bind socket to address");
        exit(EXIT_FAILURE);
    }

    socklen_t client_address_length = sizeof(client_address);

    /* recvfrom() returns the length of the message written to the buffer pointed by 
    the buffer argument. \0 is the null termination character and it marks the end of 
    the string. I'm assuming thats the point of the buffer[n] line */
    int n = ::recvfrom(server_socket, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)clientaddr_ptr, &client_address_length);
    buffer[n] = '\0';
    printf("Client: %s \n", buffer);

    
    ::sendto(server_socket, (const char *)server_message, strlen(server_message), MSG_CONFIRM, (const struct sockaddr *)clientaddr_ptr, client_address_length);

    gflags::ShutDownCommandLineFlags();
    return 0;
}
