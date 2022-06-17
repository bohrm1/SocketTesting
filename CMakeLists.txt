
#set version of cmake to version on server
cmake_minimum_required(VERSION "3.18.4")

#give project a name 
project(TCPtest)

#create executable target in cmake, requires name of executable
#also requires source code to build executable 
#note, spaces are used as delimiters 

#TCP files
add_executable(TCPserver TCPserver.cpp)
add_executable(TCPclient TCPclient.cpp)

#UDP files
add_executable(UDPserver UDPserver.cpp)
add_executable(UDPclient UDPclient.cpp)


