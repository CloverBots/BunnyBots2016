#include "LoweredPosition.h"

LoweredPosition::LoweredPosition()
{
	Requires (Grabber);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void LoweredPosition::Initialize()
{
	//set speed to joystick value
}

// Called repeatedly when this Command is scheduled to run
void LoweredPosition::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LoweredPosition::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LoweredPosition::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LoweredPosition::Interrupted()
{

}
