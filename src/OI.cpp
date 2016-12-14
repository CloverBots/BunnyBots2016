#include "OI.h"

OI::OI()
{
	// Process operator interface input here.

	pStick1 = new Joystick(0);
	pStick2 = new Joystick(1);

}

OI::~OI()
{

	delete pStick1;
	delete pStick2;

}

Joystick* OI::GetStick1()
{
	return pStick1;
}

Joystick* OI::GetStick2()
{
	return pStick2;
}
