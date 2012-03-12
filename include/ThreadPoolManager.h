/**********************************************************************

   File          : ThreadPoolManager.h

   Description   : Implementation of thread pool pattern.

   Last Modified : 
   By            : Wilmarc Lopez

***********************************************************************/

#ifndef TPOOL_H
#define TPOOL_H

#include "ThreadPoolWork.h"
#include <boost/threadpool.hpp>

class ThreadPoolManager {
	public:
		ThreadPoolManager();
		ThreadPoolManager(int poolSize) : tp(poolSize) {}
		virtual ~ThreadPoolManager();  		

		void submit(ThreadPoolWork *work);	//automatically deallocates work when finished	   
	   
   protected:
		boost::threadpool::pool tp; 
};

#endif
