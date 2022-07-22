#include <stdio.h>
#include <stdlib.h>

#include<string.h>
#include "gflags/gflags.h"

#include "server.h"
#include "client.h"

#include <thread>

#include <chrono>


static bool ValidatePort(const char* flagname, int32_t value) {
   if (value > 0 && value < 32768)   // value is ok
     return true;
   printf("Invalid value for --%s: %d\n", flagname, (int)value);
   return false;
}

DEFINE_int32(port_number, 9002, "What port to listen on");
DEFINE_validator(port_number, &ValidatePort);

DEFINE_string(comms_protocol, "TCP", "Communication protocol (TCP/UDP). Defualt is TCP");
//DEFINE_validator(port_number, &ValidatePort);
void DoServer(Server &myserver) {
    std::string message = "Hello from server";
    myserver.recieve();
    myserver.send(message); 
}

void DoClient(Client &myclient) {
    myclient.send();
    myclient.receive(); 
}

void Dumb(void) {
    printf("1");
}

int main (int argc, char *argv[])  {
    gflags::SetVersionString("1.0");
	gflags::SetUsageMessage ("port_number, comms_protocol");
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    printf("Listening on port: %d \n", FLAGS_port_number);
    printf("Communication protocol: %s \n", FLAGS_comms_protocol.c_str());

    Server server1(FLAGS_port_number, "example_address", FLAGS_comms_protocol);
    Client client1(FLAGS_port_number, "example_address", FLAGS_comms_protocol);

    //DoServer(server1);
    std::thread serverthread(DoServer, std::ref(server1));
    std::thread clientthread(DoClient, std::ref(client1));
    //std::this_thread::sleep_for(std::chrono::seconds(2));
    //DoClient(client1);

    //sychronize threads, main thread waits for serverthread and clienthread to finish 
    serverthread.join();  
    clientthread.join();

    gflags::ShutDownCommandLineFlags();
    return 0;
}

