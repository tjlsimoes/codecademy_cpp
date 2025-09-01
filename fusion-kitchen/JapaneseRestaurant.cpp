#include "JapaneseRestaurant.hpp"
#include <iostream>

JapaneseRestaurant::JapaneseRestaurant(std::string name, std::string addr, bool tatamiAvailable): Restaurant(name, addr), hasTatami(tatamiAvailable)
{}

void	JapaneseRestaurant::describeCuisine()
{
	if (hasTatami)
	{
		std::cout 
		<< "Traditional Japanese cuisine with tatami seating available"
		<< std::endl;
	}
	else
		std::cout << "Traditional Japanese cuisine" << std::endl;
}