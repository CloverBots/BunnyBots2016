#include "DrivePrecise.h"
#include <cmath>

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
	float xLeft;
	float yLeft;
	float leftTrigger;
	float rightTrigger;
	float xRight;
	float yRight;
	float TurnFactor; //Between -1 and 1. -1 is Left, 1 is Right.
	float ThrottleFactor;
	float StrafeFactor;
	int ThrottleDirection;
	int Turn;
	ThrottleStatus throttleStatus;
	TurnStatus turnStatus;
	StrafeStatus strafeStatus;
	Joystick* Controller = CommandBase::oi->Controller;
	switch (driveMode)
	{
	case DriveMode::BASIC:
		xLeft = Controller->GetRawAxis(0);
		yLeft = Controller->GetRawAxis(1);
		leftTrigger = Controller->GetRawAxis(2);
		rightTrigger = Controller->GetRawAxis(3);
		xRight = Controller->GetRawAxis(4);
		yRight = Controller->GetRawAxis(5);

		if (yLeft > 0)
		{
			throttleStatus = ThrottleStatus::FOREWARD;
			ThrottleFactor = std::fabs(yLeft);
		}
		else if (yLeft == 0)
		{
			throttleStatus = ThrottleStatus::CENTER;
			ThrottleFactor = 0;
		}
		else if (yLeft < 0)
		{
			throttleStatus = ThrottleStatus::BACKWARD;
			ThrottleFactor = std::fabs(yLeft);
		}

		if (leftTrigger > rightTrigger)
		{
			turnStatus = TurnStatus::T_LEFT;
			TurnFactor = leftTrigger - rightTrigger;
		}
		else if (rightTrigger > leftTrigger)
		{
			turnStatus = TurnStatus::T_RIGHT;
			TurnFactor = rightTrigger - leftTrigger;
		}
		else if (leftTrigger == rightTrigger)
		{
			turnStatus = TurnStatus::T_CENTER;
			TurnFactor = 0;
		}

		if (xLeft > 0)
		{
			strafeStatus = StrafeStatus::S_RIGHT;
			StrafeFactor = std::fabs(xLeft);
		}
		else if (xLeft == 0)
		{
			strafeStatus = StrafeStatus::S_CENTER;
			StrafeFactor = 0;
		}
		else if (xLeft < 0)
		{
			strafeStatus = StrafeStatus::S_LEFT;
			StrafeFactor = std::fabs(xLeft);
		}

//Thou shalt not cross this line

		if (Controller->GetRawButton(3))
		{
			driveMode = DriveMode::ASSISTED;
		}
	break;
	case DriveMode::ASSISTED:

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
