#include <iostream>
using namespace std;

// Define the structures for Customer and Account
struct Customer {
    int customerId;
    char name[50];
};

struct Account {
    int accountNumber;
    int customerId;
    double balance;
};

// Function to add a new customer
void addCustomer(Customer* customers, int& numCustomers) {
    cout << "Enter customer ID: ";
    cin >> customers[numCustomers].customerId;
    cout << "Enter customer name: ";
    cin.ignore(); // Ignore the newline character left by previous input
    cin.getline(customers[numCustomers].name, 50);

    numCustomers++;
    cout << "CUSTOMER CREATED SUCCESSFULLY!" << endl;
}

// Function to create a new account for a customer
void createAccount(Account* accounts, int& numAccounts, int customerId) {
    cout << "Enter account ID: ";
    cin >> accounts[numAccounts].accountNumber;
    accounts[numAccounts].customerId = customerId;
    cout << "Enter initial balance: ";
    cin >> accounts[numAccounts].balance;

    numAccounts++;
    cout << "ACCOUNT CREATED SUCCESSFULLY!" << endl;
}

// Function to perform a deposit
void deposit(Account* accounts, int numAccounts, int accountNumber, double amount) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            cout << "SUCCESSFULLY DEPOSITED! AVAILABLE BALANCE IS : " << accounts[i].balance << endl;
            return;
        }
    }

    cout << "Account not found. Deposit failed." << endl;
}

// Function to perform a withdrawal
void withdraw(Account* accounts, int numAccounts, int accountNumber, double amount) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                cout << "WITHDRAWAL SUCCESSFULLY! NEW BALANCE: " << accounts[i].balance << endl;
            } else {
                cout << "Insufficient funds for withdrawal. Withdrawal failed." << endl;
            }
            return;
        }
    }

    cout << "Account not found. Withdrawal failed." << endl;
}

// Function to display account information
void displayAccountInfo(Account* accounts, int numAccounts) {
    cout << "--- Account Details ---" << endl;
    for (int i = 0; i < numAccounts; i++) {
        cout << "Account ID: " << accounts[i].accountNumber << endl;
        cout << "Customer ID: " << accounts[i].customerId << endl;
        cout << "Balance: " << accounts[i].balance << endl;
        cout << "-----------------------" << endl;
    }
}

int main() {
    Customer customers[100]; // Assuming you have space for 100 customers
    Account accounts[100];   // Assuming you have space for 100 accounts
    int numCustomers = 0;
    int numAccounts = 0;

    int choice;
    do {
        cout << "<<<<<<<< BANK MANAGEMENT SYSTEM >>>>>>>>" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Create Account" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Display Accounts" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addCustomer(customers, numCustomers);
                break;
            case 2: {
                int customerId;
                cout << "Enter customer ID for the account: ";
                cin >> customerId;
                createAccount(accounts, numAccounts, customerId);
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                cout << "Enter account ID for deposit: ";
                cin >> accountNumber;
                cout << "Enter deposit amount: ";
                cin >> amount;
                deposit(accounts, accountNumber, amount);
                break;
            }
            case 4: {
                int accountNumber;
                double amount;
                cout << "Enter account ID for withdrawal: ";
                cin >> accountNumber;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                withdraw(accounts, accountNumber, amount);
                break;
            }
            case 5:
                displayAccountInfo(accounts, numAccounts);
                break;
            case 0:
                cout << "************************************************ EXIT PROGRAM ***************************************************" << endl;
                break;
            default:
                cout << "INVALID CHOICE PLEASE TRY AGAIN." << endl;
        }
    } while (choice != 0);
    return 0;
}