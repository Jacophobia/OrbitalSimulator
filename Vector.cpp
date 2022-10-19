///
/// Author: Jacob Morgan
///

#include "Vector.h"

#include "Physics.h"

/*********************************************
 * GET MAGNITUDE
 * Returns magnitude of vector
 *********************************************/
const double Vector::getMagnitude() const
{
	return magnitudeFromComponents(xComponent, yComponent);
}

/*********************************************
 * GET MAGNITUDE
 * Returns direction of vector
 *********************************************/
const double Vector::getDirection() const
{
	return directionFromComponents(xComponent, yComponent);
}

/*********************************************
 * SET DIRECTION / MAGNITUDE
 * Sets vector using direction and magnitude
 *********************************************/
void Vector::setDirectionMagnitude(double direction, double magnitude)
{
	xComponent = horizontalComponent(direction, magnitude);
	yComponent = verticalComponent(direction, magnitude);
}
