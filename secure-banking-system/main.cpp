#include <iostream>
#include "Bank.hpp"

using namespace std;

int main() {
	Bank swissBank;
	swissBank.createAccount("1001", 5000);
	swissBank.createAccount("1002", 3000);
	swissBank.createAccount("1003", 2000);

	BankAccount *account_1001 = swissBank.findAccount("1001");
	BankAccount *account_1002 = swissBank.findAccount("1002");
	BankAccount::Transaction	transaction;
	transaction.deposit(*account_1001, 1000);
	transaction.withdraw(*account_1002, 500);
	int result = swissBank.transferMoney("1001", "1002", 10000);
	switch (result)
	{
	case 1:
		std::cout << "Successful transfer!" << std::endl;
		break;
	case 2:
		std::cout << "Unsuccessful transfer: account not found!" << std::endl;
		break;
	case 3:
		std::cout << "Unsuccessful transfer: insufficient funds!" << std::endl;
		break;
	default:
		break;
	}
	return 0;
}
