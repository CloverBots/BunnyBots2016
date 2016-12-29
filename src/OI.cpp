#include "OI.h"
#include "Commands/ShootSequence.h"
#include "Commands/StopShooting.h"

OI::OI()
{
	// Process operator interface input here.

	pStick1 = new Joystick(0);
	pStick2 = new Joystick(1);

<<<<<<< HEAD
	aButton = new JoystickButton(pStick2, 1);
	aButton->WhenPressed(new ShootSequence());
	aButton->WhenReleased(new StopShooting());

	//leftTrigger = new LeftTrigger();
	//leftTrigger->WhenActive(new ShootSequence());
=======
>>>>>>> origin/master
}

OI::~OI()
{
<<<<<<< HEAD
	delete pStick1;
	delete pStick2;
=======

	delete pStick1;
	delete pStick2;

>>>>>>> origin/master
}

Joystick* OI::GetStick1()
{
	return pStick1;
}

Joystick* OI::GetStick2()
{
	return pStick2;
}
