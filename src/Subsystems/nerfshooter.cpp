#include "nerfshooter.h"
#include "../RobotMap.h"

nerfshooter::nerfshooter() :
		Subsystem("ShooterSubsystem")
{
	fire = new Talon(fire_motor);
	firewheels = new Talon(wheels_motor);
}

void nerfshooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new OperateShooter());
	fire->Set(0);
	firewheels->Set(0);
}

void nerfshooter::Fire()
{
	fire->Set(1);
}

void nerfshooter::FireWheels(){
	firewheels->Set(1);
}

void nerfshooter::SetWheelSpeed(float speed){
	firewheels->Set(speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
