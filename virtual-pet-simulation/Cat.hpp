#ifndef CAT_HPP
#define CAT_HPP

#include "Pet.hpp"

class Cat : public Pet
{
	public:
		Cat();
		~Cat();
		void makeSound() override;

};

#endif
