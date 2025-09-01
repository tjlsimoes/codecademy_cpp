#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include <string>
#include <vector>
#include "MenuItem.hpp"
using namespace std;

class Restaurant {
	private:
		std::string	name;
		std::string	address;
	protected:
		std::vector<MenuItem> menu;
	public:
		Restaurant(std::string n, std::string addr);
		void	displayInfo();
		void	describeCuisine();
		void	addMenuItem(MenuItem item);
		void	displayMenu();
};

#endif
