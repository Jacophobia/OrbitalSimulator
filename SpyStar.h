#pragma once

#include "Star.h"
namespace SpyStar {
	static int constructorCount = 0;
	static int updateCount = 0;
	static int drawCount = 0;
	static int destroyCount = 0;
	static int resetCount = 0;
}

class StarSpy : public Star
{
public:
	StarSpy() : Star(Position()) 
	{
		SpyStar::constructorCount++;
	}
	StarSpy(const Position& ptUpperRight) : Star(ptUpperRight)
	{
		SpyStar::constructorCount++;
	}
	StarSpy(const StarSpy& rhs) : Star(rhs)
	{
		SpyStar::constructorCount++;
	}
	~StarSpy()
	{
		SpyStar::destroyCount++;
	}
	void update()
	{
		SpyStar::updateCount++;
	}
	void draw()
	{
		SpyStar::drawCount++;
	}
	void reset()
	{
		SpyStar::resetCount++;
	}


	static int getConstructorCount()
	{
		return SpyStar::constructorCount;
	}
	static int getUpdateCount()
	{
		return SpyStar::updateCount;
	}
	static int getDrawCount()
	{
		return SpyStar::drawCount;
	}
	static int getDestroyCount()
	{
		return SpyStar::destroyCount;
	}
	static int getResetCount()
	{
		return SpyStar::resetCount;
	}
	static void resetSpyValues()
	{
		SpyStar::constructorCount = 0;
		SpyStar::updateCount = 0;
		SpyStar::drawCount = 0;
		SpyStar::destroyCount = 0;
	}
};