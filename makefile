CXX = g++
SRC_DIR = ./src
INC_DIR = ./include
CFLAGS = -g -Wall -I$(INC_DIR)

#ThreadPoolManager.o: $(SRC_DIR)/ThreadPooManager.cpp #ThreadPoolWork.o

Logger.o: $(SRC_DIR)/Logger.cpp
	$(CXX) -c $^ $(CFLAGS)

CommunicationServices.o: $(SRC_DIR)/CommunicationServices.cpp	Logger.o #ThreadPoolManager.o
	$(CXX) -c $(SRC_DIR)/CommunicationServices.cpp $(CFLAGS)
	
clean:
	rm *.o
	
all: CommunicationServices.o
	
