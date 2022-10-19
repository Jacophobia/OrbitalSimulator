///
/// Author: Jacob Morgan
///

#pragma once

#include "Parts.h"
#include "position.h"
#include "Velocity.h"
#include "Physics.h"
#include "uiDraw.h" // for random

/******************************************
 * FRAGMENT
 * One satellite fragment
 *****************************************/
class Fragment : public Part
{
public:
	// constructor
	Fragment(const Position& pos, const Velocity& vel) :
		Part(pos, vel),
		timeAlive(random(50.0 /* frames */ * 48.0 /* seconds per frame */, 100.0 * 48.0))
	{
		setRadius(256000);
	}

	/******************************************
	* DRAW
	* Draws a fragment
	*****************************************/
	void draw() override
	{
		drawFragment(getPosition(), getAngle());
	}

	/******************************************
	* UPDATE
	* Updates position, velocity, angle, and timeAlive
	*****************************************/
	void update(double time, const Earth& earth) override
	{
		Part::update(time, earth);
		timeAlive -= time;
	}

	/******************************************
	* HAS FIZZLED
	* Returns whether fragment has fizzled, either by colliding with earth or
	* running out of time
	*****************************************/
	bool hasFizzled(const Earth& earth) override
	{
		return Part::hasFizzled(earth) || timeAlive <= 0.0;
	}

	/******************************************
	* EXPLODE
	* Returns the pieces and fragments left when destroyed (which is nothing)
	*****************************************/
	std::vector<std::shared_ptr<Satellite>> explode() override
	{
		return { };
	}
private:
	double timeAlive;
};