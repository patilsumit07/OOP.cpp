
#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

class ATM {
private:
    double balance;

public:
    ATM(double b) {
        balance = b;
    }

    void checkBalance() {
        cout << "Current Balance: Rs. " << balance << endl;
    }

    void deposit(double amount) {
        if (amount <= 0)
            throw invalid_argument("Invalid deposit amount!");

        balance += amount;
        cout << "Amount deposited successfully." << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0)
            throw invalid_argument("Invalid withdrawal amount!");

        if (amount > balance)
            throw runtime_error("Insufficient funds!");

        balance -= amount;
        cout << "Amount withdrawn successfully." << endl;
    }
};

// C++ alternative to finally using RAII
class Finally {
public:
    ~Finally() {
        cout << "Transaction process completed.\n";
    }
};

int main() {
    ATM atm(5000);
    int choice;
    double amount;

    while (true) {
        cout << "\n===== ATM MENU =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 4) {
            cout << "Thank you for using ATM.\n";
            break;
        }

        if (choice < 1 || choice > 4) {
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        try {
            Finally finalAction;

            switch (choice) {
                case 1:
                    atm.checkBalance();
                    break;

                case 2:
                    cout << "Enter deposit amount: Rs. ";
                    if (!(cin >> amount))
                        throw invalid_argument("Amount must be numeric!");
                    atm.deposit(amount);
                    break;

                case 3:
                    cout << "Enter withdrawal amount: Rs. ";
                    if (!(cin >> amount))
                        throw invalid_argument("Amount must be numeric!");
                    atm.withdraw(amount);
                    break;
            }
        }
        catch (const invalid_argument& e) {
            cout << "Input Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (const runtime_error& e) {
            cout << "Transaction Error: " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
