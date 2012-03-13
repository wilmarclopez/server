#include "MessageProcessorImpl.h"
#include "WorkerThreadImpl.h"

int MessageProcessorImpl::process(Message* msg)
{
	if (!tp) {
		logger->error("MessageProcessor: thread pool not initialized");
		return -1;
	}
	
	logger->info("Creating thread work.");
	WorkerThreadImpl* work = new WorkerThreadImpl(workerCount++, msg);
	
	tp->assignWork(work);
	
	return 0;
}
