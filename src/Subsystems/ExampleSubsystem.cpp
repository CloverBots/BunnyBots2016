#include "ExampleSubsystem.h"
#include "../RobotMap.h"

ExampleSubsystem::ExampleSubsystem() :
		Subsystem("ExampleSubsystem")
{
	solenoid = new DoubleSolenoid(0, 1);
}

void ExampleSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void ExampleSubsystem::Extend()
{
	solenoid->Set(DoubleSolenoid::Value::kForward);
}

void ExampleSubsystem::Retract()
{
	solenoid->Set(DoubleSolenoid::Value::kReverse);
}

void ExampleSubsystem::Disable()
{
	solenoid->Set(DoubleSolenoid::Value::kOff);
}

