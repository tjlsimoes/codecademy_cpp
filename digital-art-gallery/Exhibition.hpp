#pragma once

#include "Artwork.hpp"
#include <vector>

class Exhibition {
public:
	std::vector<Artwork*> featuredArtworks;

	Exhibition() = default;
	Exhibition(const Exhibition &) = delete;
	void addToExhibition(Artwork* art);
	void showExhibition() const;
};
