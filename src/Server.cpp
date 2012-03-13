#include "Server.h"

#include <sys/types.h>
#include <sys/socket.h>

Server::Server(char* protocolPort, MessageProcessor *mp, int poolSize) : tp(poolSize)
{
	logger = Logger::getInstance();
	
	logger->info("Initializing thread pool ...");
	
	tp.initializeThreads();
	mp->setThreadPool(&tp);		
	
	comm = CommunicationServices::getInstance();
	comm->initServer(mp, SOCK_STREAM ,protocolPort);
}

void Server::start()
{
	comm->start();
}

void Server::cleanup()
{
	
}
