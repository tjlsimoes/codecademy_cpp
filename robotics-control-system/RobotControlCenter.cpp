
#include "RobotControlCenter.hpp"


RobotControlCenter::RobotControlCenter(int capacity)
{
	if (capacity < 0)
		throw RobotException("Negative capacity");
	else
		std::cout << "Control Center created" << std::endl;
}

void	RobotControlCenter::logError(const std::string & errorMessage) noexcept
{
	std::cout << errorMessage << std::endl;
}

void	RobotControlCenter::addRobot(Robot *robot)
{
	robotCollection.push_back(robot);
}

void	RobotControlCenter::executeAllRobotTasks()
{
	try
	{
		for (Robot * robot : robotCollection)
			robot->performTask();
	}
	catch (const BatteryLowException& e)
	{
		logError(e.what());
	}
	catch (const MechanicalFailureException& e)
	{
		logError(e.what());
	}
	catch (const RobotException& e)
	{
		logError(e.what());
	}
	catch (...)
	{
		std::cout << "Unknown robot error" << std::endl;
		throw;
	}
	
}


