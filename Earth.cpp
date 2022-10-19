#include "Earth.h"

#include "Physics.h"

/******************************************
 * UPDATE
 * Updates the angle of the earth every frame
 * according to the speed of its rotation.
 *****************************************/
void Earth::update()
{
	angle += speedOfRotation;
}
