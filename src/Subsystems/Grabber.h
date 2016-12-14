#ifndef Grabber_H
#define Grabber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Grabber: public Subsystem
{
private:
	float m_P = 0.25f;
	float m_I = 1.5f;
	float m_D = 0.0f;
	const double m_ENCODER_RATE = 3600;
	Encoder* grabberEncoder;
	PIDController* grabberController;
	Talon* grabberTalon;
	Talon* rollerTalon;
public:
	Grabber();
	void InitDefaultCommand();
	void SetLiftSpeed(float speed);
	void SetRollerSpeed(float speed);
};

#endif
