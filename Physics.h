///
/// Author: Jacob Morgan
///

#pragma once

#include <cmath>

#include "Earth.h"
#include "position.h"
#include "Acceleration.h"

// variables / constants
const double pi = 3.141592653589;

const double frameRate = 30;

const double hoursInADay = 24;

const double minutesInAnHour = 60;

const double secondsInAMinute = 60;

const double secondsInADay = hoursInADay * minutesInAnHour * secondsInAMinute;

const double timeDilation = hoursInADay * minutesInAnHour;

const double timePerFrame = timeDilation / frameRate;

const double speedOfRotation = -1 * ((2 * pi) / frameRate) * (timeDilation / secondsInADay);

/******************************************
 * MAGNITUDE FROM COMPONENTS
 * Returns the magnitude of a value based on its
 * vertical and horizontal components.
 *****************************************/
inline double magnitudeFromComponents(double xComponent, double yComponent)
{
	return sqrt(xComponent * xComponent + yComponent * yComponent);
}
inline double magnitudeFromComponents(double xOrigin, double x, double yOrigin, double y)
{
	return magnitudeFromComponents(x - xOrigin, y - yOrigin);
}

/******************************************
 * HEIGHT ABOVE THE EARTH
 * Returns the hight of a position relative to the
 * earth's surface.
 *****************************************/
inline double heightAboveTheEarth(double horizontalPosition, double verticalPosition, const Earth& earth)
{
	return magnitudeFromComponents(0.0, horizontalPosition, 0.0, verticalPosition) - earth.getRadius();
}

/******************************************
 * MAGNITUDE OF ACCELERATION DUE TO GRAVITY
 * Returns the acceleration of an object based on
 * its
 *****************************************/
inline double magnitudeOfAccelerationDueToGravity(double horizontalPosition, double verticalPosition, const Earth& earth)
{
	double stepOne = earth.getRadius() / (earth.getRadius() + heightAboveTheEarth(horizontalPosition, verticalPosition, earth));
	return earth.getGravityAtSeaLevel() * (stepOne * stepOne);
}

inline double magnitudeOfAccelerationDueToGravity(const Position& pos, const Earth& earth)
{
	return magnitudeOfAccelerationDueToGravity(pos.getMetersX(), pos.getMetersY(), earth);
}

// direction of gravity = atan(horizontal position of planet(0) - horizontal position of object, vertical position of the planet(0) - vertical position of the object)
inline double directionFromComponents(double xComponent, double yComponent)
{
	return atan2(xComponent, yComponent);
}

inline double directionFromComponents(double xOrigin, double yOrigin, double x, double y)
{
	return directionFromComponents(x - xOrigin, y - yOrigin);
}

inline double directionFromComponents(const Position& position)
{
	return directionFromComponents(position.getMetersX(), position.getMetersY());
}

inline double directionFromComponents(const Position& origin, const Position& position)
{
	return directionFromComponents(origin.getMetersX(), origin.getMetersY(), position.getMetersX(), position.getMetersY());
}

// horizontal component of acceleration = total acceleration * sin(angle probably in radians where 0 degrees is up)
inline double horizontalComponent(double direction, double magnitude)
{
	return -1 * magnitude * sin(direction);
}

// vertical component of acceleration = total acceleration * cos(angle probably in radians where 0 degrees is up)
inline double verticalComponent(double direction, double magnitude)
{
	return -1 * magnitude * cos(direction);
}

inline Acceleration accelerationFromGravity(const Position& pos, const Earth& earth)
{
	double direction = directionFromComponents(pos);
	double magnitude = magnitudeOfAccelerationDueToGravity(pos, earth);
	return { horizontalComponent(direction, magnitude), verticalComponent(direction, magnitude) };
}