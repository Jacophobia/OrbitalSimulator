///
/// Author: Jacob Morgan
///

#pragma once

#include "Satellite.h"

#include "uiDraw.h"

/******************************************
* BULLET
* One bullet shot by the ship
*****************************************/
class Bullet : public Satellite
{
public:
	// constructor
	Bullet(const Position& position, const Velocity& velocity, double angle) : 
		Satellite(position, velocity),
		timeAlive(random(25.0 /* frames */ * 48.0 /* seconds per frame */, 50.0 * 48.0))
	{
		setAngle(angle);
		setAngularVelocity(0.0);
		setRadius(256000.0);
	}

	/******************************************
	* UPDATE
	* Updates position, velocity, angle, and timeAlive
	*****************************************/
	void update(double time, const Earth& earth) override
	{
		Satellite::update(time, earth);
		timeAlive -= time;
	}

	/******************************************
	* DRAW
	* Draws a bullet
	*****************************************/
	void draw() override
	{
		drawProjectile(position);
	}

	/******************************************
	* HAS FIZZLED
	* Returns whether fragment has fizzled, either by colliding with earth or
	* running out of time
	*****************************************/
	bool hasFizzled(const Earth& earth) override
	{
		return Satellite::hasFizzled(earth) || timeAlive <= 0.0;
	}

	std::vector<std::shared_ptr<Satellite>> explode() override
	{
		return { };
	}
private:
	double timeAlive;
};