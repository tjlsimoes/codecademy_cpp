#include <string>
#include <iostream>

using namespace std;

class BankAccount {
	private:
		std::string accountNumber;
		double		balance;
	public:
		BankAccount(std::string acc_number, double bal);
		~BankAccount();
		class		Transaction
		{
			public:
				void	deposit(BankAccount & account, double	amount);
				void	withdraw(BankAccount & account, double amount);
		};
		std::string getAccountNumber() const;
		double		getBalance() const;
		void		setAccountNumber(std::string newAccountNumber);
		void		setBalance(double newBalance);
};