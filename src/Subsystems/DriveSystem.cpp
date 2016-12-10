#include "DriveSystem.h"
#include "../RobotMap.h"
#include "../Commands/JoystickDrive.h"

DriveSystem::DriveSystem() :
		Subsystem("DriveSystem"), m_xSpeed(0.0f), m_ySpeed(0.0f), m_rotSpeed(0.0f)
{

	m_pFrontLeftMotor = new Talon(RobotMap::FRONT_LEFT_MOTOR_PORT);
	m_pFrontRightMotor = new Talon(RobotMap::FRONT_RIGHT_MOTOR_PORT);
	m_pRearLeftMotor = new Talon(RobotMap::REAR_LEFT_MOTOR_PORT);
	m_pRearRightMotor = new Talon(RobotMap::REAR_RIGHT_MOTOR_PORT);

	m_pRobotDrive = new RobotDrive(m_pFrontLeftMotor, m_pFrontRightMotor, m_pRearLeftMotor, m_pRearRightMotor);

}

DriveSystem::~DriveSystem()
{

	delete m_pFrontLeftMotor;
	delete m_pFrontRightMotor;
	delete m_pRearLeftMotor;
	delete m_pRearRightMotor;
	delete m_pRobotDrive;

}

void DriveSystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

	SetDefaultCommand(new JoystickDrive());

}

void DriveSystem::Drive(float xSpeed, float ySpeed, float rotSpeed){

	m_pFrontLeftMotor->Set(ySpeed + xSpeed - rotSpeed);
	m_pFrontRightMotor->Set(ySpeed + xSpeed + rotSpeed);
	m_pRearLeftMotor->Set(ySpeed - xSpeed - rotSpeed);
	m_pRearRightMotor->Set(ySpeed - xSpeed + rotSpeed);

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
