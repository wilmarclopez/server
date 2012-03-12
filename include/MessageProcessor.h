/**********************************************************************

   File          : MessageProcessor.h

   Description   : Abstract class to be inherited and implemented by user

   Last Modified : 
   By            : Wilmarc Lopez

***********************************************************************/

#ifndef MSG_PROC_H
#define MSG_PROC_H

#include "Message.h"
#include "threadpool.h"

class MessageProcessor{
	public:
		/**********************************************************************

			Function    : process
			Description : creates a TPWork for the protocol using received msg and given protocol then submits it to tpm
			Inputs      : msg - Message to be processed
			Outputs     : non-zero when errored, zero otherwise

		***********************************************************************/
		virtual int process(Message *msg) = 0;

		virtual void setThreadPool(ThreadPool *tp_p) {

			tp = tp_p;
		}		
		
				
	protected:
		ThreadPool *tp;
		
};

#endif
