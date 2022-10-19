///
/// Author: Jacob Morgan
///

#pragma once
#include "Vector.h"

class Acceleration;

/*********************************************
 * Velocity
 * A vector representing velocity, which can be applied to a position
 *********************************************/
class Velocity : public Vector
{
public:
	Velocity() : Vector(0.0, 0.0) {}
	Velocity(double x, double y) : Vector::Vector(x, y) {}
	void apply(const Acceleration& acceleration, double time);
};

