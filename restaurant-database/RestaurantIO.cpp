#include "RestaurantIO.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

void addRestaurant(vector<Restaurant>& database) {
	int					restaurantId, menuItemCount;
	string				restaurantName, cuisineType;
	std::string 		itemName;
	double				itemPrice;

	std::cout << "Enter restaurant ID: " << std::endl;
	std::cin >> restaurantId;
	std::cin.ignore(1000, '\n');
	if (std::cin.fail())
	{
		std::cerr << "Invalid input" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		return ;	
	}
	std::cout << "Enter restaurant name: " << std::endl;
	std::getline(std::cin, restaurantName);

	std::cout << "Enter cuisine type: " << std::endl;;
	std::getline(std::cin, cuisineType);

	Restaurant restaurant(restaurantId, restaurantName, cuisineType);
	std::cout << "Enter the number of menu items: " << std::endl;
	std::cin >> menuItemCount;
	std::cin.ignore(1000, '\n');
	if (std::cin.fail() || menuItemCount < 0)
	{
		std::cerr << "Invalid number" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		return ;	
	}
	for (int i = 0; i < menuItemCount; i++)
	{
		std::cout << "Enter item " << i << " name: ";
		std::getline(std::cin, itemName);
		std::cout << "Enter item " << i << " price: ";
		std::cin >> itemPrice;
		if (std::cin.fail() || menuItemCount < 0)
		{
			std::cerr << "Invalid price." << std::endl;
			itemPrice = 0;
		}
		std::cin.ignore(1000, '\n');

		std::stringstream	itemEntryStream;
		itemEntryStream
		<< itemName << " "
		<< std::fixed << std::setprecision(2)
		<< itemPrice;
		restaurant.addMenuItem(itemEntryStream.str());
	}

	database.push_back(restaurant);
}

void displayRestaurants(const vector<Restaurant>& database) {
  for (const auto& restaurant : database) {
    cout << "\nID: " << restaurant.getId()
         << "\nName: " << restaurant.getName()
         << "\nCuisine: " << restaurant.getCuisine()
         << "\nMenu:\n";

    for (const auto& menuItemEntry : restaurant.getMenu()) {
      cout << "  - " << menuItemEntry << '\n';
    }
  }
}

bool loadDatabase(vector<Restaurant>& database, const string& filename) {
	database.clear();
	ifstream inputFile(filename);
	Restaurant restaurant;
	if (!inputFile.is_open())
	{
		std::cerr
		<< "[WARN] Could not open " << filename << "for reading."
		<< std::endl;
		return false;
	}
	while (inputFile >> restaurant)
		database.push_back(restaurant);
	return true;
}

void saveDatabase(const vector<Restaurant>& database, const string& filename) {
	ofstream	outputFile(filename);
	if (!outputFile.is_open())
	{
		std::cerr
		<< "[ERR] Could not open " << filename << "for writing."
		<< std::endl;
	}
	for (Restaurant restaurant : database)
	{
		outputFile << restaurant << "\n";
	}
	outputFile.close();
}
