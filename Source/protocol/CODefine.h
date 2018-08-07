#ifndef _INC_CODEFINE_H
#define _INC_CODEFINE_H

#include "COTypes.h"
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <stdarg.h>

#ifndef WIN32
#define strnicmp strncasecmp
#define stricmp strcasecmp
#endif



//***************** enable print to file ****************
//#define ENABLE_FILE_PRINT		make option: FILE_PRINT=YES
//#define ENABLE_SCREEN_PRINT		make option: SCREEN_PRINT=YES

#define MAX_BUFFER_LEN_FOR_PRINT      (2048L)
#ifdef WIN32
	#define snprintf  _snprintf
	#define vsnprintf _vsnprintf
#endif

void app_printf( const char *fmt, ... );
void app_fprintf( FILE* fd, const char *fmt, ... );
void app_fclose( FILE* fd );

//***************** begin information about registry. *************************
//
#define	CURRENT_FOLDER_AS_MAIN
#define  PROTOK_5N83
#ifndef LOGVIEWER
	#if !defined(KABINA_K9) & !defined(PROTOK_5N83) & !defined(PROTOK_5N63)
		#error FLAG not defined
	#endif
#endif

#if !defined(TRACKING_BY_PRIORITY_SOURCE) & !defined(TRACKING_BY_AVERAGE_VALUE)
#define TRACKING_BY_PRIORITY_SOURCE
#endif


const int SRC_COUNT = 10;//4 base + 6 subbordinate


//Quantity time-out period while client don't answer(203).
const int QTT_NOTANSWER_FROM_CLIENT = 3;

//#define MAX_LOAD_AIR

#ifdef MAX_LOAD_AIR
	#define MAX_AIR_OBJECTS 265
	#define MAX_GEN_TRACK_COUNT 255
	#define MAX_GEN_TRACK_NUMBER 254
	#define MAX_JAMMER_NUMBER 264	
#else
	#define MAX_AIR_OBJECTS 255
	#define MAX_GEN_TRACK_COUNT 200
	#define MAX_GEN_TRACK_NUMBER 240
	#define MAX_JAMMER_NUMBER 250
#endif

	#define MAX_SUB_AIR_OBJECTS 10
	#define MAX_SUB_GEN_TRACK_COUNT 6
	#define MAX_SUB_GEN_TRACK_NUMBER 5
	#define MAX_SUB_JAMMER_NUMBER 9

	// максимально допустимое удаление на пеленге при расчёте триангуляционной точки
	#define MAX_DISTANCE_FOR_TRIANGULATION 500000

//#define	COUNT_LOG_FILE	7
enum
{	
	MPD_IN=1,
	MPD_OUT=2,
	WST_IN=3,
	WST_OUT=4,
	//BACKUP_IN=5,
	//BACKUP_OUT=6,
	DIAGNOSTIC=5,
	LOGFILE_ID_AB_IN = 6,
	LOGFILE_ID_AB_OUT = 7
};

/*
#define	COUNT_LOG_FCS	4
enum{ FCS_IN=1, FCS_OUT=2, ERR_FCS=3, DIAGN_MAIN = 4 };
*/
//
//**************** end information about registry. ****************************


//*********************** inclusion of assertion information ******************
#define	ASSERT_ON

#include <assert.h>

#ifdef	ASSERT_ON
	#define	G_ASSERT(sign)	assert(sign)
#else
	#define	G_ASSERT(sign)	if(sign == 0)	throw -1
#endif

#ifdef	ASSERT_ON
	#define	LOCAL_ASSERT(sign)	assert(sign)
#else
//	#define	NDEBUG
	#define	LOCAL_ASSERT(sign)	assert(true)
#endif

/*		sample

		void func()
		{
			try
			{
				...
			}
			catch(...)
			{
				G_ASSERT(0);
			}
		}
*/

#pragma pack (push, 1)

//ID абонента
union GFabonentID{
	GFabonentID( void ) : m_full_number( 0 )
	{
		//
	}
	GFabonentID( int num, int sub_num )
	{
		m_num_arr[0] = num;
		m_num_arr[1] = sub_num;
	}
	bool operator ==( const GFabonentID& rAbID ) const{
		return ( m_full_number == rAbID.m_full_number );
	}
	bool operator ==( int rAbID ) const{
		return ( m_full_number == rAbID );
	}
	bool operator !=( const GFabonentID& rAbID ) const{
		return !(*this == rAbID);
	}
	bool operator !( void ) const{
		return ( !m_full_number );
	}
	bool operator <( const GFabonentID& rID ) const{
		return ( m_full_number < rID.m_full_number );
	}
	bool operator >( const GFabonentID& rID ) const{
		return ( m_full_number > rID.m_full_number );
	}
	//0 - num
	//1 - sub num
	COInt8 m_num_arr[2];

	COUInt16 m_full_number;
};

#define GF_AB_ID_num( x ) ( x ).m_num_arr[0]
#define GF_AB_ID_sub_num( x ) ( x ).m_num_arr[1]

#pragma pack (pop)

//#define HI_BYTE( x ) ( ( (x) & 0xF0 ) >> 4 )
#define LO_BYTE( x ) (x) & 0xF

#define REVERCE_INT16( x ) \
	( ( (x) >> 8 ) & 0xFF ) | ( ( (x) << 8 ) & 0xFF00 )

#define REVERCE_INT32( x ) \
	( ((x)>>24) & 0xFF) | ( ((x)>>8) & 0xFF00 ) | ( ((x)<<8) & 0xFF0000 )	| ( ((x)<<24) & 0xFF000000 )

#ifdef WIN32
	#define conv_atoi64 _atoi64
	#define conv_itoa64( value, str ) _i64toa( value, str, 10 )
#else
	#define conv_atoi64   atoll
	#define conv_itoa64( value, str ) sprintf( str, "%lld", value )
#endif

enum TYPE_COORD
{
	TOPOCENTRIC_COORD 	= 0,	// прямоугольные относительно репера
	GEODESIC_COORD		= 1,	// географические (широта, долгота)
	GAUSS_KRUGER_COORD	= 2,	// координаты в системе Гаусса-Крюгера 
	GEOCENTRIC_COORD	= 3,	// геоцентрические относительно центра земли
	POLAR_COORD		= 4	// полярная система координат
};


// **************** project parameters **************** //
const int GFnumOurCP = 0x80;
const int COMMnumSFK = 0x70;
const int TERMINAL = 0x50;
const int GATEWAY = 0x60;

#define g_PUT_num 0x5E

#define TERMINAL_BROADCAST 0x5F

#define MAX_TERMINAL_QNT 14
#define MAX_GATEWAY_QNT 4

#endif //_INC_CODEFINE_H
