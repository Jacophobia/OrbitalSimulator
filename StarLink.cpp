#include "StarLink.h"
#include "Fragment.h"

/******************************************
 * EXPLODE
 * Returns the pieces and fragments left when destroyed
 *****************************************/
std::vector<std::shared_ptr<Satellite>> StarLink::explode()
{
	return { std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity),
			 std::make_shared<StarlinkBody>(position, velocity),
			 std::make_shared<StarlinkArray>(position, velocity) };
}
