/**********************************************************************

   File          : Server.h

   Description   : A Multi-threaded Server

   Last Modified : 
   By            : Wilmarc Lopez

***********************************************************************/

#ifndef TPOOL_H
#define TPOOL_H

#include "ThreadPoolManager.h"
#include "ThreadPoolWork.h"
#include "CommunicationServices.h"
#include "Logger.h"
#include "MessageProcessor.h"

class Server {
	public:
		Server(int protocolPort, MessageProcessor *mp, 
			ThreadPoolWork *tpwork, int poolSize);
		void start();
		void cleanup();
		
	protected:
		ThreadPoolManager *tpm;
		CommunicationServices *comm; //singleton
		Logger *logger;	//singleton
	
};

#endif
