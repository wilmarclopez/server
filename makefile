CXX = g++
SRC_DIR = ./src
INC_DIR = ./include
CFLAGS = -g -Wall -I$(INC_DIR)

Logger.o: $(SRC_DIR)/Logger.cpp
	$(CXX) -c $^ $(CFLAGS)

CommunicationServices.o: $(SRC_DIR)/CommunicationServices.cpp	Logger.o #ThreadPoolManager.o
	$(CXX) -c $^ $(CFLAGS)
	
clean:
	rm *.o
	
