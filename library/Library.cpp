#include "Library.hpp"
#include "removeElement.hpp"
#include <iostream>

using namespace std;

Library::Library(): reservedCount(0) {};

int		Library::totalBorrowedBooks = 0;

int		Library::getTotalBorrowedBooks()
{
	return totalBorrowedBooks;
}


void	Library::listBooks()
{
	for (auto book : bookList)
	{
		std::cout << book << " ";
	}
	std::cout << std::endl;
}

void	Library::addBook(std::string title, double bookCost)
{
	
	if (bookList.size() < 100)
	{
		if (libraryBudget - bookCost >= 0)
			libraryBudget -= bookCost;
		else
		{
			std::cout << "Insufficient funds" << std::endl;
			return ;
		}
		bookList.push_back(title);
	}
	else
		std::cout << "Library is full!" << std::endl;
}

bool	Library::borrowBook(std::string title)
{
	for (auto book : bookList)
	{
		if (book == title)
		{
			removeElement(bookList, book);
			std::cout << "Book borrowed!" << std::endl;
			totalBorrowedBooks++;
			return true;
		}
	}
	std::cout << "Book not found!" << std::endl;
	return false;
}



void	Library::reserveBook(std::string title) const
{
	int	bookListCount = count(bookList.begin(), bookList.end(), title);
	int	reserveBookCount = count(reserveBooks.begin(), reservedBooks.end(), title);

	if (bookListCount >= 1 && reservedBookCount == 0)
	{
		reservedBooks.push_back(title);
		reservedCount++;
		std::cout << "Book reserved: " << title << "\n"
		<< "Reserved book count: " << reservedCount << std::endl;
	}
	else
		std::cout << "Book not reserved!" << std::endl;
}