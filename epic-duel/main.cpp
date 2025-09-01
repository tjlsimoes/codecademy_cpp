#include <vector>
#include "Warrior.hpp"
#include "Sorcerer.hpp"

using namespace std;

int main() {
	vector<Character *> characters;
	// Warrior *warrior = new Warrior("Warrior Chief", 100, 10);
	// Sorcerer *sorcerer = new Sorcerer("Sorcerer Chief", 100, 10);
	characters.push_back(new Warrior("Warrior Chief", 100, 10));
	characters.push_back(new Sorcerer("Sorcerer Chief", 100, 10));

	std::cout << "---------------------------------------" << std::endl;
	for (Character *character : characters)
	{
		character->attack();
		character->displayInfo();
		std::cout << "---------------------------------------" << std::endl;
	}

	Character	*characterPtr = characters[0];
	Warrior *downcast_warrior = dynamic_cast<Warrior *>(characterPtr);
	downcast_warrior->specialAttack();


	// delete warrior;
	// delete sorcerer;
	for (Character *character : characters)
		delete character;
  return 0;
}
