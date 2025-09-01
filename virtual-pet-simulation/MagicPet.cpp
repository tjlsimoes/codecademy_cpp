#include "MagicPet.hpp"
#include <iostream>
using namespace std;

void	MagicPet::makeSound()
{
	std::cout
	<< getName() << " makes a mystical sound!"
	<< std::endl;
}

void	MagicPet::doTrick()
{
	std::cout 
	<< getName() << " performs a magic trick!"
	<< std::endl;
}
