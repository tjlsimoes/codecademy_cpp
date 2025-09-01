#include "Bank.hpp"
#include <memory>
#include <iostream>

Bank::Bank() {};
Bank::~Bank()
{
	std::cout << "Bank destructor called" << std::endl;
}

void	Bank::createAccount(std::string accountNumber, int initBalance)
{
	for (std::unique_ptr<BankAccount> & account : bankAccounts)
	{
		if (account->getAccountNumber() == accountNumber)
		{
			std::cout << "Acount " 
			<< accountNumber << " already exists"
			<< std::endl;
			return;
		}
	}
	std::cout << "Creating account " 
	<< accountNumber << " with initial balance of " 
	<< initBalance << std::endl;
	bankAccounts.push_back(std::make_unique<BankAccount>(accountNumber, initBalance));
}

BankAccount *Bank::findAccount(std::string accountNumber) const
{
	for (const std::unique_ptr<BankAccount> & account : bankAccounts)
	{
		if (account->getAccountNumber() == accountNumber)
		{
			return account.get();
		}
	}
	return (nullptr);
}

int			Bank::transferMoney(std::string source, std::string target, int amount)
{
	BankAccount *source_acc = findAccount(source);
	BankAccount *target_acc = findAccount(target);
	if (!source_acc || !target_acc)
		return 2;
	if ((*source_acc).getBalance() < amount)
		return 3;
	(*source_acc).setBalance((*source_acc).getBalance() - amount);
	(*target_acc).setBalance((*target_acc).getBalance() + amount);
	// BankAccount::Transaction transaction;
	// transaction.withdraw(*source_acc, amount);
	// transaction.deposit(*target_acc, amount);
	return 1;
}