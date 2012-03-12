#include "Logger.h"

#include <stdio.h>
#include <iostream>

using namespace std;

Logger* Logger::INSTANCE = NULL;


Logger* Logger::getInstance()
{
	if (!INSTANCE)
		INSTANCE = new Logger;
	
	return INSTANCE;
}

bool Logger::error(std::string msg)
{
	cout << "Error" << msg << "\n";
	return true;
}

bool Logger::warning(std::string msg)
{
	cout << "Warning" << msg << "\n";
	return true;
}

bool Logger::info(std::string msg)
{
	cout << "Info" << msg << "\n";
	return true;
}

bool Logger::error(char *msg)
{
	/* Print message and return */
    fprintf( stderr, "Error: %s\n", msg );
	return true;
}

bool Logger::warning(char *msg)
{
	/* Print message and return */
    fprintf( stderr, "Warning: %s\n", msg );
	return true;
}

bool Logger::info(char *msg)
{
	/* Print message and return */
    fprintf( stdout, "Info: %s\n", msg );
	return true;
}


void Logger::printBuffer( char *msg, char *buf, int len )
{
	/* Print message and return */
     int i;
     if ( msg != NULL ) printf( "%s : ", msg );
     if ( buf != NULL )
     {
          for ( i=0; i<len; i++ ) 
          {
               printf( "%2X ", (unsigned char)buf[i] );
          }
     }
     else
     {
          printf( "(null)" );
     }
     printf( "\n" );
     return;
}
