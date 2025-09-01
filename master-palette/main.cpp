#include <iostream>
#include <vector>
#include "Color.hpp"

int main() {
	std::cout << std::boolalpha;  // print bools as true/false

	// You can give this color in two equivalent ways:
	//
	// 1. Hex (base-16): 0x50C878
	// 2. Decimal RGB (base-10): 80, 200, 120
	//
	// Each pair of hex digits converts to its decimal RGB value:
	// 0x50 → 80, 0xC8 → 200, 0x78 → 120
	Color emerald = Color::fromHexLiteral("#50c878");
	Color sunset = Color::fromHexLiteral("#ff4500");
	Color ocean  = Color::fromHexLiteral("#1e90ff");

	std::cout
	<< "Emerald: " 
	<< emerald[0] << ","
	<< emerald[1] << ","
	<< emerald[2]
	<< std::endl;

	Color	dusk = sunset + ocean;
	
	std::cout
	<< "Dusk: " << dusk
	<< std::endl;

	std::vector<int> warmUp = {30, -10, -10};
	std::cout << "Dusk + warmUp: " << (dusk + warmUp) << std::endl;

	std::cout << "++dusk: " << ++dusk << std::endl;
	std::cout << "--sunset: " << --sunset << std::endl;

	std::cout
	<< "Dusk: " 
	<< dusk[0] << ","
	<< dusk[1] << ","
	<< dusk[2]
	<< std::endl;

	Color	duskBoost = dusk * 2;
	std::cout << "DuskBoost: " << duskBoost << std::endl;

	std::cout
	<< "DuskBoost: " 
	<< duskBoost[0] << ","
	<< duskBoost[1] << ","
	<< duskBoost[2]
	<< std::endl;

	Color duskBoostInverted = duskBoost(ColorUtility::invert);

	std::cout
	<< "DuskBoost inverted: " 
	<< duskBoostInverted[0] << ","
	<< duskBoostInverted[1] << ","
	<< duskBoostInverted[2]
	<< std::endl;

	std::cout
	<< "dusk == duskBoost: "
	<< (dusk == duskBoost)
	<< std::endl;
}