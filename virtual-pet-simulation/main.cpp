#include "Pet.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "MagicPet.hpp"
#include <iostream>
#include <vector>
#include <memory> // for smart pointers
using namespace std;

int main() {
	Dog *myDog = new Dog();
	Cat	*myCat = new Cat();

	myDog->setAge(5);
	myDog->setName("Tails");
	
	myCat->setAge(5);
	myCat->setName("Whiskers");
	
	vector<Pet *> pets;
	pets.push_back(myDog);
	pets.push_back(myCat);
	// vector<std::unique_ptr<Pet>> pets;
	// pets.push_back(std::make_unique<Dog>());

	for (Pet *pet : pets)
		pet->makeSound();

	MagicPet	*myMagicPet = new MagicPet();
	pets.push_back(myMagicPet);
	myMagicPet->setAge(5);
	myMagicPet->setName("Magic");

	for (Pet *pet : pets)
	{
		MagicPet *magic = dynamic_cast<MagicPet *>(pet);
		if (magic)
			magic->doTrick();
	}


	for (Pet *pet : pets)
		delete pet;
	return 0;
}
