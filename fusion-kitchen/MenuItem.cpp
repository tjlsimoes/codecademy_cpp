#include "MenuItem.hpp"
#include <iostream>
#include <iomanip>

MenuItem::MenuItem(std::string n, double p) : name(n), price(p)
{}

void	MenuItem::display()
{
	std::cout
	<< name << " - "
	<< std::fixed
	<< std::setprecision(2)
	<< price << "$"
	<< std::endl;
}