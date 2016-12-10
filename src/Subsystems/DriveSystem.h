#ifndef DriveSystem_H
#define DriveSystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Talon* m_pFrontLeftMotor;
	Talon* m_pRearLeftMotor;
	Talon* m_pFrontRightMotor;
	Talon* m_pRearRightMotor;

	RobotDrive* m_pRobotDrive;

	float m_xSpeed;
	float m_ySpeed;
	float m_rotSpeed;

public:
	DriveSystem();
	~DriveSystem();

	void InitDefaultCommand();

	void Drive(float xSpeed, float ySpeed, float rotSpeed);
	//void SetSafetyEnabled(bool enabled);

	//float GetXSpeed();
	//float GetYSpeed();
	//float GetRotSpeed();

};

#endif
