/**********************************************************************

   File          : Message.h

   Description   : Structure for messages. Users can change this

   Last Modified : 
   By            : Wilmarc Lopez

***********************************************************************/

#ifndef MESSAGE_H
#define MESSAGE_H

#define MAX_BODY_SIZE 8096

/* This is the message type */
typedef enum {
     CLIENT_REQUEST,            /* message 1 - start exchange */
     SERVER_RESPONSE,           /* message 2 - server response */ 
} MessageType;

/* This is the message header */
typedef struct MessageHeader_ {
	unsigned short length;		//length of body in size. this should always be present
	unsigned short msgtype;	//message type. this should always be present
	
	//add other header things here
} MessageHeader;

/* This is the message */
typedef struct Message_ {
	MessageHeader hdr;
	char *body;
	int sock;	//socket descriptor of origin
} Message;

extern void deallocMsg(Message *msg);


#endif
