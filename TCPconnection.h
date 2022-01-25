#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <exception>

#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class TCPClient
{
private:
	int m_sock;
	struct sockaddr_in m_address;
	bool m_status = false;

public:
	TCPClient();
	void sendData(int data);
	bool tryConnect();

};
