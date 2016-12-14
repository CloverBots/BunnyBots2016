#ifndef Fire_H
#define Fire_H

#include "../CommandBase.h"
#include "WPILib.h"

class Fire: public CommandBase
{
public:
	Fire();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
