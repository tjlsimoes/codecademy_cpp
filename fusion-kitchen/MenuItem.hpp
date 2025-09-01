#ifndef MENU_ITEM_HPP
#define MENU_ITEM_HPP

#include <string>
using namespace std;

class MenuItem {
	private:
		std::string name;
		double		price;
	public:
		MenuItem(std::string n, double p);
		void	display();
};

#endif