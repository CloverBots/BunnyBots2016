#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Triggers/LeftTrigger.h"

class OI
{
private:

public:
	OI();
	Joystick* joystick2;
	LeftTrigger* lefttrigger;
};

#endif
