#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "CommunicationServices.h"
#include "Logger.h"

CommunicationServices::CommunicationServices()
{
	logger = Logger::getInstance();
}


CommunicationServices* CommunicationServices::getInstance()
{
	if (!INSTANCE)
		INSTANCE = new CommunicationServices;
	
	return INSTANCE;
}

int CommunicationServices::initServer(MessageProcessor *mp_p, 
	int tpProtocol, unsigned short int port)
{
	mp = mp_p;	//mp should have its tpm set here
	
	mainSocket = serverConnect(port, tpProtocol);
	
	return 0; //temporary
}



int CommunicationServices::start()
{
	int errored = 0, newsock = 0;
    fd_set readfds;
    
	/* check if initialized */
	if ( !mp || !mainSocket )
	{
		logger->error("CommunicationServices not initialized.\n");
		return -1;
	}
	
	/* Repeat until the socket is closed */
    while ( !errored )
    {
         FD_ZERO( &readfds );
         FD_SET( mainSocket, &readfds );
         if ( select(mainSocket+1, &readfds, NULL, NULL, NULL) < 1 )
         {
             /* Complain, explain, and exit */
              char msg[128];
              sprintf( msg, "failure selecting server connection [%.64s]\n",
                       strerror(errno) );
              logger->error( msg );
              errored = 1;
         }
         else
         {
			/* Accept the connect, receive request, and return */
			if ( (newsock = serverAccept(mainSocket)) != -1 )
			{
				Message *msg;	//mp should free this

				if (receiveReq( newsock, &msg ) < 0
					|| mp->process(msg) < 0) 
					errored = 1;					
				
				fflush( stdout );
			}
			else {
				/* Complain, explain, and exit */
				char msg[128];
				sprintf( msg, "failure accepting connection [%.64s]\n", 
					  strerror(errno) );
				logger->error( msg );
				errored = 1;
			}
         }
    }
    
    return 0;
}




int CommunicationServices::serverConnect( unsigned short int port, int tpProtocol )
{
	 /* Local variables */
     int sock;
     struct sockaddr_in inet;

     // Zero/Set the address
     memset( &inet, 0x0, sizeof(inet) );
     inet.sin_family = AF_INET;
     inet.sin_port = port;
     inet.sin_addr.s_addr = INADDR_ANY;

     /* Connect to the server */
     if ( (sock = socket( AF_INET, tpProtocol, 0)) == -1 )
     {
        /* Complain, explain, and return */
        char msg[128];
        sprintf( msg, "failed server socket create [%.64s]\n", 
                       strerror(errno) );
        logger->error( msg );
        exit( -1 );
     }

     /* Setup the socket option to reuse */
     int on = 1;
     setsockopt( sock, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

     // Call the connect
     if ( bind(sock, (struct sockaddr *)&inet, sizeof(inet)) != 0 )
     {
        /* Complain, explain, and return */
        char msg[128];
        sprintf( msg, "failed server socket bind [%.64s]\n", 
                       strerror(errno) );
        logger->error( msg );
        exit( -1 );
     }

     // Do the listen
     if ( listen(sock, 5) != 0 )
     {
        /* Complain, explain, and return */
        char msg[128];
        sprintf( msg, "failed server socket listen [%.64s]\n", 
                       strerror(errno) );
        logger->error( msg );
        exit( -1 );
     }

     /* Print a log message */
     char msg[128];
     sprintf( msg, "Server binding to port [%d], successful ...\n", 
             port  );
     logger->info(msg);     

     /* Return the file handle */
     return( sock );
}

int CommunicationServices::serverAccept( int sock )
{
	struct sockaddr_in inet;
	unsigned int inet_len = sizeof(inet), nsock;

     // Do the accept
     if ( (nsock = accept(sock, (struct sockaddr *)&inet, &inet_len)) == 0 )
     {
        /* Complain, explain, and return */
        char msg[128];
        sprintf( msg, "failed server socket accept [%.64s]\n", 
                       strerror(errno) );
        logger->error( msg );
        exit( -1 );
     }

     /* Return the new socket */
     return( nsock );
}

/*
int CommunicationServices::receiveReq( int sock, Message **msg )
{
	/* Read the message header *
     recvData( sock, (char *)hdr, sizeof(DhProtoMessageHdr), 
               sizeof(DhProtoMessageHdr) );
     hdr->length = ntohs(hdr->length);
     assert( hdr->length<MAX_BLOCK_SIZE );
     hdr->msgtype = ntohs( hdr->msgtype );
     if ( hdr->length > 0 )
        return( recvData( sock, block, hdr->length, hdr->length ) );
     return( 0 );
}
*/

