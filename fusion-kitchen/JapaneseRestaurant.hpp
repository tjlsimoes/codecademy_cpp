#ifndef JAPANESE_RESTAURANT_HPP
#define JAPANESE_RESTAURANT_HPP

#include "Restaurant.hpp"

class JapaneseRestaurant : virtual public Restaurant
{
	private:
		bool hasTatami;
	public:
		JapaneseRestaurant(std::string name, std::string addr, bool tatamiAvailable);
		void	describeCuisine();
};

#endif