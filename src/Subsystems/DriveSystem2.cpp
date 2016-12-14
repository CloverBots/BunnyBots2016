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

	m_pRobotDrive = new RobotDrive(m_pFrontLeftMotor, m_pFrontRightMotor, m_pRearLeftMotor, m_pRearRightMotor);

}

DriveSystem2::~DriveSystem2()
{

	delete m_pFrontLeftMotor;
	delete m_pFrontRightMotor;
	delete m_pRearLeftMotor;
	delete m_pRearRightMotor;
	delete m_pRobotDrive;

}

void DriveSystem2::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

	SetDefaultCommand(new JoystickDrive());

}

void DriveSystem2::Drive(float xSpeed, float ySpeed, float rotSpeed){

	m_pFrontLeftMotor->Set(ySpeed + xSpeed - rotSpeed);
	m_pFrontRightMotor->Set(ySpeed + xSpeed + rotSpeed);
	m_pRearLeftMotor->Set(ySpeed - xSpeed - rotSpeed);
	m_pRearRightMotor->Set(ySpeed - xSpeed + rotSpeed);

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
