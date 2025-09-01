#pragma once

#include <string>

class Artwork {
	public:
		std::string title;
		std::string artistName;
		int id;
		std::string medium;
		double price;
		bool sold;

		Artwork() = delete;
		Artwork(
			std::string artTitle,
			std::string artistFullName,
			int artworkId,
			std::string artworkMedium,
			double artworkPrice,
			bool soldStatus = false
		);
		Artwork(const Artwork& other);
		Artwork(Artwork&& other);

		void markAsSold();
};