#include "Restaurant.hpp"
#include <sstream>

Restaurant::Restaurant() : id(0) {}

Restaurant::Restaurant(int id, string name, string cuisine)
  : id(id), name(move(name)), cuisine(move(cuisine)) {}

void Restaurant::addMenuItem(const string& menuItemEntry) {
	menuItems.push_back(menuItemEntry);
}

int Restaurant::getId() const {
	return id;
}

const string& Restaurant::getName() const {
	return name;
}

const string& Restaurant::getCuisine() const {
	return cuisine;
}

const vector<string>& Restaurant::getMenu() const {
	return menuItems;
}

ostream& operator<<(ostream& outputStream, const Restaurant& restaurant){
	outputStream
	<< restaurant.id << "#"
	<< restaurant.name << "#"
	<< restaurant.cuisine << "#"
	<< restaurant.menuItems.size() << "#";
	for (auto item : restaurant.menuItems)
		outputStream << item << "#";
	return outputStream;
}

istream& operator>>(istream& inputStream, Restaurant& restaurant) {
	std::string			rawLine;
	std::string			field;
	restaurant.menuItems.clear();
	
	if (!std::getline(inputStream, rawLine))
		return inputStream;
	std::stringstream	lineStream(rawLine);
	std::getline(lineStream, field, '#');
	restaurant.id = std::stoi(field);
	std::getline(lineStream, restaurant.name, '#');
	std::getline(lineStream, restaurant.cuisine, '#');
	std::getline(lineStream, field, '#');
	int itemCount = std::stoi(field);
	for (int i = 0;  i < itemCount;  i++)
	{
		if (!getline(lineStream, field, '#'))
			return inputStream;
		restaurant.menuItems.push_back(field);
	}
	
	return inputStream;
}
