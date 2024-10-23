#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    // Constructor to initialize account
    BankAccount(string name, int accNumber, double initialBalance) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    // Function to display account details
    void displayAccountDetails() {
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else {
            balance -= amount;
            cout << "Amount withdrawn: $" << amount << endl;
        }
    }

    // Function to check balance
    double getBalance() {
        return balance;
    }
};

int main() {
    // Create a bank account
    BankAccount account("John Doe", 123456, 500.0);

    int choice;
    double amount;

    do {
        cout << "\n--- Bank Management System ---\n";
        cout << "1. Display Account Details\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            account.displayAccountDetails();
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account.deposit(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account.withdraw(amount);
            break;
        case 4:
            cout << "Current balance: $" << account.getBalance() << endl;
            break;
        case 5:
            cout << "Exiting the system." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}