#include <iostream>
#include "Restaurant.hpp"

using namespace std;
int main() {
	// Initialize Restaurant with 2 tables
	Restaurant restaurant = Restaurant(2);
	// Create customers and make reservations
	std::shared_ptr<Customer> customer1 = std::make_shared<Customer>("Joe");
	std::shared_ptr<Customer> customer2 = std::make_shared<Customer>("Michael");
	std::shared_ptr<Customer> customer3 = std::make_shared<Customer>("Eleanor");
	std::shared_ptr<Customer> customer4 = std::make_shared<Customer>("Reagan");
	// Release a table and demonstrate waitlist notification
	restaurant.reserveTable(customer1);
	std::vector<std::shared_ptr<Customer>> customers;
	customers.push_back(customer1);
	customers.push_back(customer2);
	customers.push_back(customer3);
	customers.push_back(customer4);

	for (std::shared_ptr<Customer> current : customers)
	{
		if ((*current).getName() == "Joe")
			continue ;
		if (restaurant.reserveTable(current))
		{
			std::cout 
			<< "Reserving table for " 
			<< (*current).getName() << ": Success!" 
			<< std::endl;
		}
		else
		{
			std::cout 
			<< "Reserving table for " 
			<< (*current).getName() << ": Added to waitlist!" 
			<< std::endl;
		}
	}

	restaurant.releaseTable(1);
	restaurant.printWaitList();
	restaurant.releaseTable(2);
	restaurant.printWaitList();
	return 0;
}