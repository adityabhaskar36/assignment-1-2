#include <iostream>
using namespace std;

class BankAccount {
private:
    static int totalAccounts;
    static const double MIN_HIGH_VALUE;
    int accountNumber;
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {
        accountNumber = ++totalAccounts;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient balance for withdrawal.\n";
        }
    }

    void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }

    bool isHighValueAccount() const {
        return balance >= MIN_HIGH_VALUE;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

int BankAccount::totalAccounts = 0;
const double BankAccount::MIN_HIGH_VALUE = 1000.0;

class Bank {
private:
    static const int MAX_ACCOUNTS = 100; // Maximum number of accounts
    BankAccount* accounts[MAX_ACCOUNTS];
    int accountCount;

public:
    Bank() : accountCount(0) {}

    ~Bank() {
        for (int i = 0; i < accountCount; ++i) {
            delete accounts[i];
        }
    }

    void addAccount(double initialBalance) {
        if (accountCount < MAX_ACCOUNTS) {
            accounts[accountCount++] = new BankAccount(initialBalance);
        } else {
            cout << "Maximum account limit reached.\n";
        }
    }

    void depositToAccount(int accountNumber, double amount) {
        for (int i = 0; i < accountCount; ++i) {
            if (accounts[i]->getAccountNumber() == accountNumber) {
                accounts[i]->deposit(amount);
                return;
            }
        }
        cout << "Account not found.\n";
    }

    void withdrawFromAccount(int accountNumber, double amount) {
        for (int i = 0; i < accountCount; ++i) {
            if (accounts[i]->getAccountNumber() == accountNumber) {
                accounts[i]->withdraw(amount);
                return;
            }
        }
        cout << "Account not found.\n";
    }

    void displayAllAccounts() const {
        for (int i = 0; i < accountCount; ++i) {
            accounts[i]->display();
        }
    }

    void displayHighValueAccounts() const {
        for (int i = 0; i < accountCount; ++i) {
            if (accounts[i]->isHighValueAccount()) {
                accounts[i]->display();
            }
        }
    }
};

int main() {
    Bank bank;

    bank.addAccount(500);
    bank.addAccount(1500);
    bank.addAccount(2500);
    bank.addAccount(800);
    bank.addAccount(300);

    cout << "\nDepositing $200 to account 1...\n";
    bank.depositToAccount(1, 200);

    cout << "\nWithdrawing $100 from account 3...\n";
    bank.withdrawFromAccount(3, 100);

    cout << "\nAll Accounts:\n";
    bank.displayAllAccounts();

    cout << "\nHigh-Value Accounts:\n";
    bank.displayHighValueAccounts();

    cout << "\nTotal Number of Accounts: " << BankAccount::getTotalAccounts() << endl;

    return 0;
}
