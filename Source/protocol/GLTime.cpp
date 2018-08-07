/*! \file GLTime.cpp
\brief Implementation of GLTime class.
*/

// _OS_INDEPENDENT_
#include "COcxx.h"
#include "CODefine.h"
#include "GLTime.h"
//#include "OSFunc.h"
#include <time.h>
#include <assert.h>
#include <stdio.h>

#ifdef WIN32
	#include <windows.h>
  #include <sys/types.h>
  #include <sys/timeb.h>
#endif

#ifdef _GNU_SOURCE
	#include <unistd.h>
	#include <sys/time.h>
	#include <time.h>
	#include <sys/timeb.h>
#endif

#define HOUR_MILLI			(COUInt32)(60 * 60 * 1000)				//count millisec. in one hour 
#define DAYS_MILLI			(COUInt32)(24 * HOUR_MILLI)				//count millisec. in one day 
#define MICRO25_IN_MILLI	(COUInt32)(1000 / 25)					//count microsec. in millisec.
#define DAYS_25MICRO		(COInt64)(DAYS_MILLI * MICRO25_IN_MILLI)//count microsec. in day
#define HALF_DAYS_25M		(COInt64)(DAYS_25MICRO / 2)				//count microsec. in half day

/*********************************************************************

                   GLTime implementation

**********************************************************************/

COInt64 GLTime::s_processStartup = 0;

GLTime::GLTime( void )
{
  if (!s_processStartup)
  {
    init();
  }
  setLocal();
}

GLTime::GLTime( const COInt64& t ) : m_time(t)
{
  if (!s_processStartup)
  {
    init();
  }
}

COUInt32 GLTime::forFullHour(COInt64 time)
{
	try
	{
		COUInt64 tmp = time % HOUR_MILLI;
		LOCAL_ASSERT(HOUR_MILLI >= tmp);
		COUInt32 ret = (COUInt32)(HOUR_MILLI - tmp);
		return	ret;
	}
	catch(...)
	{
		G_ASSERT(0);
		return	0;
	}
}

const GLTime& GLTime::operator =( const COInt64& t )
{
  m_time = t;
  return *this;
}
int GLTime::timeToString(char* buffer, int maxSize, COInt64 time)
{
	try
	{
		char	tempBuf[100];
		time_t	tempTime = (time_t)(time / 1000);
		struct tm*	pTm = localtime(&tempTime);

		int ret = sprintf(tempBuf, "%4d-%2d-%2d_%2d-%2d-%2d",
			pTm->tm_year+1900,
			pTm->tm_mon+1,
			pTm->tm_mday,
			pTm->tm_hour, pTm->tm_min, pTm->tm_sec);

		if( ret >= maxSize )
		{
			return	0;
		}
		unsigned int i;
		for(i=0; i< ::strlen(tempBuf);i++)
		{
			if( tempBuf[i] == ' ' )
			{
				tempBuf[i] = '0';
			}
		}
		strcpy(buffer, tempBuf);
		return	ret;
	}
	catch(...)
	{
		assert(0);
		return	0;
	}
}

COUInt32 GLTime::milli_to_25micro( COInt64 time )
{	
	try
	{
//		COUInt64 utc = time % DAYS_MILLI;
//		utc *= MICRO25_IN_MILLI;
//		return	(COUInt32)utc;
		COInt64 milisec = time % 1000;
		COInt64 l_t1 = time / 1000;
		time_t l_t = (time_t)l_t1;
		struct tm ttt;
		ttt = *localtime( &l_t );
		COInt64 utc = (COInt64)ttt.tm_hour * 3600 + (COInt64)ttt.tm_min * 60 + (COInt64)ttt.tm_sec;
		//COInt64 rez = double( utc )/0.000025 + double(milisec)/0.025;
		COInt64 rez = (utc * 1000000 / 25) + (milisec * 1000 / 25);
		return (COUInt32)rez;
	}
	catch(...)
	{
		assert(0);
		return	0;
	}
}

#ifdef WIN32
void GLTime::setLocal( void )
{
	_timeb st;
	_ftime(&st);

	m_time = st.time;
	m_time *= 1000;
	m_time += st.millitm;
}

void GLTime::init( void )
{
  _timeb  st;
  _ftime(&st);
  unsigned long	beg = OSticksToMs(clock());

  s_processStartup = st.time;
  s_processStartup *= 1000;
  s_processStartup += st.millitm;
  s_processStartup -= beg;	
}
#endif // WIN32

#ifdef _GNU_SOURCE
void GLTime::setLocal( void )
{
	struct timeval tp;

	//clock_gettime(CLOCK_REALTIME,&tp);
	gettimeofday(&tp, NULL);

	m_time = tp.tv_sec;
	m_time *= 1000;
	m_time += (tp.tv_usec / 1000);

/*	struct timeb  st;
	//COInt32	tmpZone;
	COInt64 tmpTime;
	ftime(&st);
	m_time = st.time;
	m_time *= 1000;
	m_time += st.millitm;
*/
}
unsigned long OSticksToMs( clock_t ticks )
{
	try
	{
#if (1000 == CLOCKS_PER_SEC)
		return ticks;
#else
		double t = ticks;
		t /= CLOCKS_PER_SEC;
		t *= 1000;
		return (unsigned long)(t);
#endif
	}
	catch(...)
	{
		G_ASSERT(0);
		return	0;
	}
}
void GLTime::init( void )
{
	struct timeval tp;

	//clock_gettime(CLOCK_REALTIME,&tp);
	gettimeofday(&tp, NULL);
	
	s_processStartup = tp.tv_sec;
	s_processStartup *= 1000;
	s_processStartup += (tp.tv_usec / 1000);


/*	struct timeb  st;
	//COInt32	tmpZone;
	COInt64 tmpTime;
	ftime(&st);
	s_processStartup = st.time;
	s_processStartup *= 1000;
	s_processStartup += st.millitm;
*/
	unsigned long	beg = OSticksToMs(clock());
	s_processStartup -= beg;
}
#endif //_GNU_SOURCE

//
