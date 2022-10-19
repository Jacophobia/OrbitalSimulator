#include "Hubble.h"
#include "Parts.h"

/******************************************
 * EXPLODE
 * Returns the pieces and fragments left when destroyed
 *****************************************/
std::vector<std::shared_ptr<Satellite>> Hubble::explode()
{
	return { std::make_shared<HubbleTelescope>(position, velocity),
			 std::make_shared<HubbleComputer>(position, velocity),
			 std::make_shared<HubbleLeft>(position, velocity),
			 std::make_shared<HubbleRight>(position, velocity)};
}