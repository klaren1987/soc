/*! \file GLTime.h
\brief Header file for GLTime class.
*/

// _OS_INDEPENDENT_

#ifndef _GLTime_h_
#define _GLTime_h_
#include "COcxx.h"

#include "COTypes.h"
#include <time.h>

/*! \class GLTime GLTime.h
\brief Represents time in milliseconds since midnight, Jan, 1, 1970.
*/
class GLTime
{

public:

  /*! \fn GLTime( void );
  \brief Class constructor.
  */
  GLTime( void );

  /*! \fn GLTime( const COInt64& t );
  \brief Copy initializer.
  */
  GLTime( const COInt64& t );

  /*! \fn const GLTime& operator =( const COInt64& t );
  \brief Assignment operator.
  */
  const GLTime& operator =( const COInt64& t );

  /*! \fn operator COInt64( void ) const;
  \brief Typecast to 64-bit integer.
  */
  operator COInt64( void ) const;

  /*! \fn void setLocal( void );
  \brief Sets object to local time.
  */
  void setLocal( void );

	static int timeToString(char* buffer,		//Buffer pointer for string.
							int maxSize,		//Buffer size.
							COInt64 time		//Time to convert.
	);

	static COUInt32 milli_to_25micro(COInt64 time);

	static COUInt32 forFullHour(COInt64 time);

private:

  /*! \var COInt64 m_time;
  \brief 64-bit integer containing number of milliseconds
  elapsed since 00:00:00 1.01.1970 (happy birthday to UNIX :)
  */
  COInt64 m_time;

  /*! \var static COInt64 m_processStartup;
  \brief Process startup time.
  */
  static COInt64 s_processStartup;

  /*! \fn static void init( void );
  \brief Performs class initialization.

  Sets m_processStartup into inital value.
  */
  static void init( void );
};

inline
GLTime::operator COInt64( void ) const
{
  return m_time;
}

#endif //_GLTime_h_
