#include "ControlGrabber.h"

ControlGrabber::ControlGrabber()
{
	Requires(CommandBase::pGrabber.get());
	// Use Requires() here to declare subsystem dependencies

}

// Called just before this Command runs the first time
void ControlGrabber::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlGrabber::Execute()
{
	CommandBase::pGrabber->SetArmSpeed(CommandBase::oi->GetArmJoystick()->GetRawAxis(1));

/*
	 if(m_pAButton WhenPressed)
	{
		CommandBase::pGrabber->
	}
*/
}

// Make this return true when this Command no longer needs to run execute()
bool ControlGrabber::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlGrabber::End()
{
	CommandBase::pGrabber->SetArmSpeed(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlGrabber::Interrupted()
{

}
