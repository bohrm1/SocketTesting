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
constexpr int MAXLINE = 1024;


Client::Client(int port_number, std::string client_address, std::string comms_protocol) {

	PortNumber = port_number;
	ClientAddress = client_address;
	CommsProtocol = comms_protocol; 

	if (CommsProtocol == "TCP") {
		NetworkSocket = socket(AF_INET, SOCK_STREAM, 0);
		::sockaddr_in server_address;
		auto serveraddr_ptr = &server_address;

		server_address.sin_family = AF_INET;
		server_address.sin_port = htons(PortNumber);
		server_address.sin_addr.s_addr = INADDR_ANY;

		int connection_status = ::connect(NetworkSocket, (struct sockaddr *)serveraddr_ptr, sizeof(server_address));

		// check for error with connection. if connect = -1, means error connecting
		if (connection_status == -1)
		{
			printf("There was an error making a connection to the remote socket\n");
		}
		else 
		{
			// recieve data from the server using recv function
			char server_response[256]; // hold message that we get back from server
			int recieve_status = ::recv(NetworkSocket, &server_response, sizeof(server_response), 0);

			if(recieve_status == 256) {       //checking if the server message fills server_response
				printf("The server message has filled up the buffer: %s \n", server_response);
				printf("Recieve Status: %u \n", recieve_status);
			}
			else {
				printf("The server sent the data: %s \n", server_response);
				printf("Recieve Status: %u \n", recieve_status);
			}
		}
	}
	else {
		NetworkSocket = ::socket(AF_INET, SOCK_DGRAM, 0);
		char buffer[MAXLINE];
		char *client_message = "Client message";

		//instantiating client_address struct of type sockaddr_in
		::sockaddr_in server_address;

		// specify an address for the socket to connect to
		auto serveraddr_ptr = &server_address;

		server_address.sin_family = AF_INET;
		server_address.sin_port = htons(PortNumber);
		server_address.sin_addr.s_addr = INADDR_ANY;

		socklen_t server_address_length = sizeof(server_address);

		::sendto(NetworkSocket, (const char*)client_message, strlen(client_message), MSG_CONFIRM, (const struct sockaddr *)serveraddr_ptr, server_address_length);
		
		int n = ::recvfrom(NetworkSocket, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)serveraddr_ptr, &server_address_length);

		buffer[n] = '\0';
		printf("Server: %s\n", buffer);
	}
}

Client::~Client() {
	::close(NetworkSocket);
}

void Client::setPortNumber(int port_number) {
	PortNumber = port_number;
}

void Client::setClientAddress(std::string client_address) {
	ClientAddress = client_address;
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



