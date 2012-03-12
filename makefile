CXX = g++
SRC_DIR = ./src
INC_DIR = ./include
TOOLS_DIR = ./tools
TP_DIR = $(TOOLS_DIR)/threadpool
BOOST_ROOT = ../boost
BOOST_THREAD_DIR = $(BOOST_ROOT)/stage/lib

CFLAGS = -g -Wall -I$(INC_DIR) -I$(BOOST_ROOT) -I$(TP_DIR)
LDFLAGS = -lpthread $(BOOST_ROOT) -lboost_thread -L$(BOOST_THREAD_DIR)



ThreadPoolManager.o: $(SRC_DIR)/ThreadPoolManager.cpp #ThreadPoolWork.o
	$(CXX) -c $(SRC_DIR)/ThreadPoolManager.cpp $(CFLAGS)

Logger.o: $(SRC_DIR)/Logger.cpp
	$(CXX) -c $^ $(CFLAGS)

CommunicationServices.o: $(SRC_DIR)/CommunicationServices.cpp	Logger.o #ThreadPoolManager.o
	$(CXX) -c $(SRC_DIR)/CommunicationServices.cpp $(CFLAGS)
	
clean:
	rm *.o
	
all: CommunicationServices.o ThreadPoolManager.o
	
