#ifndef DriveSystem_H
#define DriveSystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Talon.h"
#include "Commands/DrivePrecise.h"

class DriveSystem: public Subsystem
{
private:
	Talon* m_pLeftFrontTalon;
	Talon* m_pRightFrontTalon;
	Talon* m_pLeftRearTalon;
	Talon* m_pRightRearTalon;
public:
	DriveSystem();
	void InitDefaultCommand();
	void DriveBasic(float TurnRaw, float StrafeRaw, float ThrottleRaw, int TurnDir, int StrafeDir, int ThrottleDir);
	void DriveAssist(float Turn, float Strafe, float Throttle);
};

#endif
