/**********************************************************************

   File          : ThreadPoolWork.h

   Description   : Defines a work for the ThreadPoolManager

   Last Modified : 
   By            : Wilmarc Lopez

***********************************************************************/

#ifndef TPWORK_H
#define TPWORK_H

class ThreadPoolWork{
	public:
		virtual void operator()() = 0;
};

#endif
