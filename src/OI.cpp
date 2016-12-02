#include "OI.h"

OI::OI()
{
	accessoryController = new Joystick(2);
}

Joystick* OI::GetJoystick()
{
	return accessoryController;
}
