#ifndef SetGrabberSpeed_H
#define SetGrabberSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetGrabberSpeed: public CommandBase
{
private:

	float speed;

public:
	SetGrabberSpeed(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
