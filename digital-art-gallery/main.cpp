#include "Gallery.hpp"
#include "Exhibition.hpp"
#include <iostream>
#include <iomanip>

int main() {
	std::cout << std::fixed << std::setprecision(0);
	Artwork sunflowers("Sunflowers", "Vincent van Gogh", 1, "oil painting", 1200000);
	std::cout
	<< "ID: " << sunflowers.id << ", Title: " << sunflowers.title
	<< ", Artist: " << sunflowers.artistName << ", Medium: "
	<< sunflowers.medium << ", Price: " << sunflowers.price
	<< std::endl;

	Artwork starryNight("Starry Night", "Vincent van Gogh", 2, "oil painting", 1000000);

	Artwork galleryCopy(starryNight);

	Artwork	artworkForTransfer = std::move(starryNight);
	Artwork auctionTransfer = std::move(artworkForTransfer);

	std::cout << "----------------------------------------" << std::endl;

	std::cout
	<< "ID: " << galleryCopy.id << ", Title: " << galleryCopy.title
	<< ", Artist: " << galleryCopy.artistName << ", Medium: "
	<< galleryCopy.medium << ", Price: " << galleryCopy.price
	<< std::endl;

	std::cout << "----------------------------------------" << std::endl;

	std::cout
	<< "ID: " << starryNight.id << ", Title: " << starryNight.title
	<< ", Artist: " << starryNight.artistName << ", Medium: "
	<< starryNight.medium << ", Price: " << starryNight.price
	<< std::endl;

	std::cout << "----------------------------------------" << std::endl;

	std::cout
	<< "ID: " << auctionTransfer.id << ", Title: " << auctionTransfer.title
	<< ", Artist: " << auctionTransfer.artistName << ", Medium: "
	<< auctionTransfer.medium << ", Price: " << auctionTransfer.price
	<< std::endl;

	Artwork theScream("The Scream", "Eduard Munch", 3, "tempera", 1500000);
	Artwork digitalDream("Digital Dream", "Alice Doe", 4, "digital art", 5000);

	Gallery	gallery;
	gallery.addArtwork(std::move(sunflowers));
	gallery.addArtwork(std::move(theScream));
	gallery.addArtwork(std::move(digitalDream));
	gallery.displayGallery();

	std::cout << "----------------------------------------" << std::endl;

	Exhibition exhibition;
	exhibition.addToExhibition(&gallery.artworks[0]);
	exhibition.addToExhibition(&gallery.artworks[2]);
	exhibition.showExhibition();

	std::cout << "----------------------------------------" << std::endl;
	
	gallery.sellArtwork(4);
	exhibition.showExhibition();
	return 0;
}
