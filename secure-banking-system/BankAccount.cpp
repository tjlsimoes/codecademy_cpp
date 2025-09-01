#include "BankAccount.hpp"

BankAccount::BankAccount(std::string acc_number,
						double bal) : accountNumber(acc_number), balance(bal) {};

BankAccount::~BankAccount()
{
	std::cout << "BankAccount destructor called" << std::endl;
}

std::string BankAccount::getAccountNumber() const
{
	return accountNumber;
}

double	BankAccount::getBalance() const
{
	return balance;
}

void		BankAccount::setAccountNumber(std::string newAccountNumber)
{
	accountNumber = newAccountNumber;
}
void		BankAccount::setBalance(double newBalance)
{
	balance = newBalance;
}

void	BankAccount::Transaction::deposit(BankAccount & account, double amount)
{
	std::cout
		<< "Account " << account.getAccountNumber()
		<< ": Depositing " << amount << std::endl;
	account.setBalance(account.getBalance() + amount);
	std::cout
	<< "Account " << account.getAccountNumber()
	<< " new balance: " << account.getBalance() << std::endl;
}

void	BankAccount::Transaction::withdraw(BankAccount & account, double amount)
{
	if (account.getBalance() >= amount)
	{
		std::cout
		<< "Account " << account.getAccountNumber()
		<< ": Withdrawing " << amount << std::endl;
		account.setBalance(account.getBalance() - amount);
		std::cout
		<< "Account " << account.getAccountNumber()
		<< " new balance: " << account.getBalance() << std::endl;
	}
	else
		std::cout
		<< "Account " << account.getAccountNumber()
		<< ", with balance " << account.getBalance() 
		<< ": Insufficient funds to withdraw"
		<< amount << std::endl;
}