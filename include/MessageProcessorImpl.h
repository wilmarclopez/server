#ifndef MSG_PROC_IMPL_H
#define MSG_PROC_IMPL_H

#include "MessageProcessor.h"
#include "Logger.h"

class MessageProcessorImpl : public MessageProcessor
{
	protected:
		int workerCount;
		Logger *logger;
		
	public:
		MessageProcessorImpl() :  MessageProcessor(),
								workerCount(0), 								
								logger(Logger::getInstance()) {}
		int process(Message* msg);
};

#endif
