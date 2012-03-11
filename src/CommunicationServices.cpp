#include "CommunicationServices.h"

CommunicationServices* CommunicationServices::getInstance()
{
	if (!INSTANCE)
		INSTANCE = new CommunicationServices;
	
	return INSTANCE;
}

int CommunicationServices::initServer(MessageProcessor *mp_p, int protocolPort)
{
	mp = mp_p;
	
	return 0; //temporary
}
