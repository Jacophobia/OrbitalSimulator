///
/// Author: Jacob Morgan
///

#pragma once
#include "Satellite.h"

/******************************************
* CREW DRAGON
* One Crew Dragon Satellite
*****************************************/
class CrewDragon :
    public Satellite
{
public:
    // constructor
    CrewDragon(const Position& position, const Velocity& velocity) : Satellite(position, velocity) 
    {
        setRadius(896000);
    }
    // per-frame operations
    void draw() override
    {
        drawCrewDragon(getPosition(), getAngle());
    }
    // on collision
    std::vector<std::shared_ptr<Satellite>> explode() override;
};

