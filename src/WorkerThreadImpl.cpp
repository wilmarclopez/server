#include "WorkerThreadImpl.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>

unsigned WorkerThreadImpl::executeThis()
{
	logger->info("Executing worker thread");
	
	//check if correct message type
	if (msg->hdr.msgtype != CLIENT_REQUEST ) {
		cout << "\nSocket " << msg->sock << "msgtype = " << msg->hdr.msgtype;
		logger->warning("Not CLIENT_REQUEST");
		return -1;
	}
		
	/* Local variables */
	MessageHeader hdr;
	char block[MAX_BODY_SIZE];
	int arg = atoi(msg->body);

	/* Fake request processing with sleep */
	printf("Work on worker [%d]: do work - server sock: %d; req: %d\n", 
		id, msg->sock, arg );
	printf("====== work: %d seconds =======\n", arg );
	sleep(arg);

	/* Build reply message */
	hdr.msgtype = SERVER_RESPONSE;
	hdr.length = 0;
	strcpy(block, "done");
	hdr.length += strlen(&block[hdr.length])+1;

	/* send the reply */
	printf("Proessing request on worker[%d]: send response - server sock: %d; req: %d\n", 
		id, msg->sock, arg );
	
	
	comm->sendMessage( msg->sock, &hdr, block );

	close(msg->sock);
	
	
	return 0;
}
