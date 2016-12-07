#ifndef Grabber_H
#define Grabber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Grabber: public Subsystem
{
private:
	Talon* grabberMotor;

	Encoder* m_pArmEncoder;
	PIDController* m_pPIDController;

	const float m_P = 0.25f;
	const float m_I = 1.0f;
	const float m_D = 0.0f;


public:
	Grabber();
	void InitDefaultCommand();

	void SetGrabberSpeed(float speed);
};

#endif
