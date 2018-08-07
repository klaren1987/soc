/*! \file COcxx.h
\brief This file must be included in all files which use
the following:
- bool, true, false;
- static_cast, reinterpret_cast, dynamic_cast, const_cast
*/

#ifndef _COcxx_h_
#define _COcxx_h_

#define CPM_DEBUG_INFO

#include <stdlib.h>

/*struct  STakeoffAngle
{
  STakeoffAngle(){ distance=0;angle=0; }
  int   distance;
  float angle;
};

struct  SOneDirection
{
  SOneDirection(){ azimuth=0;count=0;data=0; };
  ~SOneDirection(){ if(data!=0){ delete [] data; } }
  float azimuth;
  int   count;
  STakeoffAngle*  data;
};

struct  SOneSource
{
  SOneSource(){ number=0;hightCenter=0; }
  int   number;
  int   hightCenter;
  SOneDirection data[360];
};

struct  STableCoefficient
{
  STableCoefficient()
  { hpoint1=0; hpoint2=0; sppoint1=0; sppoint2=0; bcpoint=0; }

	int    hpoint1;
	int    hpoint2;
	short  sppoint1;		
	short  sppoint2;		
	double bcpoint;		
};

struct  SOneTypeMissile
{
  SOneTypeMissile(){ type=0; count=0; data=0; }
  ~SOneTypeMissile(){ if(data!=0){ delete [] data; } }
  int   type;
  int   count;
  STableCoefficient*  data;
};

struct  SPlaceObject
{
  SPlaceObject(){ x=0; y=0; h=0; }
  int x;
  int y;
  int h;
};

struct  SOneObject
{
  SOneObject()
  {
    codeID=0; importance=0; count=0; data=0;
    quantityM1=0; quantityM2=0; quantityM3=0; quantityAD=0; quantityCM=0;
  }
  ~SOneObject(){ if(data!=0){ delete [] data; } }
  unsigned char codeID;
  float importance;
  int quantityM1;
  int quantityM2;


  int quantityM3;
  int quantityAD;
  int quantityCM;
  int count;
  SPlaceObject centerPoint;
  SPlaceObject* data;
};*/

#ifdef WIN32

#pragma warning(disable:4786)

#define FILENAME_LEN _MAX_FNAME
#define using_namespace_std using namespace std;

#define S_ADDR(x)		(x).S_un.S_addr          /* can be used for most tcp & ip code */
#define S_HOST(x)		(x).S_un.S_un_b.s_b2     /* host on imp */
#define S_NET(x)		(x).S_un.S_un_b.s_b1     /* network */
#define S_IMP(x)		(x).S_un.S_un_w.s_w2     /* imp */
#define S_IMPNO(x)	(x).S_un.S_un_b.s_b4     /* imp # */
#define S_LH(x)			(x).S_un.S_un_b.s_b3     /* logical host */

	#define l_l_abs	abs
	#define l_abs abs

#endif //WIN32

#ifdef _GNU_SOURCE //assuming UNIX

#include <stdio.h>
#include <cstdlib>

#define FILENAME_LEN NAME_MAX
#define using_namespace_std using namespace std;

#ifndef _GLIBCPP_USE_WCHAR_T
#define _GLIBCPP_USE_WCHAR_T
#endif

	#define l_l_abs	__gnu_cxx::llabs

/*
 * Internet address (old style... should be updated)
 */
struct in__addr
{
  union
  {
    struct { unsigned char s_b1,s_b2,s_b3,s_b4; } S_un_b;
    struct { unsigned short s_w1,s_w2; } S_un_w;
    unsigned long S_addr;
  } S_un;
//#define s_addr  S_un.S_addr          /* can be used for most tcp & ip code */
//#define s_host  S_un.S_un_b.s_b2     /* host on imp */
//#define s_net   S_un.S_un_b.s_b1     /* network */
//#define s_imp   S_un.S_un_w.s_w2     /* imp */
//#define s_impno S_un.S_un_b.s_b4     /* imp # */
//#define s_lh    S_un.S_un_b.s_b3     /* logical host */
};

#define S_ADDR(x)		(*((in__addr*)&(x))).S_un.S_addr          /* can be used for most tcp & ip code */
#define S_HOST(x)		(*((in__addr*)&(x))).S_un.S_un_b.s_b2     /* host on imp */
#define S_NET(x)		(*((in__addr*)&(x))).S_un.S_un_b.s_b1     /* network */
#define S_IMP(x)		(*((in__addr*)&(x))).S_un.S_un_w.s_w2     /* imp */
#define S_IMPNO(x)	(*((in__addr*)&(x))).S_un.S_un_b.s_b4     /* imp # */
#define S_LH(x)			(*((in__addr*)&(x))).S_un.S_un_b.s_b3     /* logical host */

#endif //_GNU_SOURCE


#include <wchar.h>
#include <string>
#include <string.h>
#include <limits.h>
//#include <unistd.h>


typedef std::basic_string<wchar_t, std::char_traits<wchar_t> > wstring;

#endif //_COcxx_h_
