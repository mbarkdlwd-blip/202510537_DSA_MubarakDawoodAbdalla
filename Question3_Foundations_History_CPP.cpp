#include <iostream>
#include <string>

using namespace std;

const int MAX_TRANSACTIONS = 100;

double balanceAmount = 1000.0;
string transactionHistory[MAX_TRANSACTIONS];
int transactionCount = 0;

// Function to add transaction history
void addTransaction(string transaction)
{
    if (transactionCount < MAX_TRANSACTIONS)
    {
        transactionHistory[transactionCount] = transaction;
        transactionCount++;
    }
}

// Function to check balance
void checkBalance()
{
    cout << "\nCurrent Balance: $" << balanceAmount << endl;
}

// Function to deposit money
void depositMoney()
{
    double amount;

    cout << "\nEnter amount to deposit: $";
    cin >> amount;

    if (amount > 0)
    {
        balanceAmount += amount;

        addTransaction("Deposited $" + to_string(amount));

        cout << "Deposit successful.\n";
    }
    else
    {
        cout << "Invalid amount.\n";
    }
}

// Function to withdraw money
void withdrawMoney()
{
    double amount;

    cout << "\nEnter amount to withdraw: $";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount.\n";
    }
    else if (amount > balanceAmount)
    {
        cout << "Insufficient balance.\n";
    }
    else
    {
        balanceAmount -= amount;

        addTransaction("Withdrawn $" + to_string(amount));

        cout << "Withdrawal successful.\n";
    }
}

// Function to display transaction history
void displayTransactionHistory()
{
    cout << "\n----- Transaction History -----\n";

    if (transactionCount == 0)
    {
        cout << "No transactions available.\n";
    }
    else
    {
        for (int i = 0; i < transactionCount; i++)
        {
            cout << i + 1 << ". " << transactionHistory[i] << endl;
        }
    }
}

int main()
{
    int pin = 1234;
    int enteredPin;
    int attempts = 0;
    bool authenticated = false;

    // PIN Authentication (Max 3 Attempts)
    while (attempts < 3)
    {
        cout << "Enter ATM PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin)
        {
            authenticated = true;
            break;
        }
        else
        {
            attempts++;
            cout << "Incorrect PIN. Attempts left: "
                 << 3 - attempts << endl;
        }
    }

    if (!authenticated)
    {
        cout << "\nAccount locked. Too many incorrect attempts.\n";
        return 0;
    }

    int choice;

    do
    {
        cout << "\n========== ATM MENU ==========\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transaction History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            checkBalance();
            break;

        case 2:
            depositMoney();
            break;

        case 3:
            withdrawMoney();
            break;

        case 4:
            displayTransactionHistory();
            break;

        case 5:
            cout << "\nThank you for using the ATM.\n";
            break;

        default:
            cout << "\nInvalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}