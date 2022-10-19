///
/// Author: Jacob Morgan
///

#pragma once

#include "UnitTest.h"

#include "Vector.h"

class TestVector {
public:
	void run() 
	{
		// clear current report
		reset_report();

		// run tests
		test_getX();
		test_getY();
		test_setX();
		test_setY();
		test_addX();
		test_addY();
		test_setComponents();
		test_setDirectionMagnitude();

		// print off a report of what happened to the console
		print_report();
	}
private:
	void test_getX()
	{
		// setup
		Vector vector;
		vector.xComponent = 5;
		vector.yComponent = 99; // can be any input
		// exercise
		auto result = vector.getX();
		// verify
		assert(result, 5.0);
		assert(vector.xComponent, 5.0); // verify that the state of the object 
		assert(vector.yComponent, 99.0);//  wasn't changed
	}   // teardown
	void test_getY()
	{
		// setup
		Vector vector;
		vector.xComponent = 99;
		vector.yComponent = 5; // can be any input
		// exercise
		auto result = vector.getY();
		// verify
		assert(result, 5.0);
		assert(vector.yComponent, 5.0); // verify that the state of the object 
		assert(vector.xComponent, 99.0);//  wasn't changed
	}   // teardown
	void test_setX()
	{
		// setup
		Vector vector;
		vector.xComponent = 99;
		vector.yComponent = 99; // can be any input
		// exercise
		vector.setX(5);
		// verify
		assert(vector.xComponent, 5.0);
		assert(vector.yComponent, 99.0);
	}   // teardown
	void test_setY()
	{
		// setup
		Vector vector;
		vector.xComponent = 99;
		vector.yComponent = 99; // can be any input
		// exercise
		vector.setY(5);
		// verify
		assert(vector.yComponent, 5.0);
		assert(vector.xComponent, 99.0);
	}   // teardown
	void test_addX()
	{
		// setup
		Vector vector;
		vector.xComponent = 5;
		vector.yComponent = 99; // can be any input
		// exercise
		vector.addX(5);
		// verify
		assert(vector.xComponent, 10.0);
		assert(vector.yComponent, 99.0);
	}   // teardown
	void test_addY()
	{
		// setup
		Vector vector;
		vector.yComponent = 5;
		vector.xComponent = 99; // can be any input
		// exercise
		vector.addY(5);
		// verify
		assert(vector.yComponent, 10.0);
		assert(vector.xComponent, 99.0);
	}   // teardown
	void test_setComponents()
	{
		// setup
		Vector vector;
		vector.yComponent = 99;
		vector.xComponent = 99; // can be any input
		// exercise
		vector.setComponents(5,5);
		// verify
		assert(vector.yComponent, 5.0);
		assert(vector.xComponent, 5.0);
	}   // teardown
	void test_setDirectionMagnitude()
	{
		// setup
		Vector vector;
		vector.yComponent = 99;
		vector.xComponent = 99; // can be any input
		// exercise
		vector.setDirectionMagnitude(10, 10);
		// verify
		relative_assert(vector.yComponent, 8.39071529076, 0.000001);
		relative_assert(vector.xComponent, 5.44021110889, 0.000001);
	}   // teardown
};