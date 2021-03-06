#include "DelayCommand.h"

DelayCommand::DelayCommand(float time) : time(time)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DelayCommand::Initialize()
{
	Wait(time);
}

// Called repeatedly when this Command is scheduled to run
void DelayCommand::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool DelayCommand::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DelayCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DelayCommand::Interrupted()
{

}
