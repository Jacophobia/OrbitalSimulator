#pragma once

#include "Velocity.h"
#include "Acceleration.h"
#include "position.h"
#include "Earth.h"
#include "uiDraw.h" // for random
#include <vector>

/*********************************************
 * Position
 * An object orbiting Earth. Is a GPS satellite by default
 *********************************************/
class Satellite
{
public:
	//constructor
	Satellite(const Position& position, const Velocity& velocity) : 
		velocity(velocity), position(position), 
		angle(random(0.0, 2*3.141592653589)), angularVelocity(random(-0.03, 0.03)) {}

	virtual void update(double time, const Earth& earth);
	virtual bool hasFizzled(const Earth& earth);
	virtual std::vector<std::shared_ptr<Satellite>> explode();
	bool hasCollidedWith(const Position& pos, double radius);
	bool hasCollidedWith(const Satellite& rhs);

	//private getters
	const Position& getPosition() const { return position; }

	/******************************************
	* DRAW
	* Draws a GPS Satellite
	*****************************************/
	virtual void draw()
	{
		drawGPS(position, getAngle());
	}
protected:
	//protected getters
	double getAngle() { return angle; }
	double getRadius() { return radius; }
	double getAngularVelocity() { return angularVelocity; }

	//setters
	void setAngle(double angle) { this->angle = angle; }
	void setRadius(double radius) { this->radius = radius; }
	void setAngularVelocity(double angularVelocity) { this->angularVelocity = angularVelocity; }
	void addAngularVelocity(double angularAcceleration, double time) { angularVelocity += angularAcceleration * time; }
	
	// Position and Velocity should be accessible by children
	Position position;
	Velocity velocity;
private:
	double radius = 1536000;
	double angularVelocity = 0;
	double angle = 0;
};
