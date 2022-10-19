///
/// Author: Jacob Morgan
///

#include "Satellite.h"

#include "Physics.h"
#include "uiDraw.h"
#include "Fragment.h"

/******************************************
 * UPDATE
 * Updates the position, velocity, and angle based on acceration
 *****************************************/
void Satellite::update(double time, const Earth& earth)
{
	Acceleration acceleration = accelerationFromGravity(position, earth);
	velocity.apply(acceleration, time);
	position.apply(acceleration, velocity, time);
	angle += getAngularVelocity();
}



/******************************************
 * HAS FIZZLED
 * Returns whether satellite has collided with Earth
 *****************************************/
bool Satellite::hasFizzled(const Earth& earth)
{
	return hasCollidedWith(earth.getPosition(), earth.getRadius());
}

/******************************************
 * HAS COLLIDED WITH
 * Returns whether satellite has collided with object of pos and radius
 *****************************************/
bool Satellite::hasCollidedWith(const Position& pos, double radius)
{
	double a = position.getMetersX() - pos.getMetersX();
	double b = position.getMetersY() - pos.getMetersY();

	return sqrt(a * a + b * b) < this->radius + radius;
}

/******************************************
 * HAS COLLIDED WITH
 * Returns whether satellite has collided with rhs satellite
 *****************************************/
bool Satellite::hasCollidedWith(const Satellite& rhs)
{
	return hasCollidedWith(rhs.position, rhs.radius);
}

/******************************************
 * EXPLODE
 * Returns the pieces and fragments left when destroyed
 *****************************************/
std::vector<std::shared_ptr<Satellite>> Satellite::explode()
{
	return { std::make_shared<Fragment>(position, velocity), 
			 std::make_shared<Fragment>(position, velocity), 
			 std::make_shared<Part>(position, velocity),
			 std::make_shared<GPSLeft>(position, velocity),
			 std::make_shared<GPSRight>(position, velocity) };
}
