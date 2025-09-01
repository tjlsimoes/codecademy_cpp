#include <vector>
#include <memory>
#include "BankAccount.hpp"

class Bank
{
	private:
		std::vector<std::unique_ptr<BankAccount>> bankAccounts;

	public:
		Bank();
		~Bank();
		void	createAccount(std::string accountNumber, int initBalance);
		BankAccount *findAccount(std::string accountNumber) const;
		int			transferMoney(std::string source, std::string target, int amount);
};