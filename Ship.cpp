#include "Ship.h"

#include "Physics.h"
#include "Bullet.h"

/******************************************
 * UPDATE
 * Updates the ship on every frame according to the
 * time that has passed and the inputs from the user.
 *****************************************/
void Ship::update(double time, const Earth& earth) {
    Acceleration gravAccel = accelerationFromGravity(position, earth);
    Acceleration shipAccel;
    if (pUI->isUp()) {
        shipAccel.setDirectionMagnitude(getAngle() + pi, thrust);
        
    }
    if (pUI->isLeft())
    {
        addAngularVelocity(-1 * angularAcceleration, time);
    }
    if (pUI->isRight())
    {
        addAngularVelocity(angularAcceleration, time);
    }
    if (pUI->isSpace())
    {
        // Fire Bullets: uses a pipe so that it can send them into
        //  space without needing access to anything in the simulator.
        //  The one way nature of the pipe makes this possible.
        auto pos = rotateMeters(position, 0, (getRadius() + 256000.0 + 1000.0) * 2, getAngle());

        Velocity vel;

        vel.setDirectionMagnitude(getAngle() + pi, velocity.getMagnitude() * 8);

        outgoingBullets.put(std::make_shared<Bullet>(pos, vel, getAngle() + pi / 2.0));
        // use the provided method rotate to get a new position
    }
    velocity.apply(gravAccel + shipAccel, time);
    position.apply(gravAccel + shipAccel, velocity, time);
    setAngle(getAngle() + getAngularVelocity());
}
