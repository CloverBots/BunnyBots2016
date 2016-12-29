#include "nerfshooter.h"
#include "../RobotMap.h"

nerfshooter::nerfshooter() :
		Subsystem("ShooterSubsystem")
{
	fire = new Talon(RobotMap::FIRE_MOTOR);
	firewheels = new Talon(RobotMap::WHEELS_MOTOR);
}

void nerfshooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new OperateShooter());
	fire->Set(0);
	firewheels->Set(0);
}

void nerfshooter::SetWheelSpeed(float speed){
	firewheels->Set(speed * WHEEL_POWER_DOWNSCALE);
}

void nerfshooter::SetShooterSpeed(float speed){
	fire->Set(speed * FIRE_POWER_DOWNSCALE);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
