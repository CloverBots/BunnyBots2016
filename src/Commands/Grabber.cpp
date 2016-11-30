#include "Grabber.h"

Grabber::Grabber()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void Grabber::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Grabber::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool Grabber::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Grabber::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Grabber::Interrupted()
{

}
