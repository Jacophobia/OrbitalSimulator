#pragma once

#include "Satellite.h"

namespace SpySatellite {
	static int constructorCount = 0;
	static int updateCount = 0;
	static int drawCount = 0;
	static int destroyCount = 0;
	static int resetCount = 0;
}

class SatelliteSpy : public Satellite
{
public:
	SatelliteSpy() : Satellite(Position(), Velocity()) 
	{
		SpySatellite::constructorCount++;
	}
	SatelliteSpy(const Position& position, const Velocity& velocity) : Satellite(position, velocity)
	{
		SpySatellite::constructorCount++;
	}
	SatelliteSpy(int num) : Satellite(Position((num + 1) * (num + 1) * 2500001 + 6378000, (num + 1) * (num + 1) * 2500001 + 6378000), Velocity()) {}
	~SatelliteSpy()
	{
		SpySatellite::destroyCount++;
	}
	void update(double time, const Earth& earth)
	{
		SpySatellite::updateCount++;
	}
	void draw()
	{
		SpySatellite::drawCount++;
	}
	void reset()
	{
		SpySatellite::resetCount++;
	}


	static int getConstructorCount()
	{
		return SpySatellite::constructorCount;
	}
	static int getUpdateCount()
	{
		return SpySatellite::updateCount;
	}
	static int getDrawCount()
	{
		return SpySatellite::drawCount;
	}
	static int getDestroyCount()
	{
		return SpySatellite::destroyCount;
	}
	static int getResetCount()
	{
		return SpySatellite::resetCount;
	}
	static void resetSpyValues()
	{
		SpySatellite::constructorCount = 0;
		SpySatellite::updateCount = 0;
		SpySatellite::drawCount = 0;
		SpySatellite::destroyCount = 0;
	}
};