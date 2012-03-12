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

#ifndef CPPTPOOL_H
#define CPPTPOOL_H

#include <pthread.h>
#include <semaphore.h>
#include <iostream>
#include <vector>

using namespace std;
/*
WorkerThread class
This class needs to be sobclassed by the user.
*/
class WorkerThread{
public:
    int id;

    unsigned virtual executeThis()
	{
		return 0;
	}

    WorkerThread(int id) : id(id) {}
    virtual ~WorkerThread(){}
};

/*
ThreadPool class manages all the ThreadPool related activities. This includes keeping track of idle threads and ynchronizations between all threads.
*/
class ThreadPool{
public:
    ThreadPool();
    ThreadPool(int maxThreadsTemp);
    virtual ~ThreadPool();
	
	void destroyPool(int maxPollSecs);

    bool assignWork(WorkerThread *worker);
    bool fetchWork(WorkerThread **worker);

	void initializeThreads();
	
    static void *threadExecute(void *param);
    
    static pthread_mutex_t mutexSync;
    static pthread_mutex_t mutexWorkCompletion;
    
    
private:
    int maxThreads;
    
    pthread_cond_t  condCrit;
    sem_t availableWork;
    sem_t availableThreads;

    //WorkerThread ** workerQueue;
    vector<WorkerThread *> workerQueue;

    int topIndex;
    int bottomIndex;
	
	int incompleteWork;

    
    int queueSize;

};

#endif




