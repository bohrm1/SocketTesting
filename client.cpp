#include <iostream>

#include <gflags/gflags.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h> //included this for the close function


#include <netinet/in.h> //contains socket structs

#include <string.h>
#include "client.h"


Client::Client(int port_number, std::string client_address, std::string comms_protocol) {

	PortNumber = port_number;
	ClientAddress = client_address;
	CommsProtocol = comms_protocol; 

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PortNumber);
	server_address.sin_addr.s_addr = INADDR_ANY;

	if (CommsProtocol == "TCP") {
		ClientSocket = socket(AF_INET, SOCK_STREAM, 0);
	}
	else if (CommsProtocol == "UDP") {
		ClientSocket = socket(AF_INET, SOCK_DGRAM, 0);
	}
}

Client::~Client() {
	::close(ClientSocket);
}

void Client::recieve(void) {

	if (CommsProtocol == "TCP") {
		//int connection_status = ::connect(NetworkSocket, (struct sockaddr *)serveraddr_ptr, sizeof(server_address));

		if (ConnectionStatus == -1)             								 // check for error with connection. if connect = -1, means error connecting
		{
			printf("There was an error making a connection to the remote socket\n");
		}
		else 
		{
			int recieve_status = ::recv(ClientSocket, &server_response, sizeof(server_response), 0);

			if(recieve_status == MAXLINE) {       //checking if the server message fills server_response
				printf("The server message has filled up the buffer: %s \n", server_response);
				printf("Recieve Status: %u \n", recieve_status);
			}
			else {
				printf("Server: %s \n", server_response);
				printf("Recieve Status: %u \n", recieve_status);
			}
		}
	}
	else {
		/*
		std::string client_message = "Client messages";   //char*
		//auto clippr = &client_message[0];

		// specify an address for the socket to connect to

		socklen_t server_address_length = sizeof(server_address);
		//::sendto(NetworkSocket, (const char*)client_message, strlen(client_message), MSG_CONFIRM, (const struct sockaddr *)serveraddr_ptr, server_address_length);
		::sendto(NetworkSocket, client_message.c_str(), client_message.length(), MSG_CONFIRM, (const struct sockaddr *)serveraddr_ptr, server_address_length);
		*/

		int n = ::recvfrom(ClientSocket, (char *)server_response, MAXLINE, MSG_WAITALL, (struct sockaddr *)serveraddr_ptr, &server_address_length);
		server_response[n] = '\0';
		printf("Server: %s\n", server_response);
		printf("Recieve Status: %u \n", n);
	}
}

void Client::send(void) {
	if (CommsProtocol == "TCP") {
		ConnectionStatus = ::connect(ClientSocket, (struct sockaddr *)serveraddr_ptr, sizeof(server_address));
	}
	else {
		std::string client_message = "Hello from client";   //char*
		::sendto(ClientSocket, client_message.c_str(), client_message.length(), MSG_CONFIRM, (const struct sockaddr *)serveraddr_ptr, server_address_length);
	}
}

void Client::setCommsProtocol(std::string comms_protocol) {
	CommsProtocol = comms_protocol;
}

int Client::getPortNumber(void) {
	return PortNumber;
}

std::string Client::getClientAddress(void) {
	return ClientAddress;
}

std::string Client::getCommmsProtocol(void) {
	return CommsProtocol; 
}



