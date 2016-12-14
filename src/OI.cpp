#include "OI.h"
#include "Triggers/LeftTrigger.h"
#include "Commands/ShootSequence.h"
OI::OI()
{
	joystick2 = new Joystick(2);

	lefttrigger = new LeftTrigger();
	lefttrigger->WhenActive(new ShootSequence());
			// Process operator interface input here.
}
