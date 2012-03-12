#ifndef MSG_PROC_IMPL_H
#define MSG_PROC_IMPL_H

#include "MessageProcessor.h"
#include "WorkerThreadImpl.h"

class MessageProcessorImpl : public MessageProcessor
{
	protected:
		int workerCount;
		
	public:
		int process(Message* msg);
};

#endif
