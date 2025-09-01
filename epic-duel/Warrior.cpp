#include "Warrior.hpp"


Warrior::Warrior() : Character("Elden King", 100, 10)
{}

Warrior::Warrior(std::string n, int h, int p) : Character(n, h, p)
{}

void	Warrior::attack()
{
	std::cout << "Swings a mighty sword!" << std::endl;
}

void	Warrior::specialAttack()
{
	std::cout
	<< name << " issues a devastating double strike!"
	<< std::endl;
}