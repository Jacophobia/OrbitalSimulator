/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "position.h"
#include <cassert>

#include "Velocity.h"
#include "Acceleration.h"


Position::Position(double x, double y) : x(0.0), y(0.0)
{
   setMetersX(x);
   setMetersY(y);
}

/******************************************
 * POINT : ASSIGNMENT
 * Assign a point
 *****************************************/
Position& Position::operator = (const Position& pt)
{
   x = pt.x;
   y = pt.y;
   return *this;
}

void Position::apply(const Acceleration& acceleration, const Velocity& velocity, double time)
{
	addMetersX(velocity.getX() * time + 0.5 * acceleration.getX() * time * time);
	addMetersY(velocity.getY() * time + 0.5 * acceleration.getY() * time * time);
}

/******************************************
 * POSITION insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream& operator << (std::ostream& out, const Position& pt)
{
   out << "(" << pt.getMetersX() << "m , " << pt.getMetersY() << "m)";
   return out;
}
   
/*******************************************
* POSITION extraction
*       Prompt for coordinates
******************************************/
std::istream& operator >> (std::istream& in, Position& pt)
{
   double x;
   double y;
   in >> x >> y;

   pt.setMetersX(x);
   pt.setMetersY(y);

   return in;
}

/************************************************************************
 * ROTATE
 * Rotate a given point (point) around a given origin (center) by a given
 * number of degrees (angle).
 *    INPUT  origin   The center point we will rotate around
 *           x,y      Offset from center that we will be rotating, in pixels
 *           rotation Rotation in degrees
 *    OUTPUT point    The new position
 *************************************************************************/
Position rotate(const Position& origin, double x, double y, double rotation)
{
	// because sine and cosine are expensive, we want to call them only once
	double cosA = cos(rotation);
	double sinA = sin(rotation);

	// start with our original point
	Position ptReturn(origin);

	// find the new values
	ptReturn.addPixelsX(x * cosA + y * sinA);
	ptReturn.addPixelsY(y * cosA - x * sinA);

	return ptReturn;
}

/************************************************************************
 * ROTATE METERS
 * Rotate a given point (point) around a given origin (center) by a given
 * number of degrees (angle).
 *    INPUT  origin   The center point we will rotate around
 *           x,y      Offset from center that we will be rotating, in meters
 *           rotation Rotation in degrees
 *    OUTPUT point    The new position
 *************************************************************************/
Position rotateMeters(const Position& origin, double x, double y, double rotation)
{
	// because sine and cosine are expensive, we want to call them only once
	double cosA = cos(rotation);
	double sinA = sin(rotation);

	// start with our original point
	Position ptReturn(origin);

	// find the new values
	ptReturn.addMetersX(x * cosA + y * sinA);
	ptReturn.addMetersY(y * cosA - x * sinA);

	return ptReturn;
}