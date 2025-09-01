#include "Library.hpp"
#include <iostream>

using namespace std;

double libraryBudget = 5000;
int main() {
  std::cout 
  	<< "Current library budget is: "
	<< libraryBudget 
	<< std::endl;

	Library myLibrary;
	myLibrary.addBook("The Great Gatsby", 300);
	myLibrary.addBook("1984", 400);
	myLibrary.addBook("To Kill a Mockingbird", 350);

	myLibrary.listBooks();
	myLibrary.reserveBook("1984");
	myLibrary.borrowBook("To Kill a Mockingbird");
	std::cout 
		<< "The total number of borrowed books is: "
		<< myLibrary.getTotalBorrowedBooks() << std::endl;
}