#pragma once

#include "Pipe.h" // for custom pipe data structure

#include "Satellite.h"
#include "uiInteract.h"

/******************************************
* SHIP
* One Player-controlled Spaceship
*****************************************/
class Ship :
    public Satellite
{
public:
    // constructor
    Ship(const Position& position, const Velocity& velocity, const Interface* pUI, Pipe::In<std::shared_ptr<Satellite>> outgoingBullets) :
        Satellite(position, velocity), pUI(pUI), outgoingBullets(outgoingBullets)
    {
        setRadius(1280000);
    }

    // per-frame operation
    void draw() {
        drawShip(getPosition(), getAngle(), pUI->isUp());
    }
    void update(double time, const Earth& earth);
private:
    const Interface* pUI;
    const double thrust = 1.0;
    const double angularAcceleration = 0.00003;
    Pipe::In<std::shared_ptr<Satellite>> outgoingBullets;
};

