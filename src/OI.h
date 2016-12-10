#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

	Joystick* pStick1;
	Joystick* pStick2;

public:
	OI();
	~OI();

	Joystick* GetStick1();
	Joystick* GetStick2();
};

#endif
