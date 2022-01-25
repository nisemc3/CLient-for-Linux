#include "TCPconnection.h"

TCPClient::TCPClient()
{
	m_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (m_sock >= 0)
	{
		//std::cout<<"Socket created success\n";
	}
	m_address.sin_family = AF_INET;
	m_address.sin_port = uint16_t(4444);
	m_address.sin_addr.s_addr = inet_addr("127.0.0.1");
}

void TCPClient::sendData(int data)
{
	if (m_status)
	{
		std::string temp = std::to_string(data);
		int i =	send(m_sock, temp.c_str(), sizeof(temp), MSG_NOSIGNAL);
		if (i == -1)
		{
			m_sock = socket(AF_INET, SOCK_STREAM, 0);
			m_status = false;
		}
	}
}

bool TCPClient::tryConnect()
{
	if (!m_status)
	{
		if ((connect(m_sock, (sockaddr*)&m_address, sizeof(m_address))) == -1)
		{
			m_status = false;
			return false;
		}
		else
		{
			m_status = true;
			return true;
		}	
	}
	else return true;
}