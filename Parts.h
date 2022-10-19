#pragma once

#include "Satellite.h"
#include "position.h"
#include "Velocity.h"
#include "Physics.h"
#include "uiDraw.h" // for random

/******************************************
* PART
* One piece of a satellite
*****************************************/
class Part : public Satellite
{
public:
	// update
	Part(const Position& pos, const Velocity& vel) :
		Satellite(Position(), Velocity())
	{
		double angle = random(0.0, 2.0 * 3.141592653589);
		double speed = vel.getMagnitude() + random(5000, 9000);
		Position offset(horizontalComponent(angle, 512000), verticalComponent(angle, 512000));
		position = pos + offset;
		velocity.setDirectionMagnitude(angle, speed);
		setAngularVelocity(random(-1, 1));
		setRadius(896000);
	}

	// per-frame operation
	void draw()
	{
		drawGPSCenter(getPosition(), getAngle());
	}

	// on collision
	std::vector<std::shared_ptr<Satellite>> explode();
private:
};

/******************************************
* GPS LEFT
* The left piece of a GPS satellite
*****************************************/
class GPSLeft : public Part
{
public:
	GPSLeft(const Position& pos, const Velocity& vel) :
		Part(pos, vel)
	{
		setRadius(1024000);
	}
		void draw()
	{
		drawGPSLeft(getPosition(), Position(), getAngle()); // offset
	}
};

/******************************************
* GPS RIGHT
* The RIGHT piece of a GPS satellite
*****************************************/
class GPSRight : public Part
{
public:
	GPSRight(const Position& pos, const Velocity& vel) :
		Part(pos, vel)
	{
		setRadius(1024000);
	}
		void draw()
	{
		drawGPSRight(getPosition(), Position(), getAngle()); // offset
	}
};

class HubbleTelescope : public Part
{
public:
	HubbleTelescope(const Position& pos, const Velocity& vel) :
		Part(pos, vel)
	{
		setRadius(1280000);
	}
		void draw()
	{
		drawHubbleTelescope(getPosition(), Position(), getAngle()); // offset
	}
	std::vector<std::shared_ptr<Satellite>> explode();
};

class HubbleComputer : public Part
{
public:
	HubbleComputer(const Position& pos, const Velocity& vel) :
		Part(pos, vel)
	{
		setRadius(896000);
	}
		void draw()
	{
		drawHubbleComputer(getPosition(), Position(), getAngle()); // offset
	}
	std::vector<std::shared_ptr<Satellite>> explode();
};

class HubbleLeft : public Part
{
public:
	HubbleLeft(const Position& pos, const Velocity& vel) :
		Part(pos, vel)
	{
		setRadius(1024000);
	}
		void draw()
	{
		drawHubbleLeft(getPosition(), Position(), getAngle()); // offset
	}
	std::vector<std::shared_ptr<Satellite>> explode();
};

class HubbleRight : public Part
{
public:
	HubbleRight(const Position& pos, const Velocity& vel) :
		Part(pos, vel)
	{
		setRadius(1024000);
	}
		void draw()
	{
		drawHubbleRight(getPosition(), Position(), getAngle());
	}
	std::vector<std::shared_ptr<Satellite>> explode();
};

class CrewDragonCenter : public Part
{
public:
	CrewDragonCenter(const Position& pos, const Velocity& vel) :
		Part(pos, vel)
	{
		setRadius(768000);
	}
		void draw()
	{
		drawCrewDragonCenter(getPosition(), getAngle());
	}
	std::vector<std::shared_ptr<Satellite>> explode();
};

class CrewDragonLeft : public Part
{
public:
	CrewDragonLeft(const Position& pos, const Velocity& vel) :
		Part(pos, vel)
	{
		setRadius(768000);
	}
		void draw()
	{
		drawCrewDragonLeft(getPosition(), Position(), getAngle()); // offset
	}
	std::vector<std::shared_ptr<Satellite>> explode();
};

class CrewDragonRight : public Part
{
public:
	CrewDragonRight(const Position& pos, const Velocity& vel) :
		Part(pos, vel)
	{
		setRadius(768000);
	}
		void draw()
	{
		drawCrewDragonRight(getPosition(), Position(), getAngle()); // offset
	}
	std::vector<std::shared_ptr<Satellite>> explode();
};

class StarlinkBody : public Part
{
public:
	StarlinkBody(const Position& pos, const Velocity& vel) :
		Part(pos, vel)
	{
		setRadius(256000);
	}
		void draw()
	{
		drawStarlinkBody(getPosition(), Position(), getAngle()); // offset
	}
	std::vector<std::shared_ptr<Satellite>> explode();
};

class StarlinkArray : public Part
{
public:
	StarlinkArray(const Position& pos, const Velocity& vel) :
		Part(pos, vel)
	{
		setRadius(512000);
	}
		void draw()
	{
		drawStarlinkArray(getPosition(), Position(), getAngle()); // offset
	}
	std::vector<std::shared_ptr<Satellite>> explode();
};