#include "Grabber.h"
#include "../RobotMap.h"
#include "../Commands/LiftArm.h"

Grabber::Grabber() :
		Subsystem("Grabber")
{
<<<<<<< HEAD
	grabberTalon = new CANTalon(RobotMap::GRABBER_CAN_TALON);
	rollerTalon = new Talon(RobotMap::ROLLER_TALON);
	grabberSource = new CANPIDSource(grabberTalon, m_ENCODER_RATE);
	grabberController = new PIDController(m_P, m_I, m_D, grabberSource, grabberTalon);
	grabberController->SetOutputRange(m_OUTPUT_RANGE_LOW, m_OUTPUT_RANGE_HIGH);
	lowLimit = new DigitalInput(RobotMap::GRABBER_LOW_LIMIT);
	highLimit = new DigitalInput(RobotMap::GRABBER_HIGH_LIMIT);
=======
	grabberTalon = new Talon(RobotMap::GRABBER_TALON);
	rollerTalon = new Talon(RobotMap::ROLLER_TALON);
	grabberEncoder = new Encoder(RobotMap::GRABBER_ENCODER_A, RobotMap::GRABBER_ENCODER_B,
								false, Encoder::EncodingType::k4X);
	grabberController = new PIDController(m_P, m_I, m_D, grabberEncoder, grabberTalon);
>>>>>>> origin/master
}

void Grabber::InitDefaultCommand()
{
	SetDefaultCommand(new LiftArm());
}

void Grabber::SetLiftSpeed(float speed)
{
<<<<<<< HEAD
	float scaledSpeed = speed * m_SPEED_SCALE;

	if (!lowLimit->Get())
	{
		if (speed <= m_DEADZONE)
		{
			grabberController->SetSetpoint(0.0f);

			if (grabberController->IsEnabled())
				grabberController->Disable();

			grabberTalon->Set(0.0f);
		}
		else
		{
			if (!grabberController->IsEnabled())
				grabberController->Enable();

			grabberController->SetSetpoint(scaledSpeed);
		}
	}
	else
	{
		if (!grabberController->IsEnabled())
			grabberController->Enable();

		grabberController->SetSetpoint(scaledSpeed);
	}

	SmartDashboard::PutNumber("Grabber Speed", grabberController->Get());
=======
	grabberController->SetSetpoint(speed);
>>>>>>> origin/master
}

void Grabber::SetRollerSpeed(float speed)
{
	rollerTalon->Set(speed);
}
<<<<<<< HEAD

void Grabber::SetPIDEnabled(bool enabled)
{
	grabberController->SetSetpoint(0.0f);
	grabberTalon->Set(0.0f);
	grabberController->Reset();

	if (enabled)
		grabberController->Enable();
}

void Grabber::SetPID(float p, float i, float d)
{
	grabberController->SetPID(p, i, d);
}
=======
>>>>>>> origin/master
