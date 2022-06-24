
#set version of cmake to version on server
cmake_minimum_required(VERSION "3.18.4")

#find_package(gflags REQUIRED)

#give project a name 
project(TCPtest)

#create executable target in cmake, requires name of executable
#also requires source code to build executable 
#note, spaces are used as delimiters 

#TCP files
#add_executable(TCPserver TCPserver.cpp)
#add_executable(TCPclient TCPclient.cpp)

#UDP files
#add_executable(UDPserver UDPserver.cpp)
#add_executable(UDPclient UDPclient.cpp)

#main file
add_executable(TCPserver TCPservermain.cpp TCPserver.cpp)
add_executable(TCPclient TCPclientmain.cpp TCPclient.cpp)

add_executable(server servermain.cpp server.cpp)
add_executable(client clientmain.cpp client.cpp)

#imported glfags library target
target_link_libraries(TCPserver gflags)
target_link_libraries(TCPclient gflags)

target_link_libraries(server gflags)
target_link_libraries(client gflags)

#target_link_libraries(UDPserver gflags)
#target_link_libraries(UDPclient gflags)

