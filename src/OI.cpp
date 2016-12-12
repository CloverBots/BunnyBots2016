#include "OI.h"
/* Axes for the controller are as follows:
 * X-Axis, Left Joystick - 0
 * Y-Axis, Left Joystick - 1
 * Left Trigger - 2
 * Right Trigger -3
 * X-Axis, Right Joystick - 4
 * Y-Axis, Right Joystick - 5
 *
 * Using JoystickName->GetRawAxis(AxisNumber) will return a float from -1 to 1.
 * JoystickName->GetRawButton(ButtonID)
 * For X-Axes, -1 is left, and 1 is right. For Y-Axis, -1 is backward, 1 is foreward
 * For the Left and Right Triggers, 0 is the resting point, and 1 is when it is fully pressed down.
 */
OI::OI()
{
	Controller = new Joystick(1);
		ButtonA = new JoystickButton(GetJoystick(), 0);
		ButtonB = new JoystickButton(GetJoystick(), 1);
		ButtonX = new JoystickButton(GetJoystick(), 2);
		ButtonY = new JoystickButton(GetJoystick(), 3);
		ButtonLB = new JoystickButton(GetJoystick(), 4);
		ButtonRB = new JoystickButton(GetJoystick(), 5);
		ButtonSel = new JoystickButton(GetJoystick(), 6);
		ButtonStr = new JoystickButton(GetJoystick(), 7);
		ButtonLS = new JoystickButton(GetJoystick(), 8);
		ButtonRS = new JoystickButton(GetJoystick(), 9);
}
Joystick* GetJoystick()
{
	return Controller;
}
