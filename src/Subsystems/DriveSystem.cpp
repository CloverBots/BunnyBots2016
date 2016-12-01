#include "DriveSystem.h"
#include "../RobotMap.h"
#include "Talon.h"
#include <cmath>


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
void DriveSystem::DriveBasic(float Turn, float Strafe, float Throttle)
{
	int TurnDirection; //0 if left, 1 if right
	int StrafeDirection; //0 if left, 1 if right
	int ThrottleDirection; //0 if foreward, 1 if backward
	float TurnFactor;
	float StrafeFactor;
	float MaxTurnMultiTask=0.5; //CHANGE THIS AFTER TESTING. Affects how much the robot can turn while it is already moving on 1+ axes
	float MaxStrafeMultiTask=0.5; //Same as above except for strafing
	if (((Turn==0)&&(Strafe==0))&&(Throttle!=0))
	{
		m_pLeftFrontTalon->Set(Throttle);
		m_pRightFrontTalon->Set(Throttle);
		m_pLeftRearTalon->Set(Throttle);
		m_pRightRearTalon->Set(Throttle);
	}
	else if (((Turn!=0)&&(Strafe==0))&&(Throttle==0))
	{
		m_pLeftFrontTalon->Set(Turn);
		m_pRightFrontTalon->Set(-(Turn));
		m_pLeftRearTalon->Set(Turn);
		m_pRightRearTalon->Set(-(Turn));
	}
	else if (((Turn==0)&&(Strafe!=0))&&(Throttle==0))
	{
		m_pLeftFrontTalon->Set(Strafe);
		m_pRightFrontTalon->Set(-(Strafe));
		m_pLeftRearTalon->Set(-(Strafe));
		m_pRightRearTalon->Set(Strafe);
	}
	else if (((Turn!=0)&&(Strafe==0))&&(Throttle!=0))
	{
		if (Turn < 0)
		{
			TurnDirection = 0;
		}
		else if (Turn > 0)
		{
			TurnDirection = 1;
		}
		if (Throttle > 0)
		{
			ThrottleDirection = 0;
		}
		else if (Throttle < 0)
		{
			ThrottleDirection = 1;
		}
		TurnFactor = (std::fabs(Turn)*MaxTurnMultiTask)*std::fabs(Throttle);
		switch (ThrottleDirection)
		{
		case 0 :
			switch (TurnDirection)
			{
			case 0 :
				m_pLeftFrontTalon->Set(Throttle-TurnFactor);
				m_pRightFrontTalon->Set(Throttle);
				m_pLeftRearTalon->Set(Throttle-TurnFactor);
				m_pRightRearTalon->Set(Throttle);
				break;
			case 1 :
				m_pLeftFrontTalon->Set(Throttle);
				m_pRightFrontTalon->Set(Throttle-TurnFactor);
				m_pLeftRearTalon->Set(Throttle);
				m_pRightRearTalon->Set(Throttle-TurnFactor);
				break;
			}
			break;
		case 1 :
			switch (TurnDirection)
			{
			case 0 :
				m_pLeftFrontTalon->Set(Throttle);
				m_pRightFrontTalon->Set(Throttle+TurnFactor);
				m_pLeftRearTalon->Set(Throttle);
				m_pRightRearTalon->Set(Throttle+TurnFactor);
				break;
			case 1 :
				m_pLeftFrontTalon->Set(Throttle+TurnFactor);
				m_pRightFrontTalon->Set(Throttle);
				m_pLeftRearTalon->Set(Throttle+TurnFactor);
				m_pRightRearTalon->Set(Throttle);
				break;
			}
			break;
		}
	}
	else if (((Turn==0)&&(Strafe!=0))&&(Throttle!=0))
	{
		if (Strafe < 0)
		{
			StrafeDirection = 0;
		}
		else if (Strafe > 0)
		{
			StrafeDirection = 1;
		}
		if (Throttle > 0)
		{
			ThrottleDirection = 0;
		}
		else if (Throttle < 0)
		{
			ThrottleDirection = 1;
		}
		TurnFactor = (std::fabs(Strafe)*MaxTurnMultiTask)*std::fabs(Throttle);
		switch (ThrottleDirection)
		{
		case 0 :
			switch (StrafeDirection)
			{
			case 0 :
				m_pLeftFrontTalon->Set(Throttle-StrafeFactor);
				m_pRightFrontTalon->Set(Throttle);
				m_pLeftRearTalon->Set(Throttle);
				m_pRightRearTalon->Set(Throttle-StrafeFactor);
				break;
			case 1 :
				m_pLeftFrontTalon->Set(Throttle);
				m_pRightFrontTalon->Set(Throttle-StrafeFactor);
				m_pLeftRearTalon->Set(Throttle-StrafeFactor);
				m_pRightRearTalon->Set(Throttle);
				break;
			}
			break;
		case 1 :
			switch (StrafeDirection)
			{
			case 0 :
				m_pLeftFrontTalon->Set(Throttle+StrafeFactor);
				m_pRightFrontTalon->Set(Throttle);
				m_pLeftRearTalon->Set(Throttle);
				m_pRightRearTalon->Set(Throttle+StrafeFactor);
				break;
			case 1 :
				m_pLeftFrontTalon->Set(Throttle);
				m_pRightFrontTalon->Set(Throttle+StrafeFactor);
				m_pLeftRearTalon->Set(Throttle+StrafeFactor);
				m_pRightRearTalon->Set(Throttle);
				break;
			}
			break;
		}
	}
}

void DriveSystem::DriveAssist(float Turn, float Strafe, float Throttle)
{

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
