#ifndef DelayCommand_H
#define DelayCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class DelayCommand: public CommandBase
{
private:
	float time;
public:
	DelayCommand(float time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
