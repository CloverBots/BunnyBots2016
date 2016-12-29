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
<<<<<<< HEAD

	const float WHEEL_POWER_DOWNSCALE = 0.25f;
	const float FIRE_POWER_DOWNSCALE = 0.5f;

public:
	nerfshooter();
	void InitDefaultCommand();
	void SetWheelSpeed(float speed);
	void SetShooterSpeed(float speed);
=======
public:
	nerfshooter();
	void InitDefaultCommand();
	void Fire();
	void FireWheels();
	void SetWheelSpeed(float speed);

>>>>>>> origin/master
};

#endif
