#include "Fire.h"

Fire::Fire()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void Fire::Initialize()
{
	CommandBase::nerfsubsystem->Fire();
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
