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
	driveMode = DriveMode::BASIC;
	SmartDashboard::PutString("Drive Mode", "Basic");

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
	int Throttle;
	int Turn;
	int Strafe;
	Joystick* Controller = CommandBase::oi->GetJoystick();
	switch (driveMode)
	{
	case DriveMode::BASIC:
		xLeft = Controller->GetRawAxis(0);
		yLeft = Controller->GetRawAxis(1);
		leftTrigger = Controller->GetRawAxis(2);
		rightTrigger = Controller->GetRawAxis(3);
		xRight = Controller->GetRawAxis(4);
		yRight = Controller->GetRawAxis(5);

		if (yLeft < 0)
		{
			Throttle = 0;
			ThrottleFactor = std::fabs(yLeft);
		}
		else if (yLeft == 0)
		{
			Throttle = 1;
			ThrottleFactor = 0;
		}
		else if (yLeft > 0)
		{
			Throttle = 2;
			ThrottleFactor = std::fabs(yLeft);
		}

		if (leftTrigger > rightTrigger)
		{
			Turn = 1;
			TurnFactor = leftTrigger - rightTrigger;
		}
		else if (rightTrigger > leftTrigger)
		{
			Turn = 0;
			TurnFactor = rightTrigger - leftTrigger;
		}
		else if (leftTrigger == rightTrigger)
		{
			Turn = 2;
			TurnFactor = 0;
		}

		if (xLeft > 0)
		{
			Strafe = 2;
			StrafeFactor = std::fabs(xLeft);
		}
		else if (xLeft == 0)
		{
			Strafe = 1;
			StrafeFactor = 0;
		}
		else if (xLeft < 0)
		{
			Strafe = 0;
			StrafeFactor = std::fabs(xLeft);
		}
		driveSystem->DriveBasic(TurnFactor, StrafeFactor, ThrottleFactor, Turn, Strafe, Throttle);

//Thou shalt not cross this line

		if (Controller->GetRawButton(3))
		{
			driveMode = DriveMode::CLASSIC;
			SmartDashboard::PutString("Drive Mode", "Classic");
		}
	break;

	case DriveMode::CLASSIC:
		xLeft = Controller->GetRawAxis(0);
		yLeft = Controller->GetRawAxis(1);
		leftTrigger = Controller->GetRawAxis(2);
		rightTrigger = Controller->GetRawAxis(3);
		xRight = Controller->GetRawAxis(4);
		yRight = Controller->GetRawAxis(5);

		if (yLeft < 0)
		{
			Throttle = 0;
			ThrottleFactor = std::fabs(yLeft);
		}
		else if (yLeft == 0)
		{
			Throttle = 1;
			ThrottleFactor = 0;
		}
		else if (yLeft > 0)
		{
			Throttle = 2;
			ThrottleFactor = std::fabs(yLeft);
		}

		if (xRight < 0)
		{
			Turn = 0;
			TurnFactor = std::fabs(xRight);
		}
		else if (xRight > 0)
		{
			Turn = 2;
			TurnFactor = std::fabs(xRight);
		}
		else if (xRight==0)
		{
			Turn = 1;
			TurnFactor = 0;
		}

		if (xLeft > 0)
		{
			Strafe = 2;
			StrafeFactor = std::fabs(xLeft);
		}
		else if (xLeft == 0)
		{
			Strafe = 1;
			StrafeFactor = 0;
		}
		else if (xLeft < 0)
		{
			Strafe = 0;
			StrafeFactor = std::fabs(xLeft);
		}
		driveSystem->DriveBasic(TurnFactor, StrafeFactor, ThrottleFactor, Turn, Strafe, Throttle);

//Thou shalt not cross this line either
		if (Controller->GetRawButton(3))
		{
			driveMode = DriveMode::BASIC;
			SmartDashboard::PutString("Drive Mode", "Basic");
		}
	break;
	//case DriveMode::ASSISTED:

//Thou knowest what is up
		//if (Controller->GetRawButton(3))
		//{
			//driveMode = DriveMode::BASIC;
		//}
	//break;
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
