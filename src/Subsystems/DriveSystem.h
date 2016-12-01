#ifndef DriveSystem_H
#define DriveSystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Talon.h"

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
	void DriveBasic(float Turn, float Strafe, float Throttle);
	void DriveAssist(float Turn, float Strafe, float Throttle);
};

#endif
