///
/// Author: Jacob Morgan
///

#pragma once

#include "Satellite.h"
#include "Fragment.h"

/******************************************
* SPUTNIK
* One Sputnik Satellite
*****************************************/
class Sputnik :
    public Satellite
{
public:
    // constructor
    Sputnik(const Position& position, const Velocity& velocity) : Satellite(position, velocity) {
        setRadius(512000);
    }

    // per-frame operation
    void draw() {
        drawSputnik(getPosition(), getAngle());
    }

    // on collision
    std::vector<std::shared_ptr<Satellite>> explode();
};

