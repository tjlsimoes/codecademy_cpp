#include "RobotControlCenter.hpp"
#include "DeliveryRobot.hpp"
#include "MaintenanceRobot.hpp"

int main() {
	try
	{
		RobotControlCenter controlCenter(5);

		// std::unique_ptr<DeliveryRobot> del_a = std::make_unique<DeliveryRobot>("Giuseppe", 50);
		DeliveryRobot	*del_a = new DeliveryRobot("Giuseppe", 50);
		DeliveryRobot	*del_b = new DeliveryRobot("Pinochio", 10);
		MaintenanceRobot	*maint_a = new MaintenanceRobot("John", 80);
		MaintenanceRobot	*maint_b = new MaintenanceRobot("Alfred", 20);
	
		controlCenter.addRobot(del_a);
		controlCenter.addRobot(del_b);
		controlCenter.addRobot(maint_a);
		controlCenter.addRobot(maint_b);
		
		try
		{
			controlCenter.executeAllRobotTasks();
		}
		catch(...)
		{
			std::cout << "Unexpected error: shutting down factory" << std::endl;
			delete del_a;
			delete del_b;
			delete maint_a;
			delete maint_b;

			std::cout << "Program finished" << std::endl;
			exit(0);
		}
		delete del_a;
		delete del_b;
		delete maint_a;
		delete maint_b;
	}
	catch(const RobotException& e)
	{
		std::cout << e.what() << std::endl;
		exit(0);
	}
	
	return 0;
}