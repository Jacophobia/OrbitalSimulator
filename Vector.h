///
/// Author: Jacob Morgan
///

#pragma once

#include <cmath>

/*********************************************
 * VECTOR
 * One vector, comprised of an x and y component. Provides useful
 * functions for working with vectors.
 *********************************************/
class Vector
{
public:
	//constructors
	Vector() : xComponent(0.0), yComponent(0.0) {}
	Vector(double x, double y) : xComponent(x), yComponent(y) {}
	Vector(const Vector& rhs) : xComponent(rhs.xComponent), yComponent(rhs.yComponent) {}
	Vector(Vector&& rhs) : xComponent(rhs.xComponent), yComponent(rhs.yComponent) 
	{
		rhs.xComponent = 0.0;
		rhs.yComponent = 0.0;
	}

	//getters
	const double getX() const { return xComponent; }
	const double getY() const { return yComponent; }
	const double getMagnitude() const;
	const double getDirection() const;

	//setters and adders
	void setX(double x) { xComponent = x; }
	void setY(double y) { yComponent = y; }
	void addX(double x) { xComponent += x; }
	void addY(double y) { yComponent += y; }
	void setComponents(double x, double y)
	{
		setX(x);
		setY(y);
	}
	void setDirectionMagnitude(double direction, double magnitude);

	//= operation
	Vector& operator=(const Vector& rhs)
	{
		xComponent = rhs.xComponent;
		yComponent = rhs.yComponent;
		return *this;
	}
private:
	double xComponent;
	double yComponent;

	friend class TestVector;
};

