#include "WorkerThreadImpl.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>

unsigned WorkerThreadImpl::executeThis()
{
	//check if correct message type
	if (msg->hdr.msgtype != CLIENT_REQUEST )
		return -1;
		
	/* Local variables */
	MessageHeader hdr;
	char block[MAX_BODY_SIZE];
	int arg = atoi(msg->body);

	/* Fake request processing with sleep */
	printf("Thread [%d]: do work - server sock: %d; req: %d\n", 
		id, msg->sock, arg );
	printf("====== work: %d seconds =======\n", arg );
	sleep(arg);

	/*
	check for cancellation -- like to set as committed to finish after here 
	printf("--- serverProcessReq[0x%x]: check terminate after work - server sock: %d; req: %d\n", 
	(unsigned)pthread_self(), sock, arg );
	YOUR CODE HERE (#4D)
	printf("serverProcessReq[0x%x]: no terminate after work - server sock: %d; req: %d\n", 
	(unsigned)pthread_self(), sock, arg );
	*/
		
	/* Build reply message */
	hdr.msgtype = SERVER_RESPONSE;
	hdr.length = 0;
	strcpy(block, "done");
	hdr.length += strlen(&block[hdr.length])+1;

	/* send the reply */
	printf("serverProcessReq[0x%x]: send response - server sock: %d; req: %d\n", 
	(unsigned)pthread_self(), msg->sock, arg );
	
	comm->sendMessage( msg->sock, &hdr, block );

	close(msg->sock);
	
	return 0;
}
