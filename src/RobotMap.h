#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

struct RobotMap
{
	const static u_int32_t
			GRABBER_PIVOT_TALON = 0,
			ARM_LIFT_MOTOR = 3,
			ARM_ENCODER_A = 1,
			ARM_ENCODER_B = 2;

};

#endif
