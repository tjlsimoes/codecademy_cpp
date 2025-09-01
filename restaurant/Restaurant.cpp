#include "Restaurant.hpp"
#include "Customer.hpp"
#include "removeElement.hpp"

#include <iostream>

using namespace std;

Restaurant::Restaurant(int InitialTableCount)
{
	std::cout 
		<< "Creating a restaurant with "
		<< InitialTableCount << " tables."
		<< std::endl;
	for (int i = 1; i < InitialTableCount + 1; i++)
	{
		std::cout << "Creating table " << i << std::endl;
		tables.push_back(std::make_unique<Table>(i));
	}
}

bool	Restaurant::reserveTable(shared_ptr<Customer> & customer)
{
	for (std::unique_ptr<Table> & table : tables)
	{
		if ((*table).getIsAvailable())
		{
			std::cout << "Table " << (*table).getNumber()
				<< " is available for reservation for " << (*customer).getName() << std::endl;
			(*table).reserve();
			activeCustomers.push_back(customer);
			return true;
		}
	}
	std::cout << "No available tables as of right now." << std::endl;
	waitlist.push_back(customer);
	return false;
}

void	Restaurant::printWaitList() const
{
	if (waitlist.size() == 0)
	{
		std::cout << "The wait list is empty." << std::endl;
		return ;
	}
	std::cout 
	<< "The following people are waiting for a table:" 
	<< std::endl;
	for (std::weak_ptr<Customer> customerWaiting : waitlist)
	{
		std::shared_ptr<Customer> customerPtr;
		if (customerPtr = customerWaiting.lock())
			std::cout << (*customerPtr).getName() << std::endl;
	}
	// Optional improvement:
	// for (const auto& customerWaiting : waitlist)
	// {
	// 	if (auto customerPtr = customerWaiting.lock())
	// 		std::cout << customerPtr->getName() << std::endl;
	// }
}

void	Restaurant::releaseTable(int tableNumber)
{
	for (std::unique_ptr<Table> & table : tables)
	{
		if ((*table).getNumber() == tableNumber && !(*table).getIsAvailable())
		{
			std::cout <<  "Releasing table " << tableNumber << std::endl;
			(*table).release();
			notifyWaitlist();
		}
	}
}

void	Restaurant::notifyWaitlist()
{
	if (waitlist.size() == 0)
		return ;
	std::shared_ptr<Customer> customer;
	customer = waitlist[0].lock();
	if (customer)
	{
		reserveTable(customer);
		removeElement(waitlist, waitlist[0]);
	}
	
}