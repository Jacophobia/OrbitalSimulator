#include "Parts.h"

#include "Fragment.h"

/******************************************
 * EXPLODE
 * Returns the pieces and fragments left when destroyed
 *****************************************/
std::vector<std::shared_ptr<Satellite>> Part::explode()
{
	return { std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity) };
}
std::vector<std::shared_ptr<Satellite>> HubbleTelescope::explode()
{
	return { std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity) };
}
std::vector<std::shared_ptr<Satellite>> HubbleComputer::explode()
{
	return { std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity) };
}
std::vector<std::shared_ptr<Satellite>> HubbleLeft::explode()
{
	return { std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity) };
}
std::vector<std::shared_ptr<Satellite>> HubbleRight::explode()
{
	return { std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity) };
}
std::vector<std::shared_ptr<Satellite>> CrewDragonCenter::explode()
{
	return { std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity) };
}
std::vector<std::shared_ptr<Satellite>> CrewDragonRight::explode()
{
	return { std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity) };
}
std::vector<std::shared_ptr<Satellite>> CrewDragonLeft::explode()
{
	return { std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity) };
}
std::vector<std::shared_ptr<Satellite>> StarlinkBody::explode()
{
	return { std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity) };
}
std::vector<std::shared_ptr<Satellite>> StarlinkArray::explode()
{
	return { std::make_shared<Fragment>(position, velocity),
			 std::make_shared<Fragment>(position, velocity) };
}
