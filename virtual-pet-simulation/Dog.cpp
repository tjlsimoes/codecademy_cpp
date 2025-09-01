#include "Dog.hpp"
#include <iostream>
using namespace std;

Dog::Dog()
{}

Dog::~Dog()
{}

void	Dog::makeSound()
{
	std::cout
	<< getName() << " is barking! Woof!"
	<< std::endl;
}