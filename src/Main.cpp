#include "Server.h"
#include "MessageProcessorImpl.h"

#define PORT 1405
#define POOL 50

int main()
{
	Server server(PORT, new MessageProcessorImpl, POOL);
	
	return 0;
}
