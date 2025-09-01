#include "Character.hpp"

Character::Character() : name("Elden King"), health(100), power(10)
{}

Character::~Character() {}

Character::Character(std::string n, int h, int p) : name(n), health(h), power(p)
{}

void	Character::attack()
{
	std::cout << "Basic Low Attack" << std::endl;
}

void	Character::displayInfo()
{
	std::cout << "Name: " << name 
	<< ", Health: " << health
	<< ", Power: " << power
	<< std::endl;
}