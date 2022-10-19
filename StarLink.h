///
/// Author: Jacob Morgan
///

#pragma once
#include "Satellite.h"

/******************************************
* STAR LINK
* One Starlink satellite
*****************************************/
class StarLink :
    public Satellite
{
public:
    // constructor
    StarLink(const Position& position, const Velocity& velocity) : Satellite(position, velocity) 
    {
        setRadius(768000);
    }

    // per-frame operation 
    void draw()
    {
        drawStarlink(getPosition(), getAngle());
    }

    // on collision
    std::vector<std::shared_ptr<Satellite>> explode();
};

