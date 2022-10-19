///
/// Author: Jacob Morgan
///

#pragma once
#include "Satellite.h"

/******************************************
* HUBBLE
* One Hubble Satellite
*****************************************/
class Hubble :
    public Satellite
{
public:
    // constructor
    Hubble(const Position& position, const Velocity& velocity) : Satellite(position, velocity) 
    {
        setRadius(1280000);
    }

    // per-frame operation
    void draw() override
    {
        drawHubble(getPosition(), getAngle());
    }

    // on collision
    std::vector<std::shared_ptr<Satellite>> explode() override;
};

