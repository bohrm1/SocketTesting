# SocketTesting
This repo was made for testing sockets as part of Rice University's REU program. The current working branch socket_new.

The breakdown of the files is as follows. The SocketTestFiles directory holds the files used to create UDP and TCP client-server models. The files are organized in the following manner: 

  1. TCPclient.cpp and TCPclient.h form the TCPclient class. A TCPclient object is instantiated in the TCPclientmain.cpp file. The TCPclient.cpp and TCPclientmain.cpp are compiled into an executable called TCPclient. Similarly, TCPserver.cpp and TCPserver.h form the TCPserver class. A TCPserver object is instantiated in the TCPservermain.cpp file. The TCPserver.cpp and TCPservermain.cpp are compiled into an executable called TCPserver. In order to form a communication between the server and client, the server must be run first (./TCPserver) followed by the client (./TCPclient). The port number can be specified on the command line using the --port_number GFLAG.
  
  2. UDPclient.cpp and UDPclient.h form the UDPclient class. A UDPclient object is instantiated in      the UDPclientmain.cpp file. The UDPclient.cpp and UDPclientmain.cpp are compiled into an executable called UDPclient. Similarly, UDPserver.cpp and UDPserver.h form the UDPserverclass. A UDPserver object is instantiated in the UDPservermain.cpp file. The UDPserver.cpp and UDPservermain.cpp are compiled into an executable called UDPserver. In order to form a communication between the server and client, the server must be run first (./UDPserver) followed by the client (./UDPclient). The port number can be specified on the command line using the --port_number GFLAG in which an integer is specified (default port number is 9002)
 
  3. A general client class where both UDP and TCP sockets are used was made in the client.cpp and client.h files. A client object is instantiated in the clientmain.cpp file. Similarly, a general server class where both UDP and TCP sockets are used is formed in the server.cpp and server.h files. A server object is instatiated in the servermain.cpp file. The client.cpp and clientmain.cpp are compiled into an executable called client and the server.cpp and servermain.cpp are compiled into an executable called server. In order to form a communication between the server and client, the server must be run first (./server) followed by the client (./client). The port number can be specified on the command line using the --port_number GFLAG in which an integer is specified (default port number is 9002). Moreover, the communication protocol can be specified on the command line using the --comms_protocol GLFAG in which a string is specified (default communication protocol is "TCP").
  
  4. The clientservermain.cpp file uses multithreading the execute the client and server class files from (3) in parallel. It is compiled into an exectuable called clientserver which is the only executable that needs to be run (./clientserver). 
  
  5. The CMakeLists.txt is used by CMake to make the make file which is located inside the build directory. 
  
  
The AgoraFiles directory holds the files from the Agora repo. The UDPServerIPv6 class was modified to be able to send IPv4 traffic to the client class. The files are organized as follows:

  1. The UDPServerIPv6 class from the udp_server_ipv6.cc and udp_server_ipv6.h files was modified such that it can send IPv4 traffic to the UDPClient class from the udp_client.cc and udp_client.h files. The test_udp_client_server.cc file uses multithreading to run the server and client. 
  
  2. The other files, gettime.h, logger.h symbols.h, utils.cc, and utils.h were needed in order for the client and server to operate correctly. 
  
  3. The CMakeLists.txt is used by CMake to make the make file which is located inside the build directory. 

