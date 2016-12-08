#include "OI.h"

OI::OI()
{
	m_pArmJoystick = new Joystick(0);
	m_pAButton = new JoystickButton(m_pArmJoystick(), 0);

	m_pAButton->WhenPressed(new SetGrabberSpeed(1.0f));
	m_pAButton->WhenReleased(new SetGrabberSpeed(0.0f));
}

 Joystick* OI::GetArmJoystick()
{
	return m_pArmJoystick;
}
