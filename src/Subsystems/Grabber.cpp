#include "Grabber.h"
#include "../RobotMap.h"

Grabber::Grabber() :
		Subsystem("ExampleSubsystem")
{
	grabberMotor = new Talon(RobotMap::GRABBER_PIVOT_TALON);
	m_pArmLiftMotor = new Talon(RobotMap::ARM_LIFT_MOTOR);

	m_pArmEncoder = new Encoder(RobotMap::ARM_ENCODER_A, RobotMap::ARM_ENCODER_B, false,
			Encoder::EncodingType::k4X);

	m_pPIDController = new PIDController(m_P, m_I, m_D, m_pArmEncoder, m_pArmLiftMotor);
	m_pPIDController->SetContinuous(false);
}

void Grabber::InitDefaultCommand()
{
	SetDefaultCommand(new ControlGrabber());
	// Set the default command for a subsystem here.
}

void Grabber::SetGrabberSpeed(float speed)
{
	grabberMotor->Set(speed);
}

void Grabber::SetArmSpeed(float speed)
{
	m_pPIDController->SetSetpoint(speed);
}






