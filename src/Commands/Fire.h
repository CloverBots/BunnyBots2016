#ifndef Fire_H
#define Fire_H

#include "../CommandBase.h"
#include "WPILib.h"

class Fire: public CommandBase
{
private:

	float m_speed;

public:
	Fire(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
