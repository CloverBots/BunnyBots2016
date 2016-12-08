#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

	Joystick* m_pArmJoystick;

	JoystickButton* m_pAButton;



public:
	OI();
	Joystick* GetArmJoystick();

};

#endif
