#ifndef TCPCLIENT_H
#define TCPCLIENT_H


class TCPclient 
{
private:
    int PortNumber;
    int ClientAddress;

public: 
    
    TCPclient();     //constructor 
    ~TCPclient();    //deconstructor


    //setters and getters;
    void setPortNumber(int port_number);
    int getPortNumber(void);
    void setClientAddress(int client_address);
    int getClientAddress(void);

};