/**********************************************************************

   File          : Message.h

   Description   : Structure for messages. Users can change this

   Last Modified : 
   By            : Wilmarc Lopez

***********************************************************************/

#ifndef MESSAGE_H
#define MESSAGE_H

/* This is the message type */
typedef enum {
     CLIENT_REQUEST,            /* message 1 - start exchange */
     SERVER_RESPONSE,           /* message 2 - server response */ 
} MessageType;

/* This is the message header */
typedef struct MessageHeader_ {
	int length;		//length of body in size. this should always be present
	MessageType mt;	//message type. this should always be present
	
	//add other header things here
} MessageHeader;

/* This is the message */
typedef struct Message_ {
	MessageHeader *hdr;
	void *body;
	int sock;	//socket descriptor of origin
} Message;

#endif
