#include "SetWheelSpeed.h"

SetWheelSpeed::SetWheelSpeed(float speed) : speed(speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg.
	Requires(CommandBase::nerfsubsystem.get());
}

// Called just before this Command runs the first time
void SetWheelSpeed::Initialize()
{
	CommandBase::nerfsubsystem->SetWheelSpeed(speed);
}

// Called repeatedly when this Command is scheduled to run
void SetWheelSpeed::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetWheelSpeed::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetWheelSpeed::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetWheelSpeed::Interrupted()
{

}
