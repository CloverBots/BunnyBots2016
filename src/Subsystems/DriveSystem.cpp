#include <cmath>
#include "DriveSystem.h"
#include "../RobotMap.h"
#include "Talon.h"



DriveSystem::DriveSystem() :
		Subsystem("DriveSystem")
{
	m_pLeftFrontTalon = new Talon(RobotMap::LEFT_FRONT_TALON);
	m_pLeftRearTalon = new Talon(RobotMap::LEFT_REAR_TALON);
	m_pRightFrontTalon = new Talon(RobotMap::RIGHT_FRONT_TALON);
	m_pRightRearTalon = new Talon(RobotMap::RIGHT_REAR_TALON);
}
void DriveSystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	void SetDefaultCommand(new DrivePrecise());
}
void DriveSystem::DriveBasic(float TurnRaw, float StrafeRaw, float ThrottleRaw, int TurnDir, int StrafeDir, int ThrottleDir)
{
	float Throttle = ThrottleRaw;
	float Turn = (1-TurnRaw);
	float Strafe = (1-StrafeRaw);
	//float LimitFactor = 0.5; //Limits how much you can slow one set of wheels
	switch (ThrottleDir)
	{
	case 0:
		switch (TurnDir)
		{
		case 0:
			switch (StrafeDir)
			{
			case 0:
				m_pLeftFrontTalon->Set(Throttle*Turn*Strafe);
				m_pLeftRearTalon->Set(Throttle*Turn);
				m_pRightFrontTalon->Set(Throttle);
				m_pRightRearTalon->Set(Throttle*Strafe);
				break;
			case 1:
				m_pLeftFrontTalon->Set(Throttle*Turn);
				m_pLeftRearTalon->Set(Throttle*Turn);
				m_pRightFrontTalon->Set(Throttle);
				m_pRightRearTalon->Set(Throttle);
				break;
			case 2:
				m_pLeftFrontTalon->Set(Throttle*Turn);
				m_pLeftRearTalon->Set(Throttle*Turn*Strafe);
				m_pRightFrontTalon->Set(Throttle*Strafe);
				m_pRightRearTalon->Set(Throttle);
				break;
			}
		break;
		case 1:
			switch (StrafeDir)
			{
			case 0:
				m_pLeftFrontTalon->Set(Throttle*Strafe);
				m_pLeftRearTalon->Set(Throttle);
				m_pRightFrontTalon->Set(Throttle);
				m_pRightRearTalon->Set(Throttle*Strafe);
				break;
			case 1:
				m_pLeftFrontTalon->Set(Throttle);
				m_pLeftRearTalon->Set(Throttle);
				m_pRightFrontTalon->Set(Throttle);
				m_pRightRearTalon->Set(Throttle);
				break;
			case 2:
				m_pLeftFrontTalon->Set(Throttle);
				m_pLeftRearTalon->Set(Throttle*Strafe);
				m_pRightFrontTalon->Set(Throttle*Strafe);
				m_pRightRearTalon->Set(Throttle);
				break;
			}
		break;
		case 2:
			switch (StrafeDir)
			{
			case 0:
				m_pLeftFrontTalon->Set(Throttle*Strafe);
				m_pLeftRearTalon->Set(Throttle);
				m_pRightFrontTalon->Set(Throttle*Turn);
				m_pRightRearTalon->Set(Throttle*Turn*Strafe);
				break;
			case 1:
				m_pLeftFrontTalon->Set(Throttle);
				m_pLeftRearTalon->Set(Throttle);
				m_pRightFrontTalon->Set(Throttle*Turn);
				m_pRightRearTalon->Set(Throttle*Turn);
				break;
			case 2:
				m_pLeftFrontTalon->Set(Throttle);
				m_pLeftRearTalon->Set(Throttle*Strafe);
				m_pRightFrontTalon->Set(Throttle*Turn*Strafe);
				m_pRightRearTalon->Set(Throttle*Turn);
				break;
			}
		break;
		}
	break;

	case 1:
		switch (TurnDir)
		{
		case 0:
			switch (StrafeDir)
			{
			case 0:
				m_pLeftFrontTalon->Set(-StrafeRaw*Turn);
				m_pLeftRearTalon->Set(StrafeRaw*Turn);
				m_pRightFrontTalon->Set(StrafeRaw);
				m_pRightRearTalon->Set(-StrafeRaw);
				break;
			case 1:
				m_pLeftFrontTalon->Set(-TurnRaw);
				m_pLeftRearTalon->Set(-TurnRaw);
				m_pRightFrontTalon->Set(TurnRaw);
				m_pRightRearTalon->Set(TurnRaw);
				break;
			case 2:
				m_pLeftFrontTalon->Set(StrafeRaw);
				m_pLeftRearTalon->Set(-StrafeRaw);
				m_pRightFrontTalon->Set(-StrafeRaw*Turn);
				m_pRightRearTalon->Set(StrafeRaw*Turn);
				break;
			}
		break;
		case 1:
			switch (StrafeDir)
			{
			case 0:
				m_pLeftFrontTalon->Set(-StrafeRaw);
				m_pLeftRearTalon->Set(StrafeRaw);
				m_pRightFrontTalon->Set(StrafeRaw);
				m_pRightRearTalon->Set(-StrafeRaw);
				break;
			case 1:
				m_pLeftFrontTalon->Set(0);
				m_pLeftRearTalon->Set(0);
				m_pRightFrontTalon->Set(0);
				m_pRightRearTalon->Set(0);
				break;
			case 2:
				m_pLeftFrontTalon->Set(StrafeRaw);
				m_pLeftRearTalon->Set(-StrafeRaw);
				m_pRightFrontTalon->Set(-StrafeRaw);
				m_pRightRearTalon->Set(StrafeRaw);
				break;
			}
		break;
		case 2:
			switch (StrafeDir)
			{
			case 0:
				m_pLeftFrontTalon->Set(-StrafeRaw);
				m_pLeftRearTalon->Set(StrafeRaw);
				m_pRightFrontTalon->Set(StrafeRaw*Turn);
				m_pRightRearTalon->Set(-StrafeRaw*Turn);
				break;
			case 1:
				m_pLeftFrontTalon->Set(TurnRaw);
				m_pLeftRearTalon->Set(TurnRaw);
				m_pRightFrontTalon->Set(-TurnRaw);
				m_pRightRearTalon->Set(-TurnRaw);
				break;
			case 2:
				m_pLeftFrontTalon->Set(StrafeRaw);
				m_pLeftRearTalon->Set(-StrafeRaw);
				m_pRightFrontTalon->Set(-StrafeRaw*Turn);
				m_pRightRearTalon->Set(StrafeRaw*Turn);
				break;
			}
		break;
		}
	break;

	case 2:
		switch (TurnDir)
		{
		case 0:
			switch (StrafeDir)
			{
			case 0:
				m_pLeftFrontTalon->Set(-Throttle*Turn);
				m_pLeftRearTalon->Set(-Throttle*Turn*Strafe);
				m_pRightFrontTalon->Set(-Throttle*Strafe);
				m_pRightRearTalon->Set(-Throttle);
				break;
			case 1:
				m_pLeftFrontTalon->Set(-Throttle*Turn);
				m_pLeftRearTalon->Set(-Throttle*Turn);
				m_pRightFrontTalon->Set(-Throttle);
				m_pRightRearTalon->Set(-Throttle);
				break;
			case 2:
				m_pLeftFrontTalon->Set(-Throttle*Turn*Strafe);
				m_pLeftRearTalon->Set(-Throttle*Turn);
				m_pRightFrontTalon->Set(-Throttle);
				m_pRightRearTalon->Set(-Throttle*Strafe);
				break;
			}
		break;
		case 1:
			switch (StrafeDir)
			{
			case 0:
				m_pLeftFrontTalon->Set(-Throttle);
				m_pLeftRearTalon->Set(-Throttle*Strafe);
				m_pRightFrontTalon->Set(-Throttle*Strafe);
				m_pRightRearTalon->Set(-Throttle);
				break;
			case 1:
				m_pLeftFrontTalon->Set(-Throttle);
				m_pLeftRearTalon->Set(-Throttle);
				m_pRightFrontTalon->Set(-Throttle);
				m_pRightRearTalon->Set(-Throttle);
				break;
			case 2:
				m_pLeftFrontTalon->Set(-Throttle*Strafe);
				m_pLeftRearTalon->Set(-Throttle);
				m_pRightFrontTalon->Set(-Throttle);
				m_pRightRearTalon->Set(-Throttle*Strafe);
				break;
			}
		break;
		case 2:
			switch (StrafeDir)
			{
			case 0:
				m_pLeftFrontTalon->Set(-Throttle);
				m_pLeftRearTalon->Set(-Throttle*Strafe);
				m_pRightFrontTalon->Set(-Throttle*Turn*Strafe);
				m_pRightRearTalon->Set(-Throttle*Turn);
				break;
			case 1:
				m_pLeftFrontTalon->Set(-Throttle);
				m_pLeftRearTalon->Set(-Throttle);
				m_pRightFrontTalon->Set(-Throttle*Turn);
				m_pRightRearTalon->Set(-Throttle*Turn);
				break;
			case 2:
				m_pLeftFrontTalon->Set(-Throttle*Strafe);
				m_pLeftRearTalon->Set(-Throttle);
				m_pRightFrontTalon->Set(-Throttle*Turn);
				m_pRightRearTalon->Set(-Throttle*Turn*Strafe);
				break;
			}
		break;
		}
	break;
}
