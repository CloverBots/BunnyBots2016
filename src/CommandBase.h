#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "Subsystems/DriveSystem2.h"
#include "Subsystems/Grabber.h"
#include "Subsystems/nerfshooter.h"
#include "OI.h"
#include "WPILib.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(const std::string &name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static DriveSystem2* pDriveSystem;
	static std::unique_ptr<Grabber> grabber;
	static std::unique_ptr<nerfshooter> nerfsubsystem;
	static std::unique_ptr<OI> oi;
};

#endif
