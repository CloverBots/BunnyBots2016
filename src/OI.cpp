#include "OI.h"

OI::OI()
{
	Controller = new Joystick(1);
	JoystickButton* ButtonA = new JoystickButton(Controller, 0),
			ButtonB = new JoystickButton(Controller, 1),
			ButtonX = new JoystickButton(Controller, 2),
			ButtonY = new JoystickButton(Controller, 3),
			ButtonLB = new JoystickButton(Controller, 4),
			ButtonRB = new JoystickButton(Controller, 5),
			ButtonSel = new JoystickButton(Controller, 6),
			ButtonStr = new JoystickButton(Controller, 7),
			ButtonLS = new JoystickButton(Controller, 8),
			ButtonRS = new JoystickButton(Controller, 9);
}
