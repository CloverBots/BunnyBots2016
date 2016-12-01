#include "DrivePrecise.h"

DrivePrecise::DrivePrecise()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(CommandBase::driveSystem.get());
}

// Called just before this Command runs the first time
void DrivePrecise::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DrivePrecise::Execute()
{
	double xLeft;
	double yLeft;
	double leftTrigger;
	double rightTrigger;
	double xRight;
	double yRight;
	double TurnStatus; //Between -1 and 1. -1 is Left, 1 is Right.
	double ThrottleStatus;
	double StrafeStatus;
	Joystick* Controller = CommandBase::oi->Controller;
	switch (driveMode)
	{
	case DriveMode::BASIC:
			xLeft = Controller->GetRawAxis(0);
			yLeft = Controller->GetRawAxis(1);
			leftTrigger = -(Controller->GetRawAxis(2));
			rightTrigger = Controller->GetRawAxis(3);

			TurnStatus = leftTrigger + rightTrigger;
			StrafeStatus = xLeft;
			ThrottleStatus = yLeft;
			CommandBase::driveSystem->DriveBasic(TurnStatus, StrafeStatus, ThrottleStatus);
		if (Controller->GetRawButton(3)) {
			driveMode = DriveMode::ASSISTED;
		}
		break;
	case DriveMode::ASSISTED:
		xLeft = Controller->GetRawAxis(0);
		yLeft = Controller->GetRawAxis(1);
		leftTrigger = -(Controller->GetRawAxis(2));
		rightTrigger = Controller->GetRawAxis(3);
		TurnStatus = leftTrigger + rightTrigger;
		StrafeStatus = xLeft;
		ThrottleStatus = yLeft;
		CommandBase::driveSystem->DriveAssist(TurnStatus, StrafeStatus, ThrottleStatus);
		if (Controller->GetRawButton(3))
		{
			driveMode = DriveMode::BASIC;
		}

		break;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DrivePrecise::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DrivePrecise::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrivePrecise::Interrupted()
{

}
