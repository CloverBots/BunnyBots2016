#include "ShootSequence.h"
#include "SetWheelSpeed.h"
#include "DelayCommand.h"
#include "Fire.h"
ShootSequence::ShootSequence()
{
	AddSequential(new SetWheelSpeed(1.0f));
	AddSequential(new DelayCommand(0.5f));
	AddSequential(new Fire(1.0f));
}
