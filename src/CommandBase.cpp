#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveSystem2* CommandBase::pDriveSystem = NULL;
std::unique_ptr<Grabber> CommandBase::grabber;
std::unique_ptr<nerfshooter> CommandBase::nerfsubsystem;
std::unique_ptr<OI> CommandBase::oi;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	pDriveSystem = new DriveSystem2();
	grabber.reset(new Grabber());
	nerfsubsystem.reset(new nerfshooter());

	oi.reset(new OI());
}
