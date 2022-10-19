#pragma once

#include "uiDraw.h"

/******************************************
 * EARTH
 * This represents the earth in our simulation.
 *****************************************/
class Earth
{
public:
	// constructor(s)
	Earth() : pos(0.0, 0.0), angle(0.0) {}
	Earth(const Position& position) : pos(position), angle(0.0) {}

	// getters
	const double getGravityAtSeaLevel() const
	{
		return gravityAtSeaLevel;
	}
	const double getRadius() const
	{
		return radius;
	}
	const Position& getPosition() const
	{
		return pos;
	}
	// per-frame operations
	void update();
	void draw()
	{
		drawEarth(getPosition(), angle);
	}
private:
	const double gravityAtSeaLevel = 9.80665;
	const double radius = 6378000;

	Position pos;
	double angle;
};

