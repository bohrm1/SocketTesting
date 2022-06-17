#include <stdio.h>
#include <stdlib.h>

#include<string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h> //included this for the close function

#include <netinet/in.h> //contains socket structs
#define MAXLINE 1024

/* 
Code heavily inspirde from: https://www.geeksforgeeks.org/udp-server-client-implementation-c/
*/

int main(int argc, char *argv[])
{
	const static int port_number = atoi(argv[1]);

	// creating client socket
	int network_socket = ::socket(AF_INET, SOCK_STREAM, 0);
	char buffer[MAXLINE];
	char *client_message = "Client message";

	//instantiating client_address struct of type sockaddr_in
	::sockaddr_in server_address;

	// specify an address for the socket to connect to
	auto serveraddr_ptr = &server_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port_number);
	server_address.sin_addr.s_addr = INADDR_ANY;

	socklen_t server_address_length = sizeof(server_address);

	::sendto(network_socket, (const char*)client_message, strlen(client_message), MSG_CONFIRM, (const struct sockaddr *)serveraddr_ptr, server_address_length);
	
	socklen_t len = sizeof(server_address);

	int n = ::recvfrom(network_socket, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)serveraddr_ptr, &len);

	buffer[n] = '\0';
	printf("Server: %s\n", buffer);
	close(network_socket);

	return 0;
}