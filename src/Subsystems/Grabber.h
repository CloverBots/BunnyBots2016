#ifndef Grabber_H
#define Grabber_H

#include "Commands/Subsystem.h"
<<<<<<< HEAD
#include "../CANPIDSource.h"
#include "WPILib.h"

class Grabber : public Subsystem
{
private:
	float m_P = 1.5f;//3.0f;//1.0f;
	float m_I = 0.75f;//0.5f;//0.75f;
	float m_D = 0.0f;//2.5f;//2.5f;

	const double m_ENCODER_RATE = 1400;
	const float m_SPEED_SCALE = 0.05f;
	const float m_OUTPUT_RANGE_HIGH = 0.5f;
	const float m_OUTPUT_RANGE_LOW = -0.05f;
	const float m_DEADZONE = 0.05f;

	CANPIDSource* grabberSource;
	PIDController* grabberController;

	//Talon* grabberTalon;
	CANTalon* grabberTalon;
	Talon* rollerTalon;

	DigitalInput* lowLimit;
	DigitalInput* highLimit;
=======
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
>>>>>>> origin/master
public:
	Grabber();
	void InitDefaultCommand();
	void SetLiftSpeed(float speed);
	void SetRollerSpeed(float speed);
<<<<<<< HEAD

	void SetPIDEnabled(bool enabled);
	void SetPID(float p, float i, float d);
=======
>>>>>>> origin/master
};

#endif
