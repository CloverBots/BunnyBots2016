#include <Triggers/LeftTrigger.h>
#include "../CommandBase.h"

LeftTrigger::LeftTrigger()
{

}

bool LeftTrigger::Get()
{
<<<<<<< HEAD
=======

>>>>>>> origin/master
	return CommandBase::oi->GetStick2()->GetRawAxis(3) > 0.5;
}
