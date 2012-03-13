#include "Server.h"
#include "MessageProcessorImpl.h"
#include <cstdlib>
#include <cstdio>

#define PORT "9157" //1405
#define POOL 50

int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("Usage: <port> <poolsize>\n");
		return -1;
	}
	
	Server server(argv[1], new MessageProcessorImpl, atoi(argv[2]));
	server.start();
	
	return 0;
}
