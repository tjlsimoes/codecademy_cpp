#include "MexicanJapaneseFusion.hpp"
#include <iostream>


MexicanJapaneseFusion::MexicanJapaneseFusion(std::string n, std::string addr, int spcLevel, bool tatamiAvailable) : Restaurant(n, addr), MexicanRestaurant(n, addr, spcLevel), JapaneseRestaurant(n, addr, tatamiAvailable)
{}

void	MexicanJapaneseFusion::describeCuisine()
{
	std::cout
	<< "A unique fusion of Mexican and Japanese cuisines"
	<< std::endl;
}

void	MexicanJapaneseFusion::displaySpecialty()
{
	std::cout
	<< "Our specialties combine both cuisines - try our Sushi Tacos and Wasabi Guacamole!"
	<< std::endl;
}
