CXX = g++
SRC_DIR = ./src
INC_DIR = ./include

CommunicationServices.o: $(SRC_DIR)/CommunicationServices.cpp
	$(CXX) -c @^
	
