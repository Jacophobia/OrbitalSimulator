///
/// Author: Jacob Morgan
///

#include "Velocity.h"

#include "Acceleration.h"
#include <iostream>

/*********************************************
 * APPLY
 * Update velocity using acceleration and time
 *********************************************/
void Velocity::apply(const Acceleration& acceleration, double time)
{
	addX(acceleration.getX() * time);
	addY(acceleration.getY() * time);
}
