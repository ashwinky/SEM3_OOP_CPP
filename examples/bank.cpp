#include <iostream>

using namespace std;

enum AccountType {
  CHECKING,
  SAVINGS,
};

class BankAccount {
  AccountType type = CHECKING;

 public:
  string name;
  int accountNumber;
  float balance;

  BankAccount(string name, int accountNumber, float balance) {
    this->name = name;
    this->accountNumber = accountNumber;
    this->balance = balance;
  }
};

class SavingsAccount : public BankAccount {
  AccountType type = SAVINGS;
  float interestRate = 0;
  float overdraft = 1000;

 public:
  SavingsAccount(string name, int accountNumber, float balance, float interestRate)
      : BankAccount(name, accountNumber, balance) {
    this->name = name;
    this->accountNumber = accountNumber;
    this->balance = balance;
    this->interestRate = interestRate;
  }

  void withdraw(float amount) {
    if (amount < balance + overdraft) {
      balance -= amount;
    } else {
      cout << "Insufficient funds" << endl;
    }
  }

  void deposit(float amount) {
    balance += amount;
    balance += balance * interestRate;
  }
};

class CurrentAccount : public BankAccount {
  AccountType type = CHECKING;
  float overdraft = 1000;

 public:
  CurrentAccount(string name, int accountNumber, float balance)
      : BankAccount(name, accountNumber, balance) {
    this->name = name;
    this->accountNumber = accountNumber;
    this->balance = balance;
  }

  void withdraw(float amount) {
    if (amount < balance + overdraft) {
      balance -= amount;
    } else {
      cout << "Insufficient funds" << endl;
    }
  }

  void deposit(float amount) { balance += amount; }
};

int main() {
  cout << "Enter the name of the account holder: ";
  string name;
  cin >> name;

  cout << "Enter the account number: ";
  int accountNumber;
  cin >> accountNumber;

  cout << "Enter opening balance: ";
  float balance;
  cin >> balance;

  cout << "Enter account type (1 for savings, 2 for current): ";
  int accountType;
  cin >> accountType;

  if (accountType == 0) {
    CurrentAccount account(name, accountNumber, balance);

    cout << "New account created for " << account.name << " with account number "
         << account.accountNumber << " and balance " << account.balance << "." << endl;

    while (true) {
      cout << "Enter amount to withdraw: ";
      float amount;
      cin >> amount;
      account.withdraw(amount);
      cout << "New balance: " << account.balance << endl;

      cout << "Enter amount to deposit: ";
      cin >> amount;
      account.deposit(amount);
      cout << "New balance: " << account.balance << endl;
    }

  } else {
    SavingsAccount account(name, accountNumber, balance, 0.02);

    cout << "New account created for " << account.name << " with account number "
         << account.accountNumber << " and balance " << account.balance << "." << endl;

    while (true) {
      cout << "Enter amount to withdraw: ";
      float amount;
      cin >> amount;
      account.withdraw(amount);
      cout << "New balance: " << account.balance << endl;

      cout << "Enter amount to deposit: ";
      cin >> amount;
      account.deposit(amount);
      cout << "New balance: " << account.balance << endl;
    }
  }
}