#ifndef SORCERER_HPP
#define SORCERER_HPP

#include "Character.hpp"

class Sorcerer : public Character
{
	public:
		Sorcerer();
		Sorcerer(std::string n, int h, int p);

		void	attack() override;
};

#endif 
