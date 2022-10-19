///
/// Author: Jacob Morgan
///

#include "Simulator.h"

#include <cassert>

/******************************************
 * GET RANDOM POSITION
 * Returns a random position on the screen.
 *****************************************/
Position getRandomPosition(const Position& ptUpperRight)
{
    Position randomPosition;
    randomPosition.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
    randomPosition.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
    return randomPosition;
}

/******************************************
 * GET RANDOM VELOCITY
 * Returns a random velocity between -3000 and
 * 3000.
 *****************************************/
Velocity getRandomVelocity()
{
    double minimum = -3000.0;
    double maximum = 3000.0;
    return { random(minimum, maximum), random(minimum, maximum) };
}

/******************************************
 * SIMULATOR
 * Constructs a simulation instance. All game actors
 * are instantiated. 
 *****************************************/
Simulator::Simulator(const Position& ptUpperRight, const Interface& ui) :
    ptUpperRight(ptUpperRight), pUI(&ui)
{

    satellites.push_back(std::make_shared<Satellite>(Position(0, 26560000), Velocity(-3880, 0.0)));
    satellites.push_back(std::make_shared<Satellite>(Position(23001634.72, 13280000), Velocity(-1940, 3360.18)));
    satellites.push_back(std::make_shared<Satellite>(Position(23001634.72, -13280000), Velocity(1940, 3360.18)));
    satellites.push_back(std::make_shared<Satellite>(Position(0, -26560000), Velocity(3880, 0.0)));
    satellites.push_back(std::make_shared<Satellite>(Position(-23001634.72, -13280000), Velocity(1940, -3360)));
    satellites.push_back(std::make_shared<Satellite>(Position(-23001634.72, 13280000), Velocity(-1940, -3360)));

    satellites.push_back(std::make_shared<CrewDragon>(Position(0, 8000000), Velocity(-7900, 0)));
    satellites.push_back(std::make_shared<StarLink>(Position(0, -13020000), Velocity(5800, 0)));
    satellites.push_back(std::make_shared<Sputnik>(Position(-36515095.13, 21082000.0), Velocity(2050, 2684)));
    satellites.push_back(std::make_shared<Hubble>(Position(0, 42164000), Velocity(3100, 0)));

    for (int i = 0; i < 200; i++)
        stars.push_back(std::make_shared<Star>(Star(ptUpperRight)));

    auto pipe = Pipe::getPipe<std::shared_ptr<Satellite>>();
    incomingBullets = pipe.second;
    satellites.push_back(std::make_shared<Ship>(Position(-57600000, 57600000), Velocity(0, -2000), &ui, pipe.first));
}

/******************************************
 * UPDATE
 * Conducts all of the per-frame logic of the 
 * entire program.
 *****************************************/
void Simulator::update()
{
    //
    // perform all the game logic
    //

    handleCollision();

    for (auto& satellite : satellites)
        satellite->update(48, earth);

    earth.update();

    for (auto& star : stars)
        star->update();

    while (incomingBullets.size() > 0)
        satellites.push_back(incomingBullets.get());
}

/******************************************
 * DRAW
 * Draws each game actor on the screen in their 
 * current state.
 *****************************************/
void Simulator::draw()
{
    //
    // draw everything
    //
    for (auto& satellite : satellites)
        satellite->draw();

    earth.draw();

    for (auto& star : stars)
        star->draw();
}

/******************************************
 * REMOVE ELEMENT BY INDEX
 * Helper function which removes an element
 * from a vector in o(1) time by index.
 *****************************************/
void removeElementByIndex(std::vector<std::shared_ptr<Satellite>>& list, size_t index)
{
    auto temp = list[list.size() - 1];
    list[list.size() - 1] = list[index];
    list[index] = temp;
    list.pop_back();
}

/******************************************
 * HANDLE COLLISION
 * Handles all collision between game actors.
 *****************************************/
void Simulator::handleCollision()
{
    for (size_t i = 0; i < satellites.size(); i++)
    {
        if (satellites.at(i)->hasFizzled(earth))
        {
            removeElementByIndex(satellites, i);
        }
    }
    auto result = checkForCollision();

    if (result.first == -1 || result.second == -1)
    {
        return;
    }

    auto s1Parts = satellites.at(result.first)->explode();
    auto s2Parts = satellites.at(result.second)->explode();
    
    if (result.first > result.second)
    {
        removeElementByIndex(satellites, result.first);

        removeElementByIndex(satellites, result.second);
    }
    else
    {
        removeElementByIndex(satellites, result.second);

        removeElementByIndex(satellites, result.first);
    }

    for (auto& element : s1Parts)
    {
        satellites.push_back(element);
    }
    for (auto& element : s2Parts)
    {
        satellites.push_back(element);
    }
}

/******************************************
 * CHECK FOR COLLISION
 * Checks to see if two game actors have collided.
 *****************************************/
std::pair<size_t, size_t> Simulator::checkForCollision()
{
    for (size_t i1 = 0; i1 < satellites.size(); i1++)
    {
        for (size_t i2 = i1 + 1; i2 < satellites.size(); i2++)
        {
            if (satellites.at(i1)->hasCollidedWith(*satellites.at(i2)))
            {
                assert(i1 != i2);
                return { i1, i2 };
            }
        }
    }
    return { -1, -1 };
}
