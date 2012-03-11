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
	mp = mp_p;
	mainSocket = serverConnect(port, tpProtocol);
	
	return 0; //temporary
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
