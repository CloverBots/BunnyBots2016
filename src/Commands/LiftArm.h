#ifndef DefaultPosition_H
#define DefaultPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class LiftArm: public CommandBase
{
public:
	LiftArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
