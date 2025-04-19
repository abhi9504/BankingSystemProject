#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    Account(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        accountHolder = name;
        balance = initialBalance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    string getHolderName() const {
        return accountHolder;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited successfully!\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn successfully!\n";
        } else {
            cout << "Invalid or insufficient balance.\n";
        }
    }

    void display() const {
        cout << "\nAccount Number: " << accountNumber
             << "\nHolder Name: " << accountHolder
             << "\nBalance: ₹ " << balance << "\n";
    }
};

class Bank {
private:
    vector<Account> accounts;

    Account* findAccount(int accNo) {
        for (auto& acc : accounts) {
            if (acc.getAccountNumber() == accNo)
                return &acc;
        }
        return nullptr;
    }

public:
    void createAccount() {
        int accNo;
        string name;
        double initialBalance;

        cout << "\nEnter Account Number: ";
        cin >> accNo;
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Initial Deposit: ₹";
        cin >> initialBalance;

        accounts.emplace_back(accNo, name, initialBalance);
        cout << "Account created successfully!\n";
    }

    void viewAccount() {
        int accNo;
        cout << "\nEnter Account Number: ";
        cin >> accNo;

        Account* acc = findAccount(accNo);
        if (acc) {
            acc->display();
        } else {
            cout << "Account not found.\n";
        }
    }

    void depositToAccount() {
        int accNo;
        double amount;

        cout << "\nEnter Account Number: ";
        cin >> accNo;
        cout << "Enter Deposit Amount: ₹";
        cin >> amount;

        Account* acc = findAccount(accNo);
        if (acc) {
            acc->deposit(amount);
        } else {
            cout << "Account not found.\n";
        }
    }

    void withdrawFromAccount() {
        int accNo;
        double amount;

        cout << "\nEnter Account Number: ";
        cin >> accNo;
        cout << "Enter Withdrawal Amount: ₹";
        cin >> amount;

        Account* acc = findAccount(accNo);
        if (acc) {
            acc->withdraw(amount);
        } else {
            cout << "Account not found.\n";
        }
    }

    void listAllAccounts() {
        if (accounts.empty()) {
            cout << "No accounts found.\n";
            return;
        }
        cout << "\nAll Accounts:\n";
        for (const auto& acc : accounts) {
            acc.display();
        }
    }
};

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\n======= BANKING SYSTEM MENU =======";
        cout << "\n1. Create Account";
        cout << "\n2. View Account";
        cout << "\n3. Deposit Money";
        cout << "\n4. Withdraw Money";
        cout << "\n5. List All Accounts";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: bank.createAccount(); break;
        case 2: bank.viewAccount(); break;
        case 3: bank.depositToAccount(); break;
        case 4: bank.withdrawFromAccount(); break;
        case 5: bank.listAllAccounts(); break;
        case 6: cout << "Exiting... Thank you!\n"; break;
        default: cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
