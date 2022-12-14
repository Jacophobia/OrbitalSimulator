///
/// Author: Jacob Morgan
///

#include "Sputnik.h"
#include "Fragment.h"

/******************************************
 * EXPLODE
 * Returns the pieces and fragments left when destroyed
 *****************************************/
std::vector<std::shared_ptr<Satellite>> Sputnik::explode()
{
	return { std::make_shared<Fragment>(position, velocity), 
             std::make_shared<Fragment>(position, velocity), 
             std::make_shared<Fragment>(position, velocity), 
             std::make_shared<Fragment>(position, velocity) };
}