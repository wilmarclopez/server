/**********************************************************************

   File          : CommunicationServices.h

   Description   : Network communication needs. A Singleton but can 
    				actually just be static

   Last Modified : 
   By            : Wilmarc Lopez

***********************************************************************/

#ifndef COMM_SERVICES_H
#define COMM_SERVICES_H

#include "MessageProcessor.h"

class CommunicationServices{
	public:
	   static CommunicationServices* getInstance();  
	   void initServer(MessageProcessor *mp, int protocolPort);	//init for server
	
	private:
	   CommunicationServices();  // Private so that it can  not be called
	   CommunicationServices(CommunicationServices const&){};             // copy constructor is private
	   CommunicationServices& operator=(CommunicationServices const&){};  // assignment operator is private
	   
	   static CommunicationServices* INSTANCE;
	   MessageProcessor *mp;
	   
	   /**********************************************************************
		Everything below is from: 
			http://www.cse.psu.edu/~tjaeger/cse473-s08/cse473-s08-p2.html
	   

			Function    : connectClient
			Description : connnect a client to the server
			Inputs      : addr - the address ("a.b.c.d/port")
			Outputs     : file handle if successful, -1 if failure

		***********************************************************************/
		int connectClient( char *addr );

		/**********************************************************************

			Function    : serverConnect
			Description : connnect a server socket to listen for
			Inputs      : none
			Outputs     : file handle if successful, -1 if failure

		***********************************************************************/
		int serverConnect( void );

		/**********************************************************************

			Function    : serverAccept
			Description : get a new connection on the server socket
			Inputs      : sock - server socket
			Outputs     : file handle if successful, -1 if failure

		***********************************************************************/
		int serverAccept( int sock );

		/**********************************************************************

			Function    : recvData
			Description : receive data from the socket
			Inputs      : sock - server socket
						  blk - block to put data in
						  sz - maxmimum size of buffer
						  minsz - minimum bytes to read
			Outputs     : bytes read if successful, -1 if failure

		***********************************************************************/
		int recvData( int sock, char *blk, int sz, int minsz );

		/**********************************************************************

			Function    : sendData
			Description : send  data to the socket
			Inputs      : sock - server socket
						  blk - block to put data in
						  len - length of data to send
			Outputs     : 0 if successful, -1 if failure

		***********************************************************************/
		int sendData( int sock, char *blk, int len );
};

#endif
