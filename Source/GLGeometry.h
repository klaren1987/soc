// _OS_INDEPENDENT_

#ifndef _GLGeometry_h_
#define _GLGeometry_h_

#include "COcxx.h"
#include <list>
#include <algorithm>

using namespace std;

#undef _OSF_SOURCE
#include <math.h>

/*! \struct GLPoint2D GLGeometry.h
\brief Represents points in 2-dimentional space.
*/
class GLSector;
struct GLPoint3D;

struct GLPoint2D
{
/*! \fn GLPoint2D( int x0 = 0, int y0 = 0);
\brief Structure constructor.

\param x0 Initial X coordinate.
\param y0 Initial Y coordinate.
*/
	GLPoint2D( int x0 = 0, int y0 = 0);

/*! \fn GLPoint2D( GLPoint3D p);
\brief Structure constructor.
\param p Initial X,Y coordinate.
*/
	GLPoint2D( GLPoint3D p );

/*! \var int x;
\brief X coordinate.
*/
	int x;

/*! \var int y;
\brief Y coordinate.
*/
	int y;

	inline
	GLPoint2D& operator =( const GLPoint3D& other );

/*! \fn GLPoint2D(const GLPoint2D& copy);
\brief Structure copy constructor.
\param p Initial X,Y coordinate.
*/	
	GLPoint2D( const GLPoint2D& copy );

	inline
	bool operator ==( const GLPoint2D& other );
	inline
	bool operator !=( const GLPoint2D& other );

	inline
	GLPoint2D operator +=( const GLPoint2D& b )
	{
		x += b.x; y += b.y;
		return *this;
	}

	inline
	GLPoint2D operator /( int b )
	{
		if( !b )
			return *this;

		x /= b;
		y /= b;
		return *this;
	}
	
//	friend GLPoint2D operator-(const GLPoint2D& a, const GLPoint2D& b);
//	friend GLPoint2D operator+(const GLPoint2D& a, const GLPoint2D& b);
};

inline
bool GLPoint2D::operator ==( const GLPoint2D& other ){
	if(x == other.x && y == other.y)
		return 1;
	return 0;
}

inline
bool GLPoint2D::operator !=( const GLPoint2D& other ){
	return !( *this == other );
}

inline
GLPoint2D operator -( const GLPoint2D& a, const GLPoint2D& b )
{
	return GLPoint2D(a.x - b.x, a.y - b.y);
}

inline
GLPoint2D operator +( const GLPoint2D& a, const GLPoint2D& b )
{
	return GLPoint2D(a.x + b.x, a.y + b.y);
} 


/*! \fn unsigned int GLdistance( const GLPoint2D& p1, const GLPoint2D& p2 );
\brief Calculates distance between two points.

\param p1 A reference to the first point.
\param p2 A reference to the second point.
\return Distance between p1 and p2.
*/
unsigned int GLdistance( const GLPoint2D& p1, const GLPoint2D& p2 );

GLPoint2D GLPtFall(GLPoint2D& pt0,GLPoint2D& pt2,GLPoint2D& pt3);

//к двоично-десятичному (параметр x<=99999999)
int toBCD32(int x);

//из двоично-десятичного(параметр x<=0x99999999) в десятичное
int fromBCD32(int x);

//PACKAGE		:  GL
//STRUCT			:  GLPointDouble2D
//DESCRIPTION	:  Represents points in 2-dimentional space.
struct GLPointDouble2D
{
public:
//PACKAGE		:  GL
//FUNCTION			: GLPointDouble2D::GLPointDouble2D(void);
//DESCRIPTION	: Structure constructor.
//INPUTS		: NONE
//RETURNS		: NONE
	GLPointDouble2D(void);

//PACKAGE		:  GL
//FUNCTION			: GLPointDouble2D::GLPointDouble2D( const double& X, const double& Y );
//DESCRIPTION	: Structure constructor.
//INPUTS		: X - Initial X coordinate, Y - Initial Y coordinate.
//RETURNS		: NONE
	GLPointDouble2D( const double& X,	//Initial X coordinate
		const double& Y	//Initial Y coordinate.
		);

//PACKAGE		:  GL
//FUNCTION			: void GLPointDouble2D::init( const double& X,const double& Y);
//DESCRIPTION	: Structure constructor.
//INPUTS		: X - New X coordinate, Y - New Y coordinate.
//RETURNS		: NONE
	void init( const double& X,	//New X coordinate.
		const double& Y	//New Y coordinate.
		);

	GLPointDouble2D operator+(GLPointDouble2D Q);
	
	GLPointDouble2D operator=(const GLPointDouble2D& Q);

	bool operator==(GLPointDouble2D& Q);

	double x;
	//X coordinate.
	
	double y;
	//Y coordinate.
};
double GLdistance( const GLPointDouble2D& p1, const GLPointDouble2D& p2 );
/*! \struct GLPoint3D GLGeometry.h
\brief Represents points in 3-dimentional space.

 Important!!!: If this class contain coordinates in Gaussian frame
 of reference then operators "+","-" not available.
*/
struct GLPoint3D
{
/*! \fn GLPoint3D( int x = 0, int y = 0, int h = 0 );
\brief Structure constructor.
\param x0 Initial X coordinate.
\param y0 Initial Y coordinate.
\param h0 Initial height.
*/
	GLPoint3D( int x0 = 0, int y0 = 0, int h0 = 0 );

/*! \fn GLPoint3D( GLPoint2D p );
\brief Structure constructor.
\param p Initial X,Y coordinate (h = 0).
*/
	GLPoint3D( GLPoint2D p );

/*! \var int x;
\brief X coordinate.
*/
	int x;

/*! \var int y;
\brief Y coordinate.
*/
	int y;

/*! \var int h;
\brief Height.
*/
	int h;

	virtual bool operator ==( const GLPoint3D& other );
	virtual bool operator !=( const GLPoint3D& other );

	inline
	GLPoint3D operator +=( const GLPoint3D& b )
	{
		x += b.x; y += b.y; h += b.h;
		return *this;
	}

	inline
	GLPoint3D operator /( int b )
	{
		if( !b )
			return *this;

		x /= b;
		y /= b;
		h /= b;
		return *this;
	}
};

inline
GLPoint2D& GLPoint2D::operator =( const GLPoint3D& other )
{
	x = other.x;
	y = other.y;
	return *this;
}

inline
GLPoint3D operator -( const GLPoint3D& a, const GLPoint3D& b )
{
	return GLPoint3D( a.x - b.x, a.y - b.y, a.h - b.h );
}

inline
GLPoint3D operator +( const GLPoint3D& a, const GLPoint3D& b )
{
	return GLPoint3D( a.x + b.x, a.y + b.y, a.h + b.h );
}

struct GLAccel3D
{

	GLAccel3D ( int x = 0,	//Initial X acceleration
				int y = 0,	//Initial Y acceleration
				int z = 0	//Initial Z acceleration
				) : sAx((float)x), sAy((float)y), sAz((float)z)
	{
		
	};
	
	float sAx;

	float sAy;

	float sAz;
	
	//GLAccel3D operator=(GLPoint3D Q);

	bool operator >( const GLAccel3D& accel ) const
	{
		return sqrt(sAx*sAx + sAy*sAy + sAz*sAz) >
			sqrt(accel.sAx*accel.sAx + accel.sAy*accel.sAy + accel.sAz*accel.sAz);
	}

	operator int() const
	{
		return (int)(sqrt(sAx*sAx + sAy*sAy + sAz*sAz));
	}

	bool operator !=( GLAccel3D& accel ) const
	{
		return sqrt(sAx*sAx + sAy*sAy + sAz*sAz) !=
			sqrt(accel.sAx*accel.sAx + accel.sAy*accel.sAy + accel.sAz*accel.sAz);

	}

	int HasModule(void) const
	{
		return (int)sqrt(sAx*sAx + sAy*sAy + sAz*sAz);
	}
};

/*! \struct GLFixedPoint GLGeometry.h
\brief Represents points in 3-dimentional space
\ и признак меридиана для реперной точки.
*/
struct GLFixedPoint:public GLPoint3D
{
//  int x, int y, int h;
	GLFixedPoint( GLPoint3D& p , int sm = 0 );

//  int x, int y, int h;
	GLFixedPoint( void );
 
// признак полушария;
	int sm;

	virtual bool operator==( const GLFixedPoint& other ) const;

};  

/*! \fn unsigned int GLdistance( const GLPoint3D& p1, const GLPoint3D& p2 );
\brief Calculates distance between two points.
\param p1 A reference to the first point.
\param p2 A reference to the second point.
\return Distance between p1 and p2.
*/
unsigned int GLdistance( const GLPoint3D& p1, const GLPoint3D& p2 );

unsigned int GLdistance( const GLPoint3D& p );

/*! \fn unsigned int GLdistanceProjection( const GLPoint3D& p );
\brief Calculates distance between point projection on XY and origin point.
\param p A reference to the point.
\return Distance distance between point p projection on XY and point (0,0,0).
*/
unsigned int GLdistanceProjection( const GLPoint3D& p );

unsigned int GLdistanceFlat( const GLPoint3D& p1, const GLPoint3D& p2 );

/*! \struct GLPointLL GLGeometry.h
\brief Represents points in "latitude-longitude-height" coordinates.
*/
struct GLPointLL

{
  /*! \fn GLPointLLH( double lt0 = 0.0, double lg0 = 0.0, int h0 = 0 );
  \brief Class constructor.
  \param lt0 Initial latitude (in radians).
  \param lg0 Initial longitude (in radians).
  \param h0 Initial height.
  */
  GLPointLL( double lt0 = 0.0, double lg0 = 0.0, int h0 = 0 )
  {lt = lt0; lg = lg0; h = h0;}
  /*! \var double lt;
  \brief Latitude.
  */
  double lt;

  /*! \var double lg;
  \brief Longitude.
  */
  double lg;

  /*! \var int h;
  \brief Height.
  */
  int h;
};




/*! \struct GLVelocity3D GLGeometry.h
\brief Represents velocities in 3-dimentional space.
*/

struct GLVelocity3D
{
  /*! \fn GLVelocity3D( int vx0 = 0, int vy0 = 0, int vh0 = 0 );
  \brief Structure constructor.
  */
  GLVelocity3D( int vx0 = 0, int vy0 = 0, int vh0 = 0 );

  /*! \var int vx;
  \brief X component.
  */
  int vx;

  /*! \var int vy;
  \brief Y component.
  */
  int vy;

  /*! \var int vh;
  \brief Height component.
  */
  int vh;
};

/*! \fn unsigned int GLabs( const GLVelocity3D& v );
\brief Calculated absolute value of velocity.
\param v A reference to velocity.
\return Absolute value of the velocity.
*/
unsigned int GLabs( const GLVelocity3D& v );

unsigned int GLabsFlat( const GLVelocity3D& v );


/*! \struct GLBearing GLGeometry.h
\brief Represents direction in 3-dimentional space.
*/
struct GLBearing
{
  /*! \fn GLBearing( double b = 0, double e = 0 )
  \brief Structure constructor.
  \param b0 Initial azimuth coordinate (beta).
  \param e0 Initial elevation coordinate (epsilon).
  */
  GLBearing( double b0 = 0, double e0 = 0 );

  /*! \fn GLBearing(GLPoint3D p)
  \brief Structure constructor.
  \param p Bearing point.
  */
	GLBearing(GLPoint3D p);

  /*! \fn GLBearing(GLPoint3D p)
  \brief Structure constructor.
  \param p Bearing point.
  */
	GLBearing(GLPoint2D p);

  /*! \var double b
  \brief Azimuth coordinate (beta).
  */
  double b;

  /*! \var double e;
  \brief Elevation coordinate (epsilon).
  */
  double e;
public:

};

/*! \struct GLBearingVelocity GLGeometry.h
\brief Represents velocities in 3-dimentional space.
*/

struct GLBearingVelocity
{
  /*! \fn GLBearingVelocity( double vb0 = 0, double ve0 = 0 );
  \brief Structure constructor.
  */
  GLBearingVelocity( double vb0 = 0, double ve0 = 0 );

  GLBearingVelocity(GLVelocity3D p);


  /*! \var double vb;
  \brief Azimuth component (beta velocity).
  */
  double vb;

  /*! \var double ve;
  \brief Elevation component (epsilon velocity).
  */
  double ve;
};

double GLazimuthChange(double newA, double prevA);

double GLmeetAngle(double a1, double a2);

bool GLazimuthSector(const list<GLPoint3D>& rList, GLSector& sect);

/*!\fn double GLangleElevtn(const GLPoint3D& point);
\brief Calculates angle of elevation subject to earth radius.
\param point Reference to point where find desired place.
\return angle of elevation.
*/
inline
double GLangleElevtn(const GLPoint3D& point)
{
  double D = sqrt((double)(point.x * point.x + point.y * point.y +	point.h * point.h));
	double Z = point.h - ( D * D )/( 2 * 8500000 );
	return atan2( Z , D );
}

/*!\fn double GLangleElevtn(const GLPoint3D& point);
\brief Calculates angle of elevation subject to earth radius.
\param point1 Reference to point relative it calculate.
\param point2 Reference to point where find desired place.
\return angle of elevation.
*/
inline
double GLangleElevtn(const GLPoint3D& point1,const GLPoint3D& point2)
{
	if( point1.x && point2.x)
	{}
  return 0;
}

//extern const double PI;

//And remember then m_cnt_pnt is only integer and result not precise.
//Use it with simple array, vector, deque, not with map, list, set and
//other associative container.
template<class T> class GLAveragePoint
{
public:
	GLAveragePoint( void ) : m_cnt_pnt(0)
	{
		m_averPnt = T();
	}
	void operator ( )( const T& l_averPnt )
	{
		m_cnt_pnt++;
		m_averPnt += l_averPnt;
	}
	operator T( )
	{
		return m_averPnt / m_cnt_pnt;
	}
protected:
private:
	T m_averPnt;
	int m_cnt_pnt;
};

//Calculate main point from array.
template<class T>
inline
void GLcalculate_main_point(
	T* pVec,	//pointer to the 1st element of array
	int l_sz,	//size of array
	T& rXD	//result of operation
	)
{
	rXD = for_each( pVec,
		pVec + l_sz,
		GLAveragePoint<T>()
		);
}

template<class T> class GLmax_distance
{
public:
	GLmax_distance( T l_SP ) : m_SP( l_SP ), m_max_distance( 0 )
	{
		//
	}
	void operator ( )( const T& l_cmp_pnt )
	{
		unsigned int l_distance(0);
		l_distance = GLdistance( m_SP, l_cmp_pnt );
		if( m_max_distance < l_distance ){
			m_max_distance = l_distance;
		}
	}
	operator unsigned int ( )
	{
		return m_max_distance;
	}
protected:
private:
	T m_SP;
	unsigned int m_max_distance;
};

//Calculate Max distance from some point to the farthest point from array.
template<class T>
inline
unsigned int GLcalculate_max_distance(
	T* pVec,	//pointer to the 1st element of array
	int l_sz,	//size of array
	T l_SP	//some point
	)
{
	GLmax_distance<T> l_max_distance( l_SP );
	return for_each( pVec,
		pVec + l_sz,
		l_max_distance
		);
}

//FUNCTION		: GLcroosLineCircuit(GLVelocity3D&  direct, GLPoint3D &firstPnt, GLPoint3D &secondPnt, COUInt32 radius)
//DESCRIPTION	: Calculates points of intersection of line and circuit
//INPUTS		: Direct of moving, firs and second points of line(relatively center of circuit), circuit radius 
//RETURNS		: The pair of point of intersection
pair<GLPointDouble2D, GLPointDouble2D> GLcroosLineCircuit(GLVelocity3D&  direct, GLPoint3D &firstPnt, GLPoint3D &secondPnt, int radius);

double findThirdCoord(GLPoint3D &firstPnt, GLPoint3D &secondPnt, GLPointDouble2D &pointInOut, int maxHeight);

bool findCoordLessThanMaxHeight(GLPoint3D &firstPnt, GLPoint3D &secondPnt, GLPointDouble2D &crossPoint, int maxHeight);

GLPoint3D AIRLocalCoord2SystemCoord(const GLPoint3D pos, const GLPoint3D coord);

GLPoint3D AIRLocalBearingCoord2SystemCoord( GLPoint3D& pos, double dist, double b, double e);

double course( int vx , int vy );

#endif //_GLGeometry_h_
