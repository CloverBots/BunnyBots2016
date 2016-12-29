#include "OI.h"
#include "Commands/ShootSequence.h"
#include "Commands/StopShooting.h"

OI::OI()
{
	// Process operator interface input here.

	pStick1 = new Joystick(0);
	pStick2 = new Joystick(1);

	aButton = new JoystickButton(pStick2, 1);
	aButton->WhenPressed(new ShootSequence());
	aButton->WhenReleased(new StopShooting());

	//leftTrigger = new LeftTrigger();
	//leftTrigger->WhenActive(new ShootSequence());
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
