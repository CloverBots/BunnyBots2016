#include <Subsystems/DriveSystem2.h>
#include "../RobotMap.h"
#include "../Commands/JoystickDrive.h"

DriveSystem2::DriveSystem2() :
		Subsystem("DriveSystem"), m_xSpeed(0.0f), m_ySpeed(0.0f), m_rotSpeed(0.0f)
{
	m_pFrontLeftMotor = new Talon(RobotMap::LEFT_FRONT_TALON);
	m_pFrontRightMotor = new Talon(RobotMap::RIGHT_FRONT_TALON);
	m_pRearLeftMotor = new Talon(RobotMap::LEFT_REAR_TALON);
	m_pRearRightMotor = new Talon(RobotMap::RIGHT_REAR_TALON);

<<<<<<< HEAD
	m_pRearRightMotor->SetInverted(true);
	m_pFrontRightMotor->SetInverted(true);
=======
	m_pRobotDrive = new RobotDrive(m_pFrontLeftMotor, m_pFrontRightMotor, m_pRearLeftMotor, m_pRearRightMotor);

>>>>>>> origin/master
}

DriveSystem2::~DriveSystem2()
{
<<<<<<< HEAD
=======

>>>>>>> origin/master
	delete m_pFrontLeftMotor;
	delete m_pFrontRightMotor;
	delete m_pRearLeftMotor;
	delete m_pRearRightMotor;
<<<<<<< HEAD
=======
	delete m_pRobotDrive;

>>>>>>> origin/master
}

void DriveSystem2::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

	SetDefaultCommand(new JoystickDrive());
<<<<<<< HEAD
=======

>>>>>>> origin/master
}

void DriveSystem2::Drive(float xSpeed, float ySpeed, float rotSpeed){

<<<<<<< HEAD
	m_pFrontLeftMotor->Set(ySpeed - xSpeed - rotSpeed);
	m_pFrontRightMotor->Set(ySpeed + xSpeed + rotSpeed);
	m_pRearLeftMotor->Set(ySpeed + xSpeed - rotSpeed);
	m_pRearRightMotor->Set(ySpeed - xSpeed + rotSpeed);
=======
	m_pFrontLeftMotor->Set(ySpeed + xSpeed - rotSpeed);
	m_pFrontRightMotor->Set(ySpeed + xSpeed + rotSpeed);
	m_pRearLeftMotor->Set(ySpeed - xSpeed - rotSpeed);
	m_pRearRightMotor->Set(ySpeed - xSpeed + rotSpeed);

>>>>>>> origin/master
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
