#include "Message.h"

void deallocMsg(Message *msg)
{
	delete[] msg->body;
	delete msg;
}
