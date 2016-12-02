#ifndef ControlGrabber_H
#define ControlGrabber_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlGrabber: public CommandBase
{
public:
	ControlGrabber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
