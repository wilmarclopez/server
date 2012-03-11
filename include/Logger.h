/**********************************************************************

   File          : Logger.h

   Description   : Definition of the class for logging. A Singleton.

   Last Modified : 
   By            : Wilmarc Lopez

***********************************************************************/

#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger{
	public:
	   static Logger* getInstance();
	   
	   bool error(std::string msg);
	   bool warning(std::string msg);
	   bool info(std::string msg);
	   
	   bool error(char *msg);
	   bool warning(char *msg);
	   bool info(char *msg);
	   	   
	   /*
	   bool openLogFile(std::string logFile);
	   void writeToLogFile();
	   bool closeLogFile();
		*/
	
	private:
	   Logger();  // Private so that it can  not be called
	   Logger(Logger const&);             // copy constructor is private
	   Logger& operator=(Logger const&);  // assignment operator is private
	   
	   static Logger* INSTANCE;
};


#endif
