#include "Server.h"
#include "MessageProcessorImpl.h"

#define PORT "9157" //1405
#define POOL 50

int main()
{
	Server server(PORT, new MessageProcessorImpl, POOL);
	server.start();
	
	return 0;
}
