#ifndef nerfshooter_H
#define nerfshooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class nerfshooter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* fire;
	Talon* firewheels;
public:
	nerfshooter();
	void InitDefaultCommand();
	void Fire();
	void FireWheels();
	void SetWheelSpeed(float speed);

};

#endif
