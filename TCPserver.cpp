#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#define _XOPEN_SOURCE_EXTENDED 1
#include <unistd.h> //included this for the close function

#include <netinet/in.h>

int main()
{
    // data to be sent to cleints
    char server_message[256] = "Recieved message FUCK";

    int server_socket;

    // make socket call to get socket file descriptor
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define the server address
    struct sockaddr_in server_address;

    // specify family (AF_INET)
    server_address.sin_family = AF_INET;

    // specify port
    server_address.sin_port = htons(9002);

    // specify address
    // INADDR_ANY resolves to any IP address on local machine

    server_address.sin_addr.s_addr = INADDR_ANY;

    // need to bind server socket to specified IP address and port
    // first argument is socket file descriptor
    // second argument is the port number
    // third is size of server address
    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    // now that the server is bound to an address, we can enable server to listen
    // for connections from the clients
    // first argument is socket file descriptor
    // 2nd is backlog, how many connections can be waiting for this socket
    listen(server_socket, 5);

    // integer to hold client socket, when we listen for connections,
    // can begin to accept connections, accept call gives back client socket fd
    int client_socket;
    // first parameter is socket we are accepting connections on, aka server socket
    // next two params can be left as NULL for now
    client_socket = accept(server_socket, NULL, NULL);

    // we can send data to client
    // first arg is socket we are sending data to
    // second arg is data we want to send
    // third argument is size of message
    send(client_socket, server_message, sizeof(server_message), NULL);

    // can close socket
    close(server_socket);
    return 0;
}