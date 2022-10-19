/*
 * Author: Jacob Morgan
 * Since: 06/17/2022
 */

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

static double testsCompleted = 0.0;
static double testsPassed = 0.0;
static std::vector<std::tuple<std::string, std::string, unsigned int>> report;

template <class T, class V>
static void __assert_eq(T val1, V val2, std::string file, unsigned int line)
{
	testsCompleted += 1.0;
	if (val1 != val2)
	{
		std::string notEqualMessage = std::to_string(val1).append(" != ").append(std::to_string(val2));
		report.push_back(std::make_tuple(notEqualMessage, file, line));
		return;
	}
	testsPassed += 1.0;
}

static void __assert_about_eq(double val1, double val2, double precision, std::string file, unsigned int line)
{
	testsCompleted += 1.0;
	if (abs(val1 - val2) > precision) __assert_eq(val1, val2, file, line);
	testsPassed += 1.0;
}

static void __print_report(std::string testName)
{
	if (report.size() == 0)
	{
		std::cout << "\tAll tests completed successfully for " << testName << std::endl;
		return;
	}
	auto lastValue = report.front();
	std::cout << "Failure at " << std::get<1>(lastValue) << std::endl;
	for (auto& value : report)
	{
		if (std::get<1>(lastValue) != std::get<1>(value))
		{
			std::cout << "Failed assertion(s) at: " << std::get<1>(value) << std::endl;
			lastValue = value;
		}
		std::cout << "\tFailed assertion at line " << std::get<2>(value) << ". Cause: " << std::get<0>(value) << std::endl;
	}
	std::cout << testsCompleted << " tests completed, " << (testsPassed / testsCompleted) * 100.0 << "% passed" << std::endl;
}

static void reset_report()
{
	testsCompleted = 0.0;
	testsPassed = 0.0;
	report.clear();
}

#undef assert
#undef relative_assert
#undef print_report

#ifndef NDEBUG
#define assert(val1, val2) __assert_eq(val1, val2, __FILE__, (unsigned)__LINE__);
#define relative_assert(val1, val2, precision) __assert_about_eq((double)val1, (double)val2, (double)precision, __FILE__, (unsigned)__LINE__);
#define print_report() __print_report(typeid(*this).name());
#else
#define assert(val1, val2) ((void)0)
#define relative_assert(val1, val2, precision) ((void)0)
#define print_report() ((void)0)
#endif