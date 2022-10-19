///
/// Author: Jacob Morgan
///

#pragma once

#include "Simulator.h"

#include <memory>

#include "UnitTest.h"
#include "SpySatellite.h"
#include "SpyStar.h"
#include "position.h"

class TestSimulator {
public:
	void run()
	{
		// clear current report
		reset_report();
		
		// run tests
		test_constructor();
		test_update();
		test_checkForCollision();
		test_draw();
		test_destructor();


		// print off a report of what happened to the console
		print_report();
	}
private:
	std::allocator<Simulator> alloc;
	const Position ptUpperRight = Position(100.0, 100.0);
	const Interface ui;

	void test_constructor()
	{
		// setup
		Simulator * simulator = alloc.allocate(1);
		// exercise
		alloc.construct(simulator, ptUpperRight, ui);
		// verify
		assert(simulator->satellites.size(), 11);
		assert(simulator->stars.size(), 200);
		// teardown
		teardownStandardFixture(simulator);
	}
	void test_update()
	{
		// setup
		Simulator simulator(ptUpperRight, ui);
		setupStandardFixture(simulator);
		// exercise
		simulator.update();
		// verify
		assert(StarSpy::getConstructorCount(), 0);
		assert(StarSpy::getDrawCount(), 0);
		assert(StarSpy::getUpdateCount(), 5);
		assert(StarSpy::getDestroyCount(), 0);
		assert(SatelliteSpy::getConstructorCount(), 0);
		assert(SatelliteSpy::getDrawCount(), 0);
		assert(SatelliteSpy::getUpdateCount(), 5);
		assert(SatelliteSpy::getDestroyCount(), 0);
		// teardown
	}
	void test_checkForCollision()
	{
		// setup
		Simulator simulator(ptUpperRight, ui);
		simulator.satellites.clear();
		simulator.satellites.push_back(std::make_shared<SatelliteSpy>(ptUpperRight, Velocity()));
		simulator.satellites.push_back(std::make_shared<SatelliteSpy>(ptUpperRight, Velocity()));
		simulator.stars.push_back(std::make_shared<StarSpy>(StarSpy()));
		SatelliteSpy::resetSpyValues();
		StarSpy::resetSpyValues();
		// exercise
		auto result = simulator.checkForCollision();
		// verify
		double x1 = simulator.satellites.at(result.first)->getPosition().getMetersX();
		double x2 = simulator.satellites.at(result.second)->getPosition().getMetersX();
		double y1 = simulator.satellites.at(result.first)->getPosition().getMetersY();
		double y2 = simulator.satellites.at(result.second)->getPosition().getMetersY();
		assert(x1, x2);
		assert(y1, y2);
		assert(result.first, 0);
		assert(result.second, 1);
		assert(simulator.satellites.size(), 2);
		assert(StarSpy::getConstructorCount(), 0);
		assert(StarSpy::getDrawCount(), 0);
		assert(StarSpy::getUpdateCount(), 0);
		assert(StarSpy::getDestroyCount(), 0);
		assert(SatelliteSpy::getConstructorCount(), 0);
		assert(SatelliteSpy::getDrawCount(), 0);
		assert(SatelliteSpy::getUpdateCount(), 0);
		assert(SatelliteSpy::getDestroyCount(), 0);
		// teardown
	}
	void test_draw()
	{
		// setup
		Simulator simulator(ptUpperRight, ui);
		setupStandardFixture(simulator);
		// exercise
		simulator.draw();
		// verify
		assert(StarSpy::getConstructorCount(), 0);
		assert(StarSpy::getDrawCount(), 5);
		assert(StarSpy::getUpdateCount(), 0);
		assert(StarSpy::getDestroyCount(), 0);
		assert(SatelliteSpy::getConstructorCount(), 0);
		assert(SatelliteSpy::getDrawCount(), 5);
		assert(SatelliteSpy::getUpdateCount(), 0);
		assert(SatelliteSpy::getDestroyCount(), 0);
		// teardown

	}
	void test_destructor()
	{
		// setup
		Simulator* simulator = alloc.allocate(1);
		alloc.construct(simulator, ptUpperRight, ui);
		setupStandardFixture(*simulator);
		// exercise
		alloc.destroy(simulator);
		// verify
		assert(simulator->satellites.size(), 0);
		assert(simulator->stars.size(), 0);
		assert(StarSpy::getConstructorCount(), 0);
		assert(StarSpy::getDrawCount(), 0);
		assert(StarSpy::getUpdateCount(), 0);
		assert(StarSpy::getDestroyCount(), 5);
		assert(SatelliteSpy::getConstructorCount(), 0);
		assert(SatelliteSpy::getDrawCount(), 0);
		assert(SatelliteSpy::getUpdateCount(), 0);
		assert(SatelliteSpy::getDestroyCount(), 5);
		// teardown
		teardownStandardFixture(simulator);

	}
	void setupStandardFixture(Simulator& simulator)
	{
		simulator.satellites.clear();
		for (int i = 0; i < 5; i++)
		{
			simulator.satellites.push_back(std::make_shared<SatelliteSpy>(i));
			simulator.stars.push_back(std::make_shared<StarSpy>());
		}
		SatelliteSpy::resetSpyValues();
		StarSpy::resetSpyValues();
	}
	void teardownStandardFixture(Simulator* simulator)
	{
		alloc.destroy(simulator);
		alloc.deallocate(simulator, 1);
	}
};