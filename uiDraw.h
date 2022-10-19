/***********************************************************************
 * Header File:
 *    User Interface Draw : put pixels on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This is the code necessary to draw on the screen. We have a collection
 *    of procedural functions here because each draw function does not
 *    retain state. In other words, they are verbs (functions), not nouns
 *    (variables) or a mixture (objects)
 ************************************************************************/

#pragma once

#include <string>     // To display text on the screen
#include <cmath>      // for M_PI, sin() and cos()
#include <algorithm>  // used for min() and max()
#include "position.h" // Where things are drawn
using std::string;
using std::min;
using std::max;

#include <sstream>


#define GL_SILENCE_DEPRECATION

/*************************************************************************
 * GRAPHICS STREAM
 * A graphics stream that behaves much like COUT except on a drawn screen
 *************************************************************************/
class ogstream : public std::ostringstream
{
public:
   ogstream(const Position& pt) : pt(pt) {}
   ~ogstream() { flush(); }; 
   void flush();

   void setPosition(const Position& pt) { flush(); this->pt = pt; }
   ogstream& operator = (const Position& pt)
   {
      setPosition(pt);
      return *this;
   }
private:
   Position pt;
};

/************************************************************************
 * DRAW FRAGMENT
 * Draw a fragment on the screen.
 *   INPUT  pt     The location of the projectile
 *          age    The age in seconds. The younger, the brighter
 *************************************************************************/
void drawFragment(const Position& center, double rotation);

/************************************************************************
 * DRAW PROJECTILE
 * Draw a projectile on the screen at a given point.
 *   INPUT  pt     The location of the projectile
 *************************************************************************/
void drawProjectile(const Position& pt);

/************************************************************************
 * DRAW Crew Dragon
 * Draw a crew dragon on the screen. It consists of three components
 *  INPUT point   The position of the ship
 *        angle   Which direction it is pointed
 *************************************************************************/
void drawCrewDragon(const Position& center, double rotation);
void drawCrewDragonRight(const Position& center, const Position& offset, double rotation);
void drawCrewDragonLeft(const Position& center, const Position& offset, double rotation);
void drawCrewDragonCenter(const Position& center, double rotation);

/************************************************************************
 * DRAW Sputnik
 * Draw the satellite on the screen
 *  INPUT point   The position of the ship
 *        angle   Which direction it is point
 *************************************************************************/
void drawSputnik(const Position& center, double rotation);

/************************************************************************
 * DRAW GPS
 * Draw a GPS satellite on the screen. It consists of three parts
 *  INPUT point   The position of the ship
 *        angle   Which direction it is pointed
 *************************************************************************/
void drawGPS(const Position& center, double rotation);
void drawGPSCenter(const Position& center, double rotation);
void drawGPSRight(const Position& center, const Position& offset, double rotation);
void drawGPSLeft(const Position& center, const Position& offset, double rotation);

/************************************************************************
 * DRAW Hubble
 * Draw a Hubble satellite on the screen. It consists of 4 parts
 *  INPUT point   The position of the ship
 *        angle   Which direction it is ponted
 *************************************************************************/
void drawHubble(const Position& center, double rotation);
void drawHubbleComputer(const Position& center, const Position& offset, double rotation);
void drawHubbleTelescope(const Position& center, const Position& offset, double rotation);
void drawHubbleLeft(const Position& center, const Position& offset, double rotation);
void drawHubbleRight(const Position& center, const Position& offset, double rotation);

/************************************************************************
 * DRAW Starlink
 * Draw a Starlink satellite on the screen. It consists of 2 components
 *  INPUT point   The position of the ship
 *        angle   Which direction it is pointed
 *************************************************************************/
void drawStarlink(const Position& center, double rotation);
void drawStarlinkBody(const Position& center, const Position& offset, double rotation);
void drawStarlinkArray(const Position& center, const Position& offset, double rotation);

/************************************************************************
 * DRAW Ship
 * Draw a spaceship on the screen
 *  INPUT point   The position of the ship
 *        angle   Which direction it is pointed
 *        thrust  Whether the thrusters are on
 *************************************************************************/
void drawShip(const Position& center, double rotation, bool thrust);
/************************************************************************
 * DRAW Earth
 * Draw Earth
 *  INPUT point   The position of the ship
 *        angle   Which direction it is pointed (time of day!)
 *************************************************************************/
void drawEarth(const Position& center, double rotation);

/************************************************************************
* DRAW STAR
* Draw a star
*   INPUT  POINT     The position of the beginning of the star
*          PHASE     The phase of the twinkling
*************************************************************************/
void drawStar(const Position& point, unsigned char phase);

/******************************************************************
 * RANDOM
 * This function generates a random number.  The user specifies
 * The parameters 
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer/double
 ****************************************************************/
int    random(int    min, int    max);
double random(double min, double max);


