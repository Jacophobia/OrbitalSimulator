///
/// Author: Jacob Morgan
///

#pragma once

#include "uiDraw.h"        // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "uiInteract.h"    // for INTERFACE
#include <vector>
#include <memory>
#include "Pipe.h"          // for custom pipe data structure

#include "Earth.h"
#include "Satellite.h"
#include "Ship.h"
#include "CrewDragon.h"
#include "StarLink.h"
#include "Sputnik.h"
#include "Hubble.h"
#include "Star.h"


/*********************************************
 * SIMULATOR
 * This class represents the entire simulation. All game actors
 * are maintained in the simulator and the flow of the game is
 * controlled here. 
 *********************************************/
class Simulator
{
public:
    // constructor
    Simulator(const Position& ptUpperRight, const Interface& ui);

    // per-frame operations
    void update();
    void draw();


private:
    // collision
    void handleCollision();
    std::pair<size_t, size_t> checkForCollision();

    // game actors
    Pipe::Out<std::shared_ptr<Satellite>> incomingBullets;
    std::vector<std::shared_ptr<Satellite>> satellites;
    std::vector<std::shared_ptr<Star>> stars;
    Earth earth;

    // simulation variables
    Position ptUpperRight;
    const Interface* pUI;

    // test cases
    friend class TestSimulator;
};

