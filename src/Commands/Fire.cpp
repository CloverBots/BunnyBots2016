#include "Fire.h"

Fire::Fire(float speed) : m_speed(speed)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(CommandBase::nerfsubsystem.get());
}

// Called just before this Command runs the first time
void Fire::Initialize()
{
	CommandBase::nerfsubsystem->SetShooterSpeed(m_speed);
}

// Called repeatedly when this Command is scheduled to run
void Fire::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool Fire::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void Fire::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Fire::Interrupted()
{

}
