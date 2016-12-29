#include <Commands/LiftArm.h>

LiftArm::LiftArm()
{
	Requires(CommandBase::grabber.get());
}

// Called just before this Command runs the first time
void LiftArm::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LiftArm::Execute()
{
	Joystick* j = CommandBase::oi->GetStick2();

	CommandBase::grabber->SetPID(
		SmartDashboard::GetNumber("P", 0.0f),
		SmartDashboard::GetNumber("I", 0.0f),
		SmartDashboard::GetNumber("D", 0.0f));

	CommandBase::grabber->SetRollerSpeed(j->GetRawAxis(1));
	CommandBase::grabber->SetLiftSpeed(-j->GetRawAxis(5));
}

// Make this return true when this Command no longer needs to run execute()
bool LiftArm::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LiftArm::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftArm::Interrupted()
{

}
