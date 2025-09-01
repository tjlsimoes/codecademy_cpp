#ifndef DOG_HPP
#define DOG_HPP

#include "Pet.hpp"

class Dog : public Pet
{
	public:
		Dog();
		~Dog();
		void makeSound() override;
};

#endif
