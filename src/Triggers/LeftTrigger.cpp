#include <Triggers/LeftTrigger.h>
#include "../CommandBase.h"

LeftTrigger::LeftTrigger()
{

}

bool LeftTrigger::Get()
{

	return CommandBase::oi->joystick2->GetRawAxis(3) > 0.5;
}
