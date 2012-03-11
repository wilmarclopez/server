/**********************************************************************

   File          : ThreadPoolManager.h

   Description   : Implementation of thread pool pattern. A Singleton.

   Last Modified : 
   By            : Wilmarc Lopez

***********************************************************************/

#ifndef TPOOL_H
#define TPOOL_H

#include "ThreadPoolWork.h"

class ThreadPoolManager {
	public:
	   static ThreadPoolManager* getInstance();  
	   void submit(ThreadPoolWork *work);	//automatically deallocates work when finished
	
	private:
	   ThreadPoolManager();  // Private so that it can  not be called
	   ThreadPoolManager(ThreadPoolManager const&){};             // copy constructor is private
	   ThreadPoolManager& operator=(ThreadPoolManager const&){};  // assignment operator is private
	   
	   static ThreadPoolManager* INSTANCE;
};

#endif
