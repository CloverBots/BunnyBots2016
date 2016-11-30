#ifndef Grabber_H
#define Grabber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Grabber: public Subsystem
{
private:
	Talon* grabberMotor;


public:
	Grabber();
	void InitDefaultCommand();
};

#endif
