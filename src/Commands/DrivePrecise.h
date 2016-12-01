#ifndef DrivePrecise_H
#define DrivePrecise_H

#include "../CommandBase.h"
#include "WPILib.h"

class DrivePrecise: public CommandBase
{
private:

	enum DriveMode {
		BASIC,
		ASSISTED
	};

	DriveMode driveMode;

public:
	DrivePrecise();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
