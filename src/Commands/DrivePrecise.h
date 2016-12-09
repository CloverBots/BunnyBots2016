#ifndef DrivePrecise_H
#define DrivePrecise_H

#include "../CommandBase.h"
#include "WPILib.h"
//do the thing where you make those dang enum's private

class DrivePrecise: public CommandBase
{
private:

	enum DriveMode
	{
		BASIC,
		ASSISTED
	};

	DriveMode driveMode;

public:
	enum struct ThrottleStatus : int
	{
		FOREWARD,
		CENTER,
		BACKWARD
	};
	extern ThrottleStatus throttleStatus;
	enum struct TurnStatus : int
	{
		T_LEFT,
		T_CENTER,
		T_RIGHT
	};
	extern TurnStatus turnStatus;
	enum struct StrafeStatus : int
	{
		S_LEFT,
		S_CENTER,
		S_RIGHT
	};
	extern StrafeStatus strafeStatus;
	DrivePrecise();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
