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
		LEFT_JOYSTICK = 4,
		GRABBER_TALON = 0,
		ROLLER_TALON = 1,
		GRABBER_ENCODER_A = 0,
		GRABBER_ENCODER_B = 0,
		FIRE_MOTOR = 5,
		WHEELS_MOTOR = 6;
};

#endif
