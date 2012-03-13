/**********************************************************************

   File          : Server.h

   Description   : A Multi-threaded Server

   Last Modified : 
   By            : Wilmarc Lopez

***********************************************************************/

#ifndef TPOOL_H
#define TPOOL_H

#include "threadpool.h"
#include "CommunicationServices.h"
#include "Logger.h"
#include "MessageProcessor.h"

class Server {
	public:
		Server(char* protocolPort, MessageProcessor *mp, int poolSize);
		void start();
		void cleanup();
		
	protected:
		ThreadPool tp;
		CommunicationServices *comm; //singleton
		Logger *logger;	//singleton
	
};

#endif
