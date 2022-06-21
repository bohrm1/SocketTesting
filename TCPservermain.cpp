#include <stdio.h>
#include <stdlib.h>

#include<string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h> //included this for the close function

#include <netinet/in.h> //contains socket structs
#include "gflags/gflags.h"

#include "TCPserver.h"


int main (int argc, char *argv[])  {

    TCPserver server1(9002, "example_address");

    return 0;
}