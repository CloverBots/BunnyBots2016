#ifndef DrivePrecise_H
#define DrivePrecise_H

#include "../CommandBase.h"
#include "WPILib.h"
//do the thing where you make those dang enum's private

class DrivePrecise:public CommandBase {
private:

	enum DriveMode
	{
		BASIC,
		CLASSIC
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
