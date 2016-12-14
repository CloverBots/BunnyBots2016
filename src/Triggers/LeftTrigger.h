#ifndef Trigger_H
#define Trigger_H

#include "WPILib.h"

class LeftTrigger: public Trigger
{
public:
	LeftTrigger();
	bool Get();
};

#endif
