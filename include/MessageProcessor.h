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
		/**********************************************************************

			Function    : process
			Description : creates a TPWork using received msg and given protocol
			 				then submits it to tpm
			Inputs      : msg - Message to be processed
			Outputs     : none

		***********************************************************************/
		virtual void process(Message *msg) = 0;
		
		virtual void setThreadPoolManager(ThreadPoolManager *tpm_p) {
			tpm = tpm_p;
		};  
		
		virtual void setProtocol(Protocol *protocol_p) {
			protocol = protocol_p;
		};
		
	protected:
		ThreadPoolManager *tpm;
		Protocol *protocol;
};

#endif
