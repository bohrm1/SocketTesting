#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <unistd.h> //included this for the close function

#include <netinet/in.h>

    // accept port number as command line argument
   //  const static int default_port_number = 9002;
   // static int port_number = default_port_number;

int main(int argc, char *argv[])
{

    const static int port_number = atoi(argv[1]);

    // data to be sent to cleints
    char server_message[20] = "Recieved messagewww";

    

    // make socket call to get socket file descriptor
    const int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(server_socket < 0) {
        printf("Failed to creat server socket");
        exit(EXIT_FAILURE);
    }

    // define the server address
    ::sockaddr_in server_address;
    auto serveraddr_ptr = &server_address;
    // specify family (AF_INET)
    server_address.sin_family = AF_INET;

    // specify port
    server_address.sin_port = htons(port_number);

    // specify address
    // INADDR_ANY resolves to any IP address on local machine

    server_address.sin_addr.s_addr = INADDR_ANY;

    // need to bind server socket to specified IP address and port
    // first argument is socket file descriptor
    // second argument is the port number
    // third is size of server address
    // ::-->scoping operating
    //change 2nd argument to c++ cast
    if (::bind(server_socket, (sockaddr *)serveraddr_ptr, sizeof(server_address)) < 0) {
        printf("Error binding socket to address");
        exit(EXIT_FAILURE);
    }

    // now that the server is bound to an address, we can enable server to listen
    // for connections from the clients
    // first argument is socket file descriptor
    // 2nd is backlog, how many connections can be waiting for this socket
    ::listen(server_socket, 5);

    // integer to hold client socket, when we listen for connections,
    // can begin to accept connections, accept call gives back client socket fd

    // first parameter is socket we are accepting connections on, aka server socket
    // next two params can be left as NULL for now
    int client_socket = ::accept(server_socket, NULL, NULL);

    // we can send data to client
    // first arg is socket we are sending data to
    // second arg is data we want to send
    // third argument is size of message
    ::send(client_socket, server_message, sizeof(server_message), NULL);

    // can close socket
    ::close(server_socket);
    return 0;
}