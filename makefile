CXX = g++
SRC_DIR = ./src
INC_DIR = ./include
TOOLS_DIR = ./tools
BOOST_ROOT = ../boost
BOOST_THREAD_DIR = $(BOOST_ROOT)/stage/lib

CFLAGS = -g -Wall -I$(INC_DIR) -I$(BOOST_ROOT)
LDFLAGS = -lpthread $(BOOST_ROOT) -lboost_thread -L$(BOOST_THREAD_DIR)

MessageProcessorImpl.o: $(SRC_DIR)/MessageProcessorImpl.cpp
	$(CXX) -c $(SRC_DIR)/MessageProcessorImpl.cpp $(CFLAGS)
	
WorkerThreadImpl.o: $(SRC_DIR)/WorkerThreadImpl.cpp
	$(CXX) -c $(SRC_DIR)/WorkerThreadImpl.cpp $(CFLAGS)

ThreadPool.o: $(SRC_DIR)/threadpool.cpp 
	$(CXX) -c $(SRC_DIR)/threadpool.cpp $(CFLAGS)

Logger.o: $(SRC_DIR)/Logger.cpp
	$(CXX) -c $^ $(CFLAGS)

CommunicationServices.o: $(SRC_DIR)/CommunicationServices.cpp	Logger.o ThreadPool.o
	$(CXX) -c $(SRC_DIR)/CommunicationServices.cpp $(CFLAGS)
	
Server.o: $(SRC_DIR)/Server.cpp Logger.o ThreadPool.o CommunicationServices.o
	$(CXX) -c $(SRC_DIR)/Server.cpp $(CFLAGS)
	
clean:
	rm *.o
	
all: CommunicationServices.o ThreadPool.o WorkerThreadImpl.o MessageProcessorImpl.o
	
