#include "Server.h"

#include <sys/types.h>
#include <sys/socket.h>

Server::Server(unsigned short int protocolPort, MessageProcessor *mp, int poolSize) : tp(poolSize)
{
	comm = CommunicationServices::getInstance();
	mp->setThreadPool(&tp);
	comm->initServer(mp, SOCK_STREAM ,protocolPort);
	logger = Logger::getInstance();
}

void Server::start()
{
	comm->start();
}

void Server::cleanup()
{
	
}
