#include "SetGrabberSpeed.h"

SetGrabberSpeed::SetGrabberSpeed(float speed) : speed(speed)
{
	Requires (CommandBase::pGrabber.get());

}

// Called just before this Command runs the first time
void SetGrabberSpeed::Initialize()
{
	CommandBase::pGrabber->SetGrabberSpeed(speed);
}

// Called repeatedly when this Command is scheduled to run
void SetGrabberSpeed::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetGrabberSpeed::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetGrabberSpeed::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetGrabberSpeed::Interrupted()
{

}
