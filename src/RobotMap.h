#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

struct RobotMap
{
	static const uint32_t
		LEFT_FRONT_TALON = 0,
		LEFT_REAR_TALON = 1,
		RIGHT_FRONT_TALON = 2,
		RIGHT_REAR_TALON = 3,
		LEFT_JOYSTICK = 4;
};

const int RightFront = 1;



#endif
