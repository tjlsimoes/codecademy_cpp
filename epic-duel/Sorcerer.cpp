#include "Sorcerer.hpp"

Sorcerer::Sorcerer() : Character("Elden King", 100, 10)
{}

Sorcerer::Sorcerer(std::string n, int h, int p) : Character(n, h, p)
{}

void	Sorcerer::attack()
{
	std::cout << "Casts a spell!" << std::endl;
}