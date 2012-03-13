CXX = g++
SRC_DIR = ./src
INC_DIR = ./include
TOOLS_DIR = ./tools
BOOST_ROOT = ../boost
BOOST_THREAD_DIR = $(BOOST_ROOT)/stage/lib

CFLAGS = -g -Wall -I$(INC_DIR) -I$(BOOST_ROOT)
LDFLAGS = -lpthread -lboost_thread -L$(BOOST_THREAD_DIR)

TARGETS =  Message.o Server.o CommunicationServices.o Logger.o \
				threadpool.o WorkerThreadImpl.o MessageProcessorImpl.o
SERVER = server
LIBSERVER = libserver.a


MessageProcessorImpl.o: $(SRC_DIR)/MessageProcessorImpl.cpp Logger.o
	$(CXX) -c $(SRC_DIR)/MessageProcessorImpl.cpp $(CFLAGS)
	
WorkerThreadImpl.o: $(SRC_DIR)/WorkerThreadImpl.cpp
	$(CXX) -c $(SRC_DIR)/WorkerThreadImpl.cpp $(CFLAGS)

threadpool.o: $(SRC_DIR)/threadpool.cpp 
	$(CXX) -c $(SRC_DIR)/threadpool.cpp $(CFLAGS)

Logger.o: $(SRC_DIR)/Logger.cpp
	$(CXX) -c $^ $(CFLAGS)

CommunicationServices.o: $(SRC_DIR)/CommunicationServices.cpp	Logger.o threadpool.o
	$(CXX) -c $(SRC_DIR)/CommunicationServices.cpp $(CFLAGS)
	
Server.o: $(SRC_DIR)/Server.cpp Logger.o threadpool.o CommunicationServices.o
	$(CXX) -c $(SRC_DIR)/Server.cpp $(CFLAGS)
	
Message.o: $(SRC_DIR)/Message.cpp
	$(CXX) -c $^ $(CFLAGS)
	
Main.o: $(SRC_DIR)/Main.cpp
	$(CXX) -c $^ $(CFLAGS)
		
server: Main.o $(TARGETS)
	$(CXX) $^ $(LDFLAGS) -o $(SERVER)
	
lib: $(TARGETS) 
	ar -rv $(LIBSERVER) $(TARGETS)
	
clean:
	rm *.o $(SERVER) $(LIBSERVER)
	
clean-obj:
	rm *.o
	
all: server lib clean-obj
