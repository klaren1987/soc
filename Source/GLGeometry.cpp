/*! \file GLGeometry.cpp
\brief Implementation of everything declared in GLGeometry.h
*/

// _OS_INDEPENDENT_


#include "GLGeometry.h"

#include"COTypes.h"
#include<assert.h>
#undef _OSF_SOURCE
#include <math.h>

//const double PI = 3.1415926535897932384626433832795;

/*********************************************************************

                   GLPoint3D implementation

**********************************************************************/

GLPoint3D::GLPoint3D( int x0, int y0, int h0 ) :
  x(x0), y(y0), h(h0)
{
  // Nothing to do.
}

GLFixedPoint::GLFixedPoint( GLPoint3D& p ,int sm0 ) :
  GLPoint3D( p.x, p.y, p.h ), sm(sm0)
{
  // Nothing to do.
}

GLFixedPoint::GLFixedPoint( void ) : sm(0){
	//
}

bool GLFixedPoint::operator==( const GLFixedPoint& other ) const
{
	if(x == other.x && y == other.y && h == other.h)
	{
		return true;
	}
  
	return false;
}

GLPoint3D::GLPoint3D( GLPoint2D p ) :
  x(p.x), y(p.y), h(0)
{
  // Nothing to do.
}

bool GLPoint3D::operator ==( const GLPoint3D& other ){
	if( x == other.x && y == other.y && h == other.h )
		return true;
	return false;
}

bool GLPoint3D::operator !=( const GLPoint3D& other ){
	return !( *this == other );
}

GLPoint2D::GLPoint2D( int x0, int y0 ) :
  x(x0), y(y0)
{
  // Nothing to do.
}

GLPoint2D::GLPoint2D( const GLPoint2D& copy ):x(copy.x),y(copy.y)
{}

GLPoint2D::GLPoint2D( GLPoint3D p ) :
  x(p.x), y(p.y)
{
  // Nothing to do.
}

/*********************************************************************

                   GLPointDouble2D implementation

**********************************************************************/
GLPointDouble2D::GLPointDouble2D(void) :
x(0), y(0)
{
}

GLPointDouble2D::GLPointDouble2D(const double& X,const double& Y) :
x(X), y(Y)
{
}

void GLPointDouble2D::init(const double& X,const double& Y)
{
	x=X;
	y=Y;
}

GLPointDouble2D GLPointDouble2D::operator+(GLPointDouble2D Q)
{
	GLPointDouble2D tmp;
	tmp.x=this->x+Q.x;
	tmp.y=this->y+Q.y;
	return tmp;
}

GLPointDouble2D GLPointDouble2D::operator=(const GLPointDouble2D& Q)
{
	this->x=Q.x;
	this->y=Q.y;
	return *this;
}

bool GLPointDouble2D::operator==(GLPointDouble2D& Q)
{
	double tmp;
	COInt64 chek1,chek2;
	tmp = (this->x > Q.x) ? (this->x-Q.x):(Q.x-this->x);
	if((tmp-(COInt64)tmp)>=0.5)
			chek1=(COInt64)tmp+1;
	else
		chek1=(COInt64)tmp;
	tmp = (this->y > Q.y) ? (this->y-Q.y):(Q.y-this->y);
	if((tmp-(COInt64)tmp)>=0.5)
			chek2=(COInt64)tmp+1;
	else
		chek2=(COInt64)tmp;
	
	if(chek1==0 && chek2==0)
		return true;
	return false;
}
/*********************************************************************

                   GLVelocity3D implementation

**********************************************************************/

GLVelocity3D::GLVelocity3D( int vx0, int vy0, int vh0 ) :
  vx(vx0), vy(vy0), vh(vh0)
{
  // Nothing to do.
}




/*********************************************************************

                   GLBearing implementation

**********************************************************************/

GLBearing::GLBearing( double b0, double e0 ) :
  b(b0), e(e0)
{
  // Nothing to do.
}

GLBearing::GLBearing(GLPoint3D p)
{
	if (p.x == 0)
	{
		b = (p.y > 0) ? PI / 2.0 : 1.5 * PI;
	}
	else if (p.y == 0)
	{
		b = (p.x > 0) ? 0 : PI;
	}
	else
	{
		if ( (b = atan2(p.y, p.x)) < 0 ) b += 2.0 * PI;
	}

	e = atan2 (p.h,
						 sqrt( (double)p.x * (double)p.x + 
									 (double)p.y * (double)p.y ) );
}

GLBearing::GLBearing(GLPoint2D p)
{
	if (p.x == 0)
	{
		b = (p.y > 0) ? PI / 2.0 : 1.5 * PI;
	}
	else if (p.y == 0)
	{
		b = (p.x > 0) ? 0 : PI;
	}
	else
	{
		if ( (b = atan2(p.y, p.x)) < 0 ) b += 2.0 * PI;
	}
}

/*********************************************************************

                   GLBearingVelocity implementation

**********************************************************************/

GLBearingVelocity::GLBearingVelocity( double vb0, double ve0 ) :
  vb(vb0), ve(ve0)
{
  // Nothing to do.
}

GLBearingVelocity::GLBearingVelocity(GLVelocity3D p)
{
	if (p.vx == 0)
	{
		vb = (p.vy > 0) ? PI / 2.0 : 1.5 * PI;
	}
	else if (p.vy == 0)
	{
		vb = (p.vx > 0) ? 0 : PI;
	}
	else
	{
		if ( (vb = atan2(p.vy, p.vx)) < 0 ) vb += 2.0 * PI;
	}

	ve = atan2 (p.vh,
						 sqrt( (double)p.vx * (double)p.vx + 
									 (double)p.vy * (double)p.vy ) );
}


unsigned int GLdistance( const GLPoint2D& p1, const GLPoint2D& p2 )
{
  return (unsigned int)sqrt(
    (double)(p1.x - p2.x)*(p1.x - p2.x) +
    (double)(p1.y - p2.y)*(p1.y - p2.y));
}

unsigned int GLdistance( const GLPoint3D& p1, const GLPoint3D& p2 )
{
  return (unsigned int)sqrt(
    (double)(p1.x - p2.x)*(p1.x - p2.x) +
    (double)(p1.y - p2.y)*(p1.y - p2.y) +
    (double)(p1.h - p2.h)*(p1.h - p2.h));
}

unsigned int GLdistanceFlat( const GLPoint3D& p1, const GLPoint3D& p2 )
{
  return (unsigned int)sqrt(
    (double)(p1.x - p2.x)*(p1.x - p2.x) +
    (double)(p1.y - p2.y)*(p1.y - p2.y));
}

unsigned int GLdistance( const GLPoint3D& p )
{
  return (unsigned int)sqrt( ((double)p.x * p.x) +
														 ((double)p.y * p.y) +
														 ((double)p.h * p.h) );
}

unsigned int GLdistanceProjection( const GLPoint3D& p )
{
  return (unsigned int)sqrt( ((double)p.x * p.x) +
														 ((double)p.y * p.y) );
}

unsigned int GLabs( const GLVelocity3D& v )
{
  return (unsigned int)sqrt(
    (double)v.vx*v.vx + (double)v.vy*v.vy + (double)v.vh*v.vh);
}

unsigned int GLabsFlat( const GLVelocity3D& v )
{
  return (unsigned int)sqrt(
    (double)v.vx*v.vx + (double)v.vy*v.vy);
}


double GLazimuthChange(double newA, double prevA)
{
	if (newA >= 2*PI) newA -= 2*PI;
	if (prevA >= 2*PI) prevA -= 2*PI;

	double d = newA - prevA;
	if (PI < fabs(d)) d = (d > 0) ? d - 2*PI : d + 2*PI;

	return d;	
}

double GLmeetAngle(double a1, double a2)
{
	double meetAngle = GLazimuthChange(a1, a2);
	
	meetAngle = PI/2.0 < fabs(meetAngle) ? 
										PI - fabs(meetAngle):
										fabs(meetAngle);

	return meetAngle;
}

bool GLazimuthSector(const list<GLPoint3D>& rList, GLSector& sect)
{
  if(rList.size() < 2)
  {
    return false;
  }
  double maxDistance1 = 0.0;
  double azimuth11 = 0.0, azimuth12 = 0.0;

  list<GLPoint3D>::const_iterator target1, target2;

  for(target1 = rList.begin(); target1!= rList.end(); ++target1)
  {
    double maxDistance3 = 0.0, maxDistance2 = 0.0;
    double azimuth21 = 0.0, azimuth22 = 0.0;

    for(target2 = target1; target2!= rList.end(); ++target2)
    {
      double a1 = atan2((*target1).y, (*target1).x),
             a2 = atan2((*target2).y, (*target2).x);
      maxDistance3 = fabs( a1 - a2 );

      if(maxDistance3 > PI)
      {
        maxDistance3 = 2.0 * PI - maxDistance3;
      }

      if(maxDistance3 >= maxDistance2)
      {
        maxDistance2 = maxDistance3;
        azimuth21 = a1;
        azimuth22 = a2;
      }
    }
    if(maxDistance1 <= maxDistance2)
    {
      maxDistance1 = maxDistance2;
      azimuth11 = azimuth21;
      azimuth12 = azimuth22;
    }
  }

  if( azimuth12 < 0 ){
  	azimuth12 = 2 * PI + azimuth12;
  }
  if( azimuth11 < 0 ){
  	azimuth11 = 2 * PI + azimuth11;
  }
  if( azimuth11 < azimuth12 ){
	sect.setBaseAngle(azimuth11, azimuth12);
  }
  else{
  	sect.setBaseAngle(azimuth12, azimuth11);
  }
  return true;
}

GLPoint2D GLPtFall(GLPoint2D& pt0,GLPoint2D& pt2,GLPoint2D& pt3)
{
	GLPoint2D pt;
	double k1,k2,b1,b2;
	if(pt3.y==pt2.y){pt.x=pt0.x;pt.y=pt2.y;return pt;}
	if(pt3.x==pt2.x){pt.y=pt0.y;pt.x=pt2.x;return pt;}
	k1=(double)(pt3.x-pt2.x)/(double)(pt3.y-pt2.y);
	k2=(double)(pt2.y-pt3.y)/(double)(pt3.x-pt2.x);
	b1=(double)pt2.x-k1*((double)pt2.y);
	b2=(double)pt0.x-k2*((double)pt0.y);
	pt.x=(long)((k2*b1-k1*b2)/(k2-k1));
	pt.y=(long)((b1-b2)/(k2-k1));
	return pt;
}

int toBCD32(int x)
{
	int bcd = 0;
	if (x<=99999999)
	{	
		int sdv = 28;
		for(int k = 10000000; k>0; k = k/10, sdv = sdv-4)
		{
			bcd |= (x/k)<<sdv;
			x = x - (x/k)*k;
		}
	}
	return bcd;
}

int fromBCD32(int bcd)
{
	int x = 0;
	if (bcd<=0x99999999)
	{	
		for(int k = 1; k<10000001; k = k*10)
		{
			x = x + (bcd&0xf)*k;
			bcd = bcd>>4;
		}
	}
	return x;
}

pair<GLPointDouble2D, GLPointDouble2D> GLcroosLineCircuit(GLVelocity3D&  direct, GLPoint3D &firstPnt, GLPoint3D &secondPnt, int radius)
{
	GLPointDouble2D onePnt;
	GLPointDouble2D otherPnt;
	
	if( firstPnt.x == secondPnt.x)
	{
		if(firstPnt.y != secondPnt.y)
		{
			onePnt.y = sqrt( (double)(radius * radius - firstPnt.x * firstPnt.x));
			otherPnt.y = -sqrt( (double)(radius * radius - firstPnt.x * firstPnt.x));
			onePnt.x = firstPnt.x;
			otherPnt.x = firstPnt.x;
		}
		else
		{
			onePnt.y = firstPnt.x;
			otherPnt.y = firstPnt.x;
			onePnt.x = firstPnt.x;
			otherPnt.x = firstPnt.x;
		}
	}
	else
	{
		if( firstPnt.y == secondPnt.y)
		{
			onePnt.x = sqrt( (double)(radius * radius - firstPnt.y * firstPnt.y));
			otherPnt.x = -sqrt( (double)(radius * radius - firstPnt.y * firstPnt.y));
			onePnt.y = firstPnt.y;
			otherPnt.y = firstPnt.y;
		}
		else
		{
			//get coefficient of line x = y * k + m
			double k = (double)(firstPnt.x - secondPnt.x)/(double)(firstPnt.y - secondPnt.y);
			double m = (double)firstPnt.x - (double)firstPnt.y * k;
			
			// x*x + y*y = radius* radius
			// (y * k + m)*(y * k + m) + y*y - radius* radius = 0
			//get coefficints of quadratic z*z*a + z*b + c = 0
			double a = 1.0 + k * k;
			double b = 2.0 * k * m;
			double c = m * m - (double)radius * (double)radius;

			//get solution of quadratic
			onePnt.y = (sqrt( b*b - 4.0*a*c) - b) /(2.0*a);
		
			otherPnt.y = (-sqrt( b*b - 4.0*a*c) - b )/(2.0*a);
		
			onePnt.x = onePnt.y * k + m;
			
			otherPnt.x = otherPnt.y * k + m;	
		}
	}
	
	return make_pair( onePnt, otherPnt );
}

double findThirdCoord(GLPoint3D &firstPnt, GLPoint3D &secondPnt, GLPointDouble2D &pointInOut, int maxHeight)
{
	if( firstPnt.h == secondPnt.h)
	{
		return firstPnt.h;
	}
	else
	{
		if(firstPnt.y != secondPnt.y)
		{
			//To find third corrdinate of crossing point
			//get coefficient of line h = y * k + m
			double k = (double)(firstPnt.h - secondPnt.h)/(double)(firstPnt.y - secondPnt.y);
			double m = (double)firstPnt.h - (double)firstPnt.y * k;
			return  pointInOut.y * k + m;
		}
		else
		{
			if(firstPnt.x != secondPnt.x)
			{
				//To find third corrdinate of crossing point
				//get coefficient of line h = x * k + m
				double k = (double)(firstPnt.h - secondPnt.h)/(double)(firstPnt.x - secondPnt.x);
				double m = (double)firstPnt.h - (double)firstPnt.x * k;
				return pointInOut.x * k + m;
			}
			return (double)maxHeight;
		}
	}
}

bool findCoordLessThanMaxHeight(GLPoint3D &firstPnt, GLPoint3D &secondPnt, GLPointDouble2D &crossPoint, int maxHeight)
{

	crossPoint.x = firstPnt.x;
	crossPoint.y = firstPnt.y;

	if(firstPnt.h == secondPnt.h)
	{
		if(firstPnt.h > maxHeight)
		{
			return false;
		}
	}
	else
	{
		if(firstPnt.y != secondPnt.y)
		{
			//To find third corrdinate of crossing point
			//get coefficient of line h = y * k + m
			double k = (double)(firstPnt.y - secondPnt.y)/(double)(firstPnt.h - secondPnt.h);
			double m = (double)firstPnt.y - (double)firstPnt.h * k;
			crossPoint.y = maxHeight * k + m;
		}
					
		if(firstPnt.x != secondPnt.x)
		{
			//To find third corrdinate of crossing point
			//get coefficient of line h = x * k + m
			double k = (double)(firstPnt.x - secondPnt.x)/(double)(firstPnt.h - secondPnt.h);
			double m = (double)firstPnt.x - (double)firstPnt.h * k;
			crossPoint.x = maxHeight * k + m;
		}
	}
	return true;
}

double GLdistance( const GLPointDouble2D& p1, const GLPointDouble2D& p2 )
{
  return sqrt(
    (double)(p1.x - p2.x)*(p1.x - p2.x) +
    (double)(p1.y - p2.y)*(p1.y - p2.y));
}

GLPoint3D AIRLocalBearingCoord2SystemCoord( GLPoint3D& pos, double dist, double b, double e)
{
	GLPoint3D jmrPos;
	//jmrPos - 
	jmrPos.x = int(dist * cos(e) * cos(b));
	jmrPos.y = int(dist * cos(e) * sin(b));
	jmrPos.h = int(dist * sin(e));

	return jmrPos;//AIRLocalCoord2SystemCoord(pos, jmrPos);
}

GLPoint3D AIRLocalCoord2SystemCoord(const GLPoint3D pos, const GLPoint3D coord)
{
	GLPoint3D systemCoord(coord.x + pos.x,
											 coord.y + pos.y,
											 coord.h + pos.h);

	systemCoord.h += int(((double)coord.x * coord.x +
									(double)coord.y * coord.y) / 17000000.0);

	return systemCoord;
}

double course( int vx , int vy )
{
  double c = atan2(vy, vx);
  if (c < 0.0)
  {
    c += 2.0*PI;
  }
  return c/PI*180;
}

