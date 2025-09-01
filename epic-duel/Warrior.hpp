#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "Character.hpp"

class Warrior : public Character
{
	public:
		Warrior();
		Warrior(std::string n, int h, int p);

		void	attack() override;
		void	specialAttack();
};

#endif 
