#include <iostream>
#include <limits>
using namespace std;

class BankAccount{

protected:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    virtual void withdraw(double amount) = 0;
    virtual void deposit(double amount) = 0;
    virtual void menu() = 0;

    double getBalance() const {
        return balance;
    }
};

class SavingsAccount : public BankAccount{

private:
    const double minBalance = 1000;

public:
    SavingsAccount(double initialBalance) : BankAccount(initialBalance) {}

    void deposit(double amount) override
    {
        bool validInput = false;

        while (!validInput){

            cout << "Enter deposit amount: ";
            cin >> amount;

            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number greater than zero." << endl;
            }
            else if (balance == 0 && amount < minBalance){
                cout << "Minimum initial deposit must be at least 1000." << endl;
            }
            else if (amount > 0){
                balance += amount;
                cout << "Deposit successful! New Balance: " << balance << endl;
                validInput = true;
            }
            else{
                cout << "Invalid deposit amount!" << endl;
            }
        }
        cout << "Returning to Main Menu..." << endl;
        system("pause");
    }

    void withdraw(double amount) override{

        if (balance == 0) {
            cout << "You have no funds to withdraw!" << endl << "Your current balance is 0" << endl;
            system("pause");
            return;
        }

        bool validInput = false;

        while (!validInput) {
            cout << "Enter withdrawal amount: ";
            cin >> amount;

            if (cin.fail()) {

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input!" << endl;
            }
            else if (amount > 0 && balance - amount >= minBalance){
                balance -= amount;
                cout << "Withdrawal successful! New Balance: " << balance << endl;
                validInput = true;
            }
            else if (amount > balance){
                cout << "Insufficient funds! Please enter an amount within your account balance." << endl << "Account Balance: " << balance << endl << endl;
            }
            else if (balance - amount < minBalance){
                cout << "Unable to withdraw, maintaining a balance of 1000 is required!" << endl << "Account Balance: " << balance << endl << endl;
                break;
            }
            else {
                cout << "Invalid amount!" << endl;
                break;
            }
        }

        cout << "Returning to Main Menu..." << endl;
        system("pause");
    }

    void menu() override {

        int choice = 0;
        do {
            system("cls");

            cout << endl << "Savings Account Menu" << endl;
            
            cout << "1 - Deposit" << endl;
            cout << "2 - Withdraw" << endl;
            cout << "3 - Check Balance" << endl;
            cout << "4 - Back" << endl;

            cout << "Enter choice: ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 4) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Invalid input! Please try again." << endl;
                system("pause");
            }
            else{
                switch (choice){
                case 1:
                    system("cls");
                    cout << "Deposit" << endl << endl;
                    deposit(0);
                    break;
                case 2:
                    system("cls");
                    cout << "Withdraw" << endl << endl;
                    withdraw(0);
                    break;
                case 3:
                    system("cls");
                    cout << "Check Balance" << endl;
                    cout << endl << "Current Balance: " << getBalance() << endl;
                    system("pause");
                    break;
                case 4:
                    cout << endl << "Returning to Main Menu..." << endl;
                    system("pause");
                    break;
                }
            }
        } while (choice != 4);
    }
};

class CurrentAccount : public BankAccount {

public:
    CurrentAccount(double initialBalance) : BankAccount(initialBalance) {}

    void deposit(double amount) override {

        bool validInput = false;
        while (!validInput) {
            cout << "Enter deposit amount: ";
            cin >> amount;
            if (cin.fail()) {

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Invalid input! Please try again." << endl;
            }
            else if (amount > 0){
                balance += amount;
                cout << "Deposit successful! New Balance: " << balance << endl;
                validInput = true;
            }
            else{
                cout << "Invalid deposit amount!" << endl;
            }
        }
        cout << "Returning to Main Menu..." << endl;
        system("pause");
    }

    void withdraw(double amount) override {

        if (balance == 0) {
            cout << "You have no funds to withdraw!" << endl << "Your current balance is 0" << endl;
            system("pause");
            return;
        }

        bool validInput = false;
        while (!validInput) {
            cout << "Enter withdrawal amount: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please try again." <<endl;
                system("pause");
            }
            else if (amount > 0 && amount <= balance){
                balance -= amount;
                cout << "Withdrawal successful! New Balance: " << balance << endl;
                validInput = true;
            }
            else if (amount > balance){
                cout << "Insufficient funds! Please enter an amount within your account balance." << endl << "Account Balance: " << balance << endl;
            }
            else
            {
                cout << "Invalid amount!" << endl;
            }
        }
        cout << "Returning to Main Menu..." << endl;
        system("pause");
    }

    void menu() override {

        int choice = 0;

        do {
            system("cls");

            cout << endl << "Current Account Menu" << endl;

            cout << "1 - Deposit" << endl;
            cout << "2 - Withdraw" << endl;
            cout << "3 - Check Balance" << endl;
            cout << "4 - Back" << endl;

            cout << "Enter choice: ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 4){

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please try again." << endl;
                system("pause");
            }
            else {
                switch (choice) {

                case 1:
                    system("cls");
                    cout << "Deposit" << endl << endl;
                    deposit(0);
                    break;
                case 2:
                    system("cls");
                    cout << "Withdraw" << endl << endl;
                    withdraw(0);
                    break;
                case 3:
                    system("cls");
                    cout << "Check Balance" << endl;
                    cout << endl << "Current Balance: " << getBalance() << endl;
                    system("pause");
                    break;
                case 4:
                    cout << endl << "Returning to Main Menu..." << endl;
                    system("pause");
                    break;
                }
            }
        } while (choice != 4);
    }
};

int main() {

    SavingsAccount savings(0);
    CurrentAccount current(0);

    int choice = 0;

    do {
        system("cls");

        cout << endl<< "Main Menu" << endl;
        
        cout << "1 - Savings Account" << endl;
        cout << "2 - Current Account" << endl;
        cout << "3 - Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 3){

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Invalid input! Please try again." << endl;
            system("pause");
        }
        else {
            switch (choice) {
            case 1:
                savings.menu();
                break;
            case 2:
                current.menu();
                break;
            case 3:
                cout << "Exiting the system..." << endl;
                break;
            }
        }
    } while (choice != 3);

    return 0;
}