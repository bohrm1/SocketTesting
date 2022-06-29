#include<iostream>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <unistd.h> //included this for the close function

#include <netinet/in.h>
#include <string.h>

#include "server.h"

Server::Server(int port_number, const std::string &server_addr, const std::string &comms_protocol) {
    PortNumber = port_number;
    ServerAddr = server_addr;
    CommsProtocol = comms_protocol;

    //char server_message[] = "Server Message";

    /* 
    ::sockaddr_in server_address, client_address;
    ::sockaddr_in* serveraddr_ptr = &server_address;
    ::sockaddr_in* clientaddr_ptr = &client_address;
    */

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //printf("Before socket() call");
    //fflush(stdout);
    if (CommsProtocol == "TCP") {
        ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
    }
    else if (CommsProtocol == "UDP") {
        ServerSocket = socket(AF_INET, SOCK_DGRAM, 0);
    }

    //printf("before socket bind()");
    //fflush(stdout);
    if(ServerSocket < 0) {
        printf("Failed to creat server socket");
        exit(EXIT_FAILURE);
    }

    if (::bind(ServerSocket, (sockaddr *)serveraddr_ptr, sizeof(server_address)) < 0) {
        printf("Error binding socket to address");
        exit(EXIT_FAILURE);
    }
    //printf("after socket bind");
    //fflush(stdout);
    /*
    if (CommsProtocol == "TCP") {
    
        ::listen(ServerSocket, 5);

        int client_socket = ::accept(ServerSocket, NULL, NULL);

        ::send(client_socket, server_message, sizeof(server_message), NULL);
    }
    else {
        char buffer[MAXLINE]; 
        
        socklen_t client_address_length = sizeof(client_address);

        int n = ::recvfrom(ServerSocket, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)clientaddr_ptr, &client_address_length);
        buffer[n] = '\0';
        printf("Client: %s \n", buffer);

        ::sendto(ServerSocket, (const char *)server_message, strlen(server_message), MSG_CONFIRM, (const struct sockaddr *)clientaddr_ptr, client_address_length);
    } */
}

Server::~Server() {
    ::close(ServerSocket);
}

void Server::send(const std::string &server_message) {
    if (CommsProtocol == "TCP") {

        
        /*
        const int backlog = 1;
        ::listen(ServerSocket, backlog);

        int client_socket = ::accept(ServerSocket, NULL, NULL);
        */

       // ::send(client_socket, server_message, sizeof(server_message), NULL);
       ::send(ClientSocket, server_message.c_str(), server_message.length(), 0);
    }
    else {        
        socklen_t client_address_length = sizeof(client_address);

        /*
        int n = ::recvfrom(ServerSocket, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)clientaddr_ptr, &client_address_length);   //why am I sending so many bytes? 
        buffer[n] = '\0';
        printf("Client: %s \n", buffer);
        */

        ::sendto(ServerSocket, server_message.c_str(), server_message.length(), MSG_CONFIRM, (const struct sockaddr *)clientaddr_ptr, client_address_length);
    }
}

void Server::recieve (void) {
    if (CommsProtocol == "TCP") {
        const int backlog = 1;
        ::listen(ServerSocket, backlog);
        ClientSocket = ::accept(ServerSocket, NULL, NULL);
    }
    else {
        socklen_t client_address_length = sizeof(client_address);
        int n = ::recvfrom(ServerSocket, (char *)buffer, MAXLINE_CLIENTBUFFER, MSG_WAITALL, (struct sockaddr *)clientaddr_ptr, &client_address_length);   //why am I sending so many bytes? 
        buffer[n] = '\0';
        printf("Client: %s \n", buffer);
    }
}

int Server::getPortNumber(void) {
    return PortNumber;
}

std::string Server::getServerAddress(void) {
    return ServerAddr; 
}

std::string Server::getCommsProtocol(void) {
    return CommsProtocol;
}