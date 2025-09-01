#include <vector>
#include <string>

using namespace std;

extern double libraryBudget;

//Since the variable is declared globally in Library.hpp
// and will be used in main.cpp, it should be declared
// outside the Library class and using the extern variable.

class Library {
	private:
		std::vector<std::string> bookList;
		static int	totalBorrowedBooks;
		mutable int reservedCount;
		mutable std::vector<std::string> reservedBooks;
	
	public:
		Library();
		void	addBook(std::string title, double bookCost);
		bool	borrowBook(std::string title);
		void	listBooks();
		int		getTotalBorrowedBooks();
		void	reserveBook(std::string title) const;
};