#include <stdio.h>
#include <stdlib.h>

#include<string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h> //included this for the close function

#include <netinet/in.h> //contains socket structs
#include "gflags/gflags.h"
constexpr int MAXLINE = 1024;

/* 
Code heavily inspirde from: https://www.geeksforgeeks.org/udp-server-client-implementation-c/
*/

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
	gflags::SetUsageMessage ("port_number");

    gflags::ParseCommandLineFlags(&argc, &argv, true);
    //const static int port_number = atoi(argv[1]);
    
    printf("Listening on port: %d \n", FLAGS_port_number);

	//const static int port_number = atoi(argv[1]);

	// creating client socket
	int network_socket = ::socket(AF_INET, SOCK_DGRAM, 0);
	char buffer[MAXLINE];
	char *client_message = "Client message";

	//instantiating client_address struct of type sockaddr_in
	::sockaddr_in server_address;

	// specify an address for the socket to connect to
	auto serveraddr_ptr = &server_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(FLAGS_port_number);
	server_address.sin_addr.s_addr = INADDR_ANY;

	socklen_t server_address_length = sizeof(server_address);

	::sendto(network_socket, (const char*)client_message, strlen(client_message), MSG_CONFIRM, (const struct sockaddr *)serveraddr_ptr, server_address_length);
	
	int n = ::recvfrom(network_socket, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)serveraddr_ptr, &server_address_length);

	buffer[n] = '\0';
	printf("Server: %s\n", buffer);
	close(network_socket);

	return 0;
}