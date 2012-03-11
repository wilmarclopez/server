/**********************************************************************

   File          : Message.h

   Description   : Structure for messages. Users can change this

   Last Modified : 
   By            : Wilmarc Lopez

***********************************************************************/

#ifndef MESSAGE_H
#define MESSAGE_H

typedef struct MessageHeader_ {
	int length;		//length of body in size. this should always be present
	
	//add other header things here
} MessageHeader;

typedef struct Message_ {
	MessageHeader *hdr;
	void *body;
	int sock;	//socket descriptor of origin
} Message;

#endif
