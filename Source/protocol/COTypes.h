/*! \file COTypes.h
\brief Contains definition of fixed-size types.
*/

#ifndef _COTypes_h_
#define _COTypes_h_

#ifdef WIN32

typedef __int64          COInt64;
typedef unsigned __int64 COUInt64;
typedef long             COInt32;
typedef unsigned long    COUInt32;
typedef short            COInt16;
typedef unsigned short   COUInt16;
typedef signed char      COInt8;
typedef unsigned char    COUInt8;
typedef float		COFloat32;
typedef double		 COFloat64;

#else // assuming UNIX

typedef long long      COInt64;
typedef unsigned long long  COUInt64;
typedef int            COInt32;
typedef unsigned int   COUInt32;
typedef short          COInt16;
typedef unsigned short COUInt16;
typedef signed char    COInt8;
typedef unsigned char  COUInt8;
typedef float		COFloat32;
typedef double		COFloat64;

//N!#else //__alpha

//#error Unknown target platform

//N!#endif //__alpha

#endif //WIN32

struct  STakeoffAngle
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
};

#endif //_COTypes_h_
