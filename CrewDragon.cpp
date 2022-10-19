///
/// Author: Jacob Morgan
///

#include "CrewDragon.h"
#include "Fragment.h"

/******************************************
 * EXPLODE
 * Returns the pieces and fragments left when destroyed
 *****************************************/
std::vector<std::shared_ptr<Satellite>> CrewDragon::explode()
{
	return { std::make_shared<CrewDragonCenter>(position, velocity),
			 std::make_shared<CrewDragonLeft>(position, velocity),
			 std::make_shared<CrewDragonRight>(position, velocity),
			 std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity)};
}