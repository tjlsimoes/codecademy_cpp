#include <iostream>
#include "MexicanRestaurant.hpp"
#include "JapaneseRestaurant.hpp"
#include "MexicanJapaneseFusion.hpp"

using namespace std;

int main() {
    cout << "Testing Restaurant Inheritance Hierarchy:" << endl;
	MexicanRestaurant mexican = MexicanRestaurant("La Casa", "123 Spice Lane", 4);
	JapaneseRestaurant japanese = JapaneseRestaurant("Sakura", "456 Sushi Road", true);
	MexicanJapaneseFusion fusion = MexicanJapaneseFusion("Fusion Fiesta", "789 Fuxion Ave", 3, true);

	std::cout << "--------------------------" << std::endl;
	mexican.displayInfo();
	mexican.describeCuisine();
	std::cout << "--------------------------" << std::endl;
	japanese.displayInfo();
	japanese.describeCuisine();
	std::cout << "--------------------------" << std::endl;
	fusion.displayInfo();
	fusion.describeCuisine();
	fusion.displaySpecialty();

	mexican.addMenuItem(MenuItem("Tacos", 8.99));
	mexican.addMenuItem(MenuItem("Enchiladas", 12.99));

	japanese.addMenuItem(MenuItem("Sushi Roll", 14.99));
	japanese.addMenuItem(MenuItem("Ramen", 11.99));

	fusion.addMenuItem(MenuItem("Sushi Tacos", 15.99));
	fusion.addMenuItem(MenuItem("Wasabi Guacamole", 7.99));

	std::cout << "--------------------------" << std::endl;
	std::cout << "--------------------------" << std::endl;

	mexican.displayMenu();
	std::cout << "--------------------------" << std::endl;
	japanese.displayMenu();
	std::cout << "--------------------------" << std::endl;
	fusion.displayMenu();
	std::cout << "--------------------------" << std::endl;

    return 0;
}
