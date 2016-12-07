#include "Grabber.h"
#include "../RobotMap.h"
#include "../Commands/LiftArm.h"

Grabber::Grabber() :
		Subsystem("Grabber")
{
	grabberTalon = new Talon(RobotMap::GRABBER_TALON);
	rollerTalon = new Talon(RobotMap::ROLLER_TALON);
	grabberEncoder = new Encoder(RobotMap::GRABBER_ENCODER_A, RobotMap::GRABBER_ENCODER_B,
								false, Encoder::EncodingType::k4X);
	grabberController = new PIDController(m_P, m_I, m_D, grabberEncoder, grabberTalon);
}

void Grabber::InitDefaultCommand()
{
	SetDefaultCommand(new LiftArm());
}

void Grabber::SetLiftSpeed(float speed)
{
	grabberController->SetSetpoint(speed);
}

void Grabber::SetRollerSpeed(float speed)
{
	rollerTalon->Set(speed);
}
