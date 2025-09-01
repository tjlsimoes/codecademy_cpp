#include "MaintenanceRobot.hpp"

MaintenanceRobot::MaintenanceRobot(const std::string & name, int initialIntegrity) : Robot(name), mechanicalIntegrity(initialIntegrity)
{}

void	MaintenanceRobot::performTask()
{
	if (mechanicalIntegrity < 30)
		throw MechanicalFailureException("Insufficient integrity");
	std::cout << "Maintenance Robot is performing maintenance" << std::endl;
	mechanicalIntegrity -= 15;
	std::cout << "Maintenance done" << std::endl;
}



