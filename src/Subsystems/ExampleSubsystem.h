#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ExampleSubsystem: public Subsystem
{
private:

	DoubleSolenoid* solenoid;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ExampleSubsystem();

	void InitDefaultCommand();
	void Extend();
	void Retract();
	void Disable();
};

#endif
