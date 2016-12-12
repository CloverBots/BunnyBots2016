#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* Controller;
	JoystickButton* ButtonA, ButtonB, ButtonX, ButtonY, ButtonLB, ButtonRB, ButtonSel, ButtonStr, ButtonRS, ButtonLS;

public:
	OI();
	Joystick* GetJoystick();
};

#endif
