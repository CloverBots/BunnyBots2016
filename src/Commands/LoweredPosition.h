#ifndef LoweredPosition_H
#define LoweredPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class LoweredPosition: public CommandBase
{
public:
	LoweredPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
