/*
    Thread Pool implementation for unix / linux environments
    Copyright (C) 2008 Shobhit Gupta

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include "threadpool.h"

using namespace std;


#define ITERATIONS 200

class SampleWorkerThread : public WorkerThread
{
public:
        int id;

	unsigned virtual executeThis()
	{
	// Instead of sleep() we could do anytime consuming work here.
	//Using ThreadPools is advantageous only when the work to be done is really time consuming. (atleast 1 or 2 seconds)
		sleep(2);

		return(0);
	}


        SampleWorkerThread(int id) : WorkerThread(id), id(id)
        {
//           cout << "Creating SampleWorkerThread " << id << "\t address=" << this << endl;
        }

        ~SampleWorkerThread()
        {
//           cout << "Deleting SampleWorkerThread " << id << "\t address=" << this << endl;
        }
};


int main(int argc, char **argv)
{
	//ThreadPool(N);
	//Create a Threadpool with N number of threads
	ThreadPool* myPool = new ThreadPool(25);
	myPool->initializeThreads();

	//We will count time elapsed after initializeThreads()
    time_t t1=time(NULL);

	//Lets start bullying ThreadPool with tonnes of work !!!
	for(unsigned int i=0;i<ITERATIONS;i++){
		SampleWorkerThread* myThread = new SampleWorkerThread(i);
//cout << "myThread[" << myThread->id << "] = [" << myThread << "]" << endl;
		myPool->assignWork(myThread);
	}
	
	// destroyPool(int maxPollSecs)
	// Before actually destroying the ThreadPool, this function checks if all the pending work is completed.
	// If the work is still not done, then it will check again after maxPollSecs
	// The default value for maxPollSecs is 2 seconds.
	// And ofcourse the user is supposed to adjust it for his needs.
	
    myPool->destroyPool(2);

    time_t t2=time(NULL);
    cout << t2-t1 << " seconds elapsed\n" << endl;
	delete myPool;
	
    return 0;
}
