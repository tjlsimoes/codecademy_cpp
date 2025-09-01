#include "MexicanRestaurant.hpp"
#include <iostream>

MexicanRestaurant::MexicanRestaurant(std::string name, std::string addr, int spceLevel) : Restaurant(name, addr), spiceLevel(spceLevel)
{}

void	MexicanRestaurant::describeCuisine()
{
	std::cout
	<< "Authentic Mexican cuisine with spice level "
	<< spiceLevel
	<< " out of 5"
	<< std::endl;
}