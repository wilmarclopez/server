CXX = g++
SRC_DIR = ./src
INC_DIR = ./include
CFLAGS = -g -Wall -I$(INC_DIR)

CommunicationServices.o: $(SRC_DIR)/CommunicationServices.cpp	#Logger.o ThreadPoolManager.o
	$(CXX) -c $^ $(CFLAGS)
	
clean:
	rm *.o
	
