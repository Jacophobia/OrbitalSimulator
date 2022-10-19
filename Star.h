///
/// Author: Jacob Morgan
///

#pragma once

#include "uiDraw.h" 

#include "position.h"

/******************************************
* STAR
* One Star
*****************************************/
class Star
{
public:
	// constructors
	Star() = default;
	Star(const Position& ptUpperRight) : phase(0)
	{
		position.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
		position.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
		phase = (unsigned char)random(0, 255);
	}
	Star(const Star& rhs)
	{
		position = rhs.position;
		phase = rhs.phase;
	}
	Star(Star&& rhs)
	{
		position = rhs.position;
		phase = rhs.phase;
		rhs.position.setMeters(0.0, 0.0);
		rhs.phase = 0;
	}

	// per-frame operation
	virtual void update()
	{
		phase++;
	}
	virtual void draw()
	{
		drawStar(position, phase);
	}
private:
	Position position;
	unsigned char phase;
};

