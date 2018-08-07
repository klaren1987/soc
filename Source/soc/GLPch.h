/*! \file GLPch.h
\brief This file contains the most common includes used in the library.
*/

#ifndef _GLPch_h_
#define _GLPch_h_

// Disable C4786 warning in Microsoft Visual C++
// ('identifier' : identifier was truncated to
// 'number' characters in the debug information).
#ifdef _MSC_VER
#pragma warning (disable : 4786)
#endif //_MSC_VER

#include "COcxx.h"
#include <time.h>
#include <malloc.h>
#include <errno.h>

template<class T> class GLallocator
{
public:
	typedef T* pT;
	GLallocator( void )
	{
		//
	}
	void operator ( )( pT& l_pntr )
	{
		l_pntr = new T();
		if( !l_pntr )
		{
			throw;
		}
	}
	pT operator ( )( const T& l_T, pT& l_pntr )
	{
		l_pntr = new T();
		if( !l_pntr )
		{
			throw;
			return NULL;
		}
		*l_pntr = l_T;
		return l_pntr;
	}
protected:
private:
};

template<class T> class GLdelete
{
public:
	typedef T* pT;
	GLdelete( void )
	{
		//
	}
	void operator ( )( pT& l_pntr )
	{
		if( l_pntr )
			delete l_pntr;
		l_pntr = 0;
	}
protected:
private:
};

template<class T> class GLdel_release
{
public:
	typedef T* pT;
	GLdel_release( void )
	{
		//
	}
	void operator ()( pT& l_pntr )
	{
		if( l_pntr )
			l_pntr->release();
		l_pntr = 0;
	}
protected:
private:
};

#define GLmin(a, b)  (((a) < (b)) ? (a) : (b)) 
#define GLmax(a, b)  (((a) > (b)) ? (a) : (b)) 

#endif //_GLPch_h_
