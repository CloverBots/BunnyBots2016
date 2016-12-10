#include "JoystickDrive.h"

JoystickDrive::JoystickDrive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::pDriveSystem);
}

// Called just before this Command runs the first time
void JoystickDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void JoystickDrive::Execute()
{
	CommandBase::pDriveSystem->Drive(
		CommandBase::oi->GetStick1()->GetRawAxis(0),
		CommandBase::oi->GetStick1()->GetRawAxis(1),
		CommandBase::oi->GetStick1()->GetRawAxis(4));
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void JoystickDrive::End()
{
	CommandBase::pDriveSystem->Drive(0.0f, 0.0f, 0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickDrive::Interrupted()
{

}
