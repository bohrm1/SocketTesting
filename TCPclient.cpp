#include <iostream>

#include <gflags/gflags.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h> //included this for the close function


#include <netinet/in.h> //contains socket structs

#include <string>
#include "TCPclient.h"


TCPclient::TCPclient(int port_number, std::string client_address) {
	PortNumber = port_number;
	ClientAddress = client_address;
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
			printf("Server: %s \n", server_response);
			printf("Recieve Status: %u \n", recieve_status);
		}
	}
}

TCPclient::~TCPclient() {
	::close(NetworkSocket);
}

void TCPclient::setPortNumber(int port_number) {
	PortNumber = port_number;
}

void TCPclient::setClientAddress(std::string client_address) {
	ClientAddress = client_address;
}

int TCPclient::getPortNumber(void) {
	return PortNumber;
}

std::string TCPclient::getClientAddress(void) {
	return ClientAddress;
}


/*  
int main(int argc, char *argv[])
{

	// creating client socket
	int network_socket = socket(AF_INET, SOCK_STREAM, 0);

	// integer to hold port # from command line argument
	// want to take second string argument to use as port #
	// check argc
	const static int port_number = atoi(argv[1]);

	// specify an address for the socket to connect to
	::sockaddr_in server_address;
	auto serveraddr_ptr = &server_address;

	// need to define a few fields within the sockaddr_in struct
	// what is the family
	server_address.sin_family = AF_INET;
	// specify port
	// htons = host to network (making sure data format is correct)
	// puts integer port into correct byte order
	// pass the actual port, htons takes care of conversion
	server_address.sin_port = htons(port_number);

	// specify actual address
	// server_address is a struct with a sin_addr struct member which contains
	// s_addr field
	// conecting to loval machine, can use any address connected to local machine
	server_address.sin_addr.s_addr = INADDR_ANY;

	// first arg is actual socket
	// 2nd param, need to cast pointer  to struct sockaddr
	// 3rd param is size of address
	int connection_status = ::connect(network_socket, (struct sockaddr *)serveraddr_ptr, sizeof(server_address));

	// check for error with connection. if connect = -1, means error connecting
	if (connection_status == -1)
	{
		printf("There was an error making a connection to the remote socket\n");
	}
	else 
	{
		// recieve data from the server using recv function
		char server_response[256]; // hold message that we get back from server
		int recieve_status = ::recv(network_socket, &server_response, sizeof(server_response), 0);

		if(recieve_status == 256) {       //checking if the server message fills server_response
			printf("The server message has filled up the buffer: %s \n", server_response);
			printf("Recieve Status: %u \n", recieve_status);
		}
		else {
			printf("The server sent the data: %s \n", server_response);
			printf("Recieve Status: %u \n", recieve_status);
		}

		// and then close the socket
		::close(network_socket);
	}
	return 0;
}


*/