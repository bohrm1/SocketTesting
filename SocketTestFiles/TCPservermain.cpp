#include <stdio.h>
#include <stdlib.h>

#include<string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h> //included this for the close function

#include <netinet/in.h> //contains socket structs
#include "gflags/gflags.h"

#include "TCPserver.h"


static bool ValidatePort(const char* flagname, int32_t value) {
   if (value > 0 && value < 32768)   // value is ok
     return true;
   printf("Invalid value for --%s: %d\n", flagname, (int)value);
   return false;
}

DEFINE_int32(port_number, 9002, "What port to listen on");
DEFINE_validator(port_number, &ValidatePort);

int main (int argc, char *argv[])  {


    gflags::SetVersionString("1.0");
	  gflags::SetUsageMessage ("port_number");
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    printf("Listening on port: %d \n", FLAGS_port_number);

    TCPserver server1(FLAGS_port_number, "example_address");

    gflags::ShutDownCommandLineFlags();
    return 0;
}