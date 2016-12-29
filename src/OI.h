#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Triggers/LeftTrigger.h"

class OI
{
private:

	Joystick* pStick1;
	Joystick* pStick2;

	JoystickButton* aButton;

	//LeftTrigger* leftTrigger;

public:
	OI();
	~OI();

	Joystick* GetStick1();
	Joystick* GetStick2();
};

#endif
