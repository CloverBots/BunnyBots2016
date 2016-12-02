#include "Grabber.h"
#include "../RobotMap.h"
#include "../Commands/LiftArm.h"

Grabber::Grabber() :
		Subsystem("Grabber")
{
	grabberLift = new Talon(RobotMap::GRABBER_LIFT);
	roller = new Talon(RobotMap::ROLLER);
}

void Grabber::InitDefaultCommand()
{
	SetDefaultCommand(new LiftArm());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
