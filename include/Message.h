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
	unsigned short msgtype;	//message type. this should always be present
	unsigned short length;		//length of body in size. this should always be present
	
	//add other header things here
	
	//constructors
	MessageHeader_(unsigned short msgtype_p, unsigned short length_p)
		: msgtype(msgtype_p), length(length_p) {}
	MessageHeader_() : msgtype(-1), length(0) {}
} MessageHeader;

/* This is the message */
typedef struct Message_ {
	MessageHeader hdr;
	char *body;
	int sock;	//socket descriptor of origin
	
	//constructors
	Message_(MessageHeader hdr_p, char *body_p, int sock_p)
		:hdr(hdr_p), body(body_p), sock(sock_p) {}
	Message_() : body(0), sock(-1) {}
} Message;

extern void deallocMsg(Message *msg);


#endif
