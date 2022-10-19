#pragma once

#include "Vector.h"

/*********************************************
 * Acceleration
 * A vector representing acceleration, which can be applied to a velocity or position
 *********************************************/
class Acceleration : public Vector
{
public:
	Acceleration() : Vector() {}
	Acceleration(double x, double y) : Vector(x, y) {}

	Acceleration operator+(const Vector& rhs) const
	{
		return { getX() + rhs.getX(), getY() + rhs.getY() };
	}
};

