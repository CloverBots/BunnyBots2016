#ifndef Grabber_H
#define Grabber_H

#include "../CommandBase.h"
#include "WPILib.h"

class Grabber: public CommandBase
{
public:
	Grabber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
