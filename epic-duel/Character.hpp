#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>

using namespace std;

class Character
{
	public:
		Character();
		virtual ~Character();
		Character(std::string n, int h, int p);

		virtual void	attack();
		virtual void	displayInfo();

		std::string	name;
		int			health;
		int			power;
};

#endif 