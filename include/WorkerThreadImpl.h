#ifndef WORKER_IMPL_H
#define WORKER_IMPL_H

#include "threadpool.h"
#include "CommunicationServices.h"
#include "Message.h"
#include "Logger.h"

class WorkerThreadImpl : public WorkerThread
{
	protected:
		int id;
		Message *msg;
		CommunicationServices *comm;
		Logger *logger;
		
	
	public:
		WorkerThreadImpl(int id, Message *msg_p) : WorkerThread(id),
										id(id),
										msg(msg_p), 
										comm(CommunicationServices::getInstance()),
										logger(Logger::getInstance()){}
										
		~WorkerThreadImpl() {
			deallocMsg(msg);
		}
		
		unsigned executeThis();
	
};

#endif
