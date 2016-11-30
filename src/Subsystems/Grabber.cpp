#include "Grabber.h"
#include "../RobotMap.h"

Grabber::Grabber() :
		Subsystem("ExampleSubsystem")
{
	grabberPivot = new Talon;
}

void Grabber::InitDefaultCommand()
{
	SetDefaultCommand(new LoweredPosition());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
