#include<iostream>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <unistd.h> //included this for the close function

#include <netinet/in.h>
#include <string.h>

#include "server.h"
constexpr int MAXLINE = 1024;


Server::Server(int port_number, std::string server_addr, std::string comms_protocol) {
    PortNumber = port_number;
    ServerAddr = server_addr;
    CommsProtocol = comms_protocol;

    ::sockaddr_in server_address, client_address;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (CommsProtocol == "TCP") {
        ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
    }
    else if (CommsProtocol == "UDP") {
        ServerSocket = socket(AF_INET, SOCK_DGRAM, 0);
    }

    auto serveraddr_ptr = &server_address;
    auto clientaddr_ptr = &client_address;

    char server_message[] = "Server Message ahh";

    if(ServerSocket < 0) {
        printf("Failed to creat server socket");
        exit(EXIT_FAILURE);
    }

    if (CommsProtocol == "TCP") {
     
        if (::bind(ServerSocket, (sockaddr *)serveraddr_ptr, sizeof(server_address)) < 0) {
            printf("Error binding socket to address");
            exit(EXIT_FAILURE);
        }

        ::listen(ServerSocket, 5);

        int client_socket = ::accept(ServerSocket, NULL, NULL);

        ::send(client_socket, server_message, sizeof(server_message), NULL);
    }
    else {
        char buffer[MAXLINE]; 
        
        if (::bind(ServerSocket, (sockaddr *)serveraddr_ptr, sizeof(server_address)) < 0) {
            printf("Failed to bind socket to address");
            exit(EXIT_FAILURE);
        }

        socklen_t client_address_length = sizeof(client_address);

        int n = ::recvfrom(ServerSocket, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)clientaddr_ptr, &client_address_length);
        buffer[n] = '\0';
        printf("Client: %s \n", buffer);

        ::sendto(ServerSocket, (const char *)server_message, strlen(server_message), MSG_CONFIRM, (const struct sockaddr *)clientaddr_ptr, client_address_length);
    }
}

Server::~Server() {
    ::close(ServerSocket);
}

void Server::setPortNumber(int port_number) {
    PortNumber = port_number;
} 

void Server::setServerAddress(std::string server_addr) {
    ServerAddr = server_addr;
}

int Server::getPortNumber(void) {
    return PortNumber;
}

std::string Server::getServerAddress(void) {
    return ServerAddr; 
}
