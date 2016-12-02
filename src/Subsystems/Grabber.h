#ifndef Grabber_H
#define Grabber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Grabber: public Subsystem
{
private:
	Talon* grabberLift;
	Talon* roller;
public:
	Grabber();
	void InitDefaultCommand();
	void SetLiftSpeed(float speed);
	void SetRollerSpeed(float speed);
};

#endif
