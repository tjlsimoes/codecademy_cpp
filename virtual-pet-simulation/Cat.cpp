#include "Cat.hpp"
#include <iostream>
using namespace std;

Cat::Cat()
{}

Cat::~Cat()
{}

void	Cat::makeSound()
{
	std::cout
	<< getName() << " is meowing! Meow!"
	<< std::endl;
}