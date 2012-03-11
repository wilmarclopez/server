/**********************************************************************

   File          : MessageProcessor.h

   Description   : Abstract class to be implemented by the protocol

   Last Modified : 
   By            : Wilmarc Lopez

***********************************************************************/

#ifndef MSG_PROC_H
#define MSG_PROC_H

#include "Message.h"

class MessageProcessor{
	public:
		/*
		virtual MessageProcessor();  
		virtual ~MessageProcessor(); 
		virtual MessageProcessor(MessageProcessor const&);           
		virtual MessageProcessor& operator=(MessageProcessor const&); 
		*/
		virtual void process(Message *msg) = 0;	   
};

#endif
