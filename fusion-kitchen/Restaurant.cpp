#include "Restaurant.hpp"
#include <iostream>


Restaurant::Restaurant(std::string n, std::string addr) : name(n), address(addr) {}

void	Restaurant::Restaurant::displayInfo()
{
	std::cout << name << ", " << address << std::endl;
}

void	Restaurant::Restaurant::describeCuisine()
{
	std::cout
	<< "This restaurant serves various types of cuisines."
	<< std::endl;
}

void	Restaurant::addMenuItem(MenuItem item)
{
	menu.push_back(item);
}

void	Restaurant::displayMenu()
{
	std::cout << name << "'s Menu:" << std::endl;
	for (MenuItem item : menu)
		item.display();
}
