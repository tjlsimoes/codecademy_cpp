#include "Pet.hpp"
#include <iostream>
using namespace std;

Pet::~Pet()
{}

std::string Pet::getName()
{
	return name;
}

int		Pet::getAge()
{
	return age;
}

void Pet::setName(std::string newName)
{
	name = newName;
}

void		Pet::setAge(int newAge)
{
	age = newAge;
}


void	Pet::eat()
{
	std::cout << name << " is eating!" << std::endl;
}