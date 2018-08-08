/*!\file GLSector.cpp
\brief Implementation file for GLSector class.
*/

// _OS_INDEPENDENT_
#include "GLSector.h"
#include<assert.h>
#undef _OSF_SOURCE
#include <math.h>

GLSector::GLSector(void):
 m_BaseAngle(0),
 m_Azimuth(-1),
 m_LoAngleElevtn(0),
 m_HiAngleElevtn(0),
 m_nearBord(0),
 m_farBord(0),
 m_begSect(0),
 m_endSect(0)
{
  
}

 GLSector::GLSector(GLBearing b1, GLBearing b2):
 m_BaseAngle(0),
 m_Azimuth(-1),
 m_LoAngleElevtn(0),
 m_HiAngleElevtn(0),
 m_nearBord(0),
 m_farBord(0)
{
 setBaseAngle(b1.b, b2.b);
}

bool GLSector::ptInSector( GLPoint3D& coord ) const
{
  if(ptInBaseAngle(coord) == true)
    if(ptInAngleElevat(coord) == true)
      if(ptInBorder(coord) == true) return true;
  return false;
}

bool GLSector::anglInSector( double angle ) const
{
	if(angle < 0)
	{
		angle += 2 * PI;
	}
	double halfBaseAngl = m_BaseAngle / 2;
	if( (m_Azimuth - halfBaseAngl) < 0 )
	{ 
		if ((angle >= 2.0*PI + (m_Azimuth - halfBaseAngl)) || (angle <= (m_Azimuth + halfBaseAngl)))
			return true;
	}
	else if ((m_Azimuth + halfBaseAngl) > 2.0*PI)
	{
		if ((angle >= (m_Azimuth - halfBaseAngl)) || (angle <= (m_Azimuth + halfBaseAngl) - 2.0*PI))
			return true;
	}
	else
  	{ 
		if( angle >= (m_Azimuth - halfBaseAngl) &&
		    angle <= (m_Azimuth + halfBaseAngl) )
		{
			return true;
		}
	}
	return false;
}

bool GLSector::ptInBaseAngle( const GLPoint3D& coord ) const
{
  double angle = 0;
  angle = atan2( coord.y - m_Position.y, coord.x - m_Position.x );
  if( angle < 0 ) angle = angle + 2.0*PI;
  return anglInSector(angle);
}

bool GLSector::ptInBorder( const GLPoint3D& coord ) const
{
  COUInt32 distncToPt = 
           GLdistance( GLPoint2D(coord.x,coord.y),
                       GLPoint2D(m_Position.x,m_Position.y) );
  if( distncToPt >= m_nearBord &&
      distncToPt <= m_farBord ) return true;
  else return false;
}

bool GLSector::ptInAngleElevat( const GLPoint3D& coord ) const
{
  COUInt32 distncToPt = 
           GLdistance( GLPoint2D(coord.x,coord.y),
                       GLPoint2D(m_Position.x,m_Position.y) );
  double ptAnglElvtn = atan2( coord.h/* - m_Position.h*/ ,distncToPt );
  if( ptAnglElvtn < m_HiAngleElevtn &&
      ptAnglElvtn > m_LoAngleElevtn) return true;
  else return false;
}

void GLSector::setAzimuthExpl(double angl)
{
  m_Azimuth = angl;
}

bool GLSector::resize_by_one_side( double one_side )
{
	if( one_side > 2.0*PI )
	{
		one_side -= 2.0*PI;
	}
	if( one_side < 0 )
	{
		one_side += 2.0*PI;
	}
	assert( (one_side >= 0 && one_side <= 2.0*PI) );
	assert( m_Azimuth != -1 );
	double l_res = fabs( one_side - m_Azimuth );
	if( l_res > (PI/2.0)*3 )
	{
		l_res = PI*2.0 - l_res;
	}
	if( l_res >= PI/2 )
	{
		return false;
	}
	setBaseAngle( l_res * 2 );
	return true;
}

void GLSector::setAzimuth(double angl)
{
  //assert(angl <= 2.0*PI);
  if( angl > 2.0*PI)
  {
    angl -= 2.0*PI;
  }
  assert(angl <= 2.0*PI);
  if(angl < 0)
  {
    angl+=2.0*PI;
  }
  assert( (angl >= 0 && angl <= 2.0*PI) );
  m_Azimuth = angl;
  double halfSect = m_BaseAngle / 2;
  m_begSect = angl - halfSect;
  if(m_begSect < 0)
    m_begSect += 2.0*PI;
  m_endSect = angl + halfSect;
  if(m_endSect > 2.0*PI)
    m_endSect -= 2.0*PI;
}


void GLSector::setAzimuthMin(int angl)
{
	setAzimuth((double)angl/60*PI/180); 
} 


void GLSector::setBaseAngle(double begSect,double endSect)
{
  assert(begSect <= 2*PI);
  assert(endSect <= 2*PI);
  if(endSect < begSect) endSect += 2*PI; 
  m_BaseAngle = endSect - begSect;
  
  //printf ( "begSect = %f; endSect = %f; m_BaseAngle = %f \n",begSect, endSect, m_BaseAngle);

	m_BaseAngle = fabs(m_BaseAngle);

	double halfSect = m_BaseAngle / 2;
	double end_beg = endSect - begSect;
	double beg_end = begSect - endSect;
	double P2_m_BaseAngle = 2*PI - m_BaseAngle;

	if ((end_beg == m_BaseAngle) || (beg_end == P2_m_BaseAngle))
	{
		m_Azimuth = begSect + halfSect;
	}
	else 
	{
		if ((beg_end == m_BaseAngle) || (end_beg == P2_m_BaseAngle))
		{
			m_Azimuth = endSect + halfSect;
		}
		else 
		{	
			assert(false);			
		}
	}

	if(m_Azimuth > 2*PI)  m_Azimuth -= 2.0*PI;

  m_begSect = begSect;
  m_endSect = endSect;

}

bool GLSector::IsSectorInSector( const GLSector& sector )
{
	double a = sector.getBegSect();
	double b = sector.getEndSect();

	if (m_begSect>=0 && m_endSect>=0)
	{
		if (a>=0 && b>=0)
			if (a>=m_begSect && b<=m_endSect) return true;
			
		if (a<=0 && b<=0)
			if ((a+2.0*PI)<=m_endSect && (b+2.0*PI)>=m_begSect) return true;

		if (a>=0 && b<=0)
			if (a>=m_begSect && (b+2.0*PI)<=m_endSect) return true;
		
		if (a<=0 && b>=0)
			if ((a+2.0*PI)<=m_endSect && b>=m_begSect) return true;
	}

	if (m_begSect<=0 && m_endSect<=0)
	{
		if (a>=0 && b>=0)
			if (a>=(m_endSect+2.0*PI) && b<=(m_begSect+2.0*PI)) return true;
			
		if (a<=0 && b<=0)
			if (a<=m_begSect && b<=m_endSect) return true;

		if (a>=0 && b<=0)
			if (a>=(m_endSect+2.0*PI) && b<=m_begSect) return true;
		
		if (a<=0 && b>=0)
			if (a<=m_begSect && b>=m_endSect+2.0*PI) return true;
	}

	if (m_begSect>=0 && m_endSect<=0)
	{
		if (a>=0 && b>=0)
			if (a>=m_begSect && b<=(m_endSect+2.0*PI)) return true;
			
		if (a<=0 && b<=0)
			if (a<=m_endSect && (b+2.0*PI)>=m_begSect) return true;

		if (a>=0 && b<=0)
			if (a>=m_begSect && b<=m_endSect) return true;
		
		if (a<=0 && b>=0)
			if (a>=m_endSect && b<=m_begSect) return true;
	}

	if (m_begSect<=0 && m_endSect>=0)
	{
		if (a>=0 && b>=0)
			if (b<=m_endSect) return true;
			
		if (a<=0 && b<=0)
			if (a<=m_begSect && b<=m_begSect) return true;

		if (a>=0 && b<=0)
			if (a<=m_endSect && b<=m_begSect) return true;
		
		if (a<=0 && b>=0)
			if (a<=m_begSect && b<=m_endSect) return true;
	}
	return false;
}
