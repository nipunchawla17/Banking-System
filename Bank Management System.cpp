#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class MyBank {
private:
    string name, address;
    string acc_type;
    float balance;
    int account_number;

public:
    MyBank();
    void open_account();
    void deposit_money();
    void withdraw_money();
    void display_account();
    int get_account_number();
};

MyBank::MyBank() {
    balance = 0;
}

void MyBank::open_account() {
    cout << "Enter your full name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter your address: ";
    getline(cin, address);

    cout << "What type of account you want to open Savings or Current: ";
    cin >> acc_type;

    cout << "Enter initial deposit amount: ";
    cin >> balance;

    // Generate a random account number
    srand(time(nullptr));
    account_number = rand() % 10000 + 1;

    cout << "Account created successfully. Your account number is: " << account_number << endl;
}

void MyBank::deposit_money() {
    float amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    balance += amount;
    cout << "Amount deposited successfully. Updated balance: " << balance << endl;
}

void MyBank::withdraw_money() {
    float amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount > balance) {
        cout << "Insufficient balance. Withdrawal failed." << endl;
    } else {
        balance -= amount;
        cout << "Amount withdrawn successfully. Updated balance: " << balance << endl;
    }
}

void MyBank::display_account() {
    cout << "Account Holder Name: " << name << endl
         << "Address: " << address << endl
         << "Account Type: " << acc_type << endl
         << "Balance: " << balance << endl
         << "Account Number: " << account_number << endl
         << endl;
}

int MyBank::get_account_number() {
    return account_number;
}

int main() {
    int choice;
    vector<MyBank> accounts;

    while (true) {
        cout << "\n1) Open account \n";
        cout << "2) Deposit money \n";
        cout << "3) Withdraw money \n";
        cout << "4) Display Account \n";
        cout << "5) Exit \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                MyBank newAccount;
                newAccount.open_account();
                accounts.push_back(newAccount);
                break;
            }
            case 2: {
                int accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                for (MyBank &acc : accounts) {
                    if (acc.get_account_number() == accountNumber) {
                        acc.deposit_money();
                        break;
                    }
                }
                break;
            }
            case 3: {
                int accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                for (MyBank &acc : accounts) {
                    if (acc.get_account_number() == accountNumber) {
                        acc.withdraw_money();
                        break;
                    }
                }
                break;
            }
            case 4: {
                int accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                for (MyBank &acc : accounts) {
                    if (acc.get_account_number() == accountNumber) {
                        acc.display_account();
                        break;
                    }
                }
                break;
            }
            case 5:
                cout << "Exiting...";
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
