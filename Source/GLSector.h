/*! \file GLSector.h
\brief Header file for GLSector class.
*/

// _OS_INDEPENDENT_

#ifndef _GLSector_h_
#define _GLSector_h_

#include "GLGeometry.h"
#include "COTypes.h"

/*!\class GLSector
\brief GLSector.
*/
class GLSector
{
public:
/*!\fn GLSector( void );
\brief Constructor.
*/
	GLSector( void );

/*!\fn GLSector(GLBearing b1, GLBearing b2);
\brief Constructor.
*/
	GLSector(GLBearing b1, GLBearing b2);

/*!\fn void resize_by_one_side( double one_side );
\brief resize sector by azimuth of one side.
Beware!!!
if new sector size will more than 180 grade than this function fail.
\return false if angle larger than 180 grades, true if angle less or equal 180 grades.
*/
	bool resize_by_one_side( double one_side );

/*!\fn double getAzimuth(void) const;
\brief Retrieved azimuth.
\return bisector angle.
*/
	double getAzimuth(void) const;
	int getAzimuthMin() const;

/*!\fn double getBaseAngle(void) const;
\brief Retrieved base angle.
\return base angle.
*/
  double getBaseAngle(void) const;
  int getBaseAngleMin() const;

/*!\fn double getBegSect(void) const;
\brief Retrieved preamble azimuth of sector.
\return preamble azimuth of sector.
*/
  double getBegSect(void) const;

/*!\fn double getEndSect(void) const;
\brief Retrieved final azimuth of sector.
\return final azimuth of sector.
*/
  double getEndSect(void) const;

/*!\fn COUInt32 getFarBordr(void) const;
\brief Retrieved far border of sector.
\return far border of sector.
*/
  COUInt32 getFarBordr(void) const;
  
/*!\fn COUInt32 getNearBordr(void) const;
\brief Retrieved near border of sector.
\return near border of sector.
*/
  COUInt32 getNearBordr(void) const;

/*!\fn double getLoAngleElevtn(void) const;
\brief Retrieves lower border of sector.
\return lower border of sector.
*/
  double getLoAngleElevtn(void) const;

/*!\fn double getHiAngleElevtn(void) const;
\brief Retrieves higher border of sector.
\return higher border of sector.
*/
  double getHiAngleElevtn(void) const;

/*!\fn void setAzimuth(double angl);
\brief Sets azimuth.
\param angl azimuth.

Range (0,2*pi)
*/
	void setAzimuth(double angl);
	void setAzimuthMin(int angl);

  /*!\fn void setAzimuthExpl(double angl);
  \brief Sets azimuth explicit.
  \param angl azimuth.
  
    Range (0,2*pi)
  */
  void setAzimuthExpl(double angl);

/*!\fn void setBaseAngle(double angl);
\brief Sets size of base angle.
\param angl base angle.

Range (0,pi)
*/
  void setBaseAngle(double angl);
  void setBaseAngleMin(int angl);

/*!\fn void setBaseAngle(double begSect,double endSect);
\brief Sets size of base angle & azimuth.
\param begSect preamble azimuth of sector.
\param endSect final azimuth of sector..

Range (0,2*pi)
*/
  void setBaseAngle(double begSect,double endSect);

/*!\fn void setBorders(COUInt32 nearB,COUInt32 farB);
\brief Sets borders of sector.
\param nearB Near border of sector.
\param farB Far border of sector.
*/
  void setBorders(COUInt32 nearB,COUInt32 farB);

/*!\fn void setPsn(const GLPoint3D& psn);
\brief Sets position of sector in space.
\param psn Position of sector in space.
*/
  void setPsn(const GLPoint3D& psn);

/*!\fn void setAnglsElevtn(double loB,double hiB);
\brief Sets angles of elevation.
\param loB Low border of angle of elevation.
\param hiB High border of angle of elevation.
*/
  void setAnglsElevtn(double loB,double hiB);

/*!\fn bool ptInZone( GLPoint3D& coord ) const;
\brief Checking is point belonging to sector.
\param coord coordinates of point.
\return true if point belonging to sector another false.
*/
	bool ptInSector( GLPoint3D& coord ) const;

	bool ptInZone( GLPoint2D& koord ) const;

/*!\fn bool anglInSector( double angle ) const;
\brief Checking is angle belonging to sector.
\param angle Checking angle.
\return true if angle belonging to sector another false.
*/
	bool anglInSector( double angle ) const;

/*!\fn bool ptInBaseAngle( const GLPoint3D& coord ) const;
\brief Determination is point belonging to base angle of sector.
\param coord Point's coordinates .
\return true if point belonging to base angle of sector another false.
*/
  bool ptInBaseAngle( const GLPoint3D& coord ) const;

/*!\fn bool ptInBorder( const GLPoint3D& coord ) const;
\brief Determination is point placed in border of sector.
\param coord Point's coordinates .
\return true if point placed in border of sector another false.
*/
  bool ptInBorder( const GLPoint3D& coord ) const;

/*!\fn bool ptInAngleElevat( const GLPoint3D& coord ) const;
\brief Determination is point belonging to angle of elevation.
\param coord Point's coordinates .
\return true if point belonging to angle of elevation another false.
*/
  bool ptInAngleElevat( const GLPoint3D& coord ) const;

  bool IsSectorInSector( const GLSector& sector );

private:

/*!\var m_BaseAngle
\brief base angle.
*/
	double m_BaseAngle;

/*!\var m_Azimuth
\brief azimuth.
*/
	double m_Azimuth;

/*!\var m_begSect
\brief preamble azimuth of sector.
*/
  double m_begSect;

/*!\var m_endSect
\brief final azimuth of sector.
*/
  double m_endSect;

/*!\var m_LoAngleElevtn
\brief Low border of angle of elevation.
*/
	double m_LoAngleElevtn;

/*!\var m_LoAngleElevtn
\brief High border of angle of elevation.
*/
  double m_HiAngleElevtn;

/*!\var m_nearBord
\brief Near border.
*/
  COUInt32 m_nearBord;

/*!\var m_farBord
\brief Far border.
*/
  COUInt32 m_farBord;

/*!\var m_Position
\brief Position of sector in space.
*/
  GLPoint3D m_Position;
};

/*!\fn double GLmin2rad( short minutes );
\brief Conversion minutes to radians.
\param minutes Value in minutes.
\return Converted value in radians.
*/
double GLmin2rad( short minutes );

/*!\fn short GLrad2min( double radians );
\brief Conversion radians to minutes.
\param radians Value in radians.
\return Converted value in minutes.
*/
short GLrad2min( double radians );

/*!\fn double GLrad2grad( double radians );
\brief Conversion radians to grades.
\param radians Value in radians.
\return Converted value in grades.
*/
double GLrad2grad( double radians );

/*!\fn double GLgrad2rad( short grades );
\brief Conversion grades to radians.
\param radians Value in radians.
\return Converted value in grades.
*/
double GLgrad2rad( short grades );

//#include "GLSector.inl"

#endif //_GLSector_h_
