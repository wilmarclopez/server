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
		Server(MessageProcessor *mp, ThreadPoolWork *tpwork, int poolSize);
		void start();
		
	protected:
		ThreadPoolManager *tpm;
		CommunicationServices *comm; //singleton
		Logger *logger;	//singleton
	
};

#endif
