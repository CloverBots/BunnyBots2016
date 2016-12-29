#ifndef SetWheelSpeed_H
#define SetWheelSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetWheelSpeed: public CommandBase
{
private:
	float speed;
public:
	SetWheelSpeed(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
