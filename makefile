CXX = g++
SRC_DIR = ./src
INC_DIR = ./include
TOOLS_DIR = ./tools
BOOST_ROOT = ../boost
BOOST_THREAD_DIR = $(BOOST_ROOT)/stage/lib

CFLAGS = -g -Wall -I$(INC_DIR) -I$(BOOST_ROOT)
LDFLAGS = -lpthread $(BOOST_ROOT) -lboost_thread -L$(BOOST_THREAD_DIR)


ThreadPool.o: $(SRC_DIR)/threadpool.cpp #ThreadPoolWork.o
	$(CXX) -c $(SRC_DIR)/threadpool.cpp $(CFLAGS)

Logger.o: $(SRC_DIR)/Logger.cpp
	$(CXX) -c $^ $(CFLAGS)

CommunicationServices.o: $(SRC_DIR)/CommunicationServices.cpp	Logger.o ThreadPool.o
	$(CXX) -c $(SRC_DIR)/CommunicationServices.cpp $(CFLAGS)
	
clean:
	rm *.o
	
all: CommunicationServices.o ThreadPool.o
	
