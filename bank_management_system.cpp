
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_ACCOUNTS = 100;

int accountNumbers[MAX_ACCOUNTS];
string customerNames[MAX_ACCOUNTS];
string passwords[MAX_ACCOUNTS];
double balances[MAX_ACCOUNTS];
int totalAccounts = 0;

int findAccountIndex(int accountNumber);
void manager();
void employee();
void atm();
// manager function
void balanceInquiry();
void closeAccount();
void displayAccounts();
void mainpanel();
void createAccount();
// employee Function
void deposit();
void withdrawal();
void balanceInquiry();
void displayAccounts();
void billpayment();
// file handling
void saveDataToFile();
void loadDataFromFile();

void saveDataToFile()
{
    ofstream outFile("accounts.txt");

    if (!outFile)
    {
        cout << "Error opening file for writing." << endl;
        return;
    }

    outFile << totalAccounts << endl;
    for (int i = 0; i < totalAccounts; i++)
    {
        outFile << accountNumbers[i] << " " << customerNames[i] << " " << passwords[i] << " " << balances[i] << endl;
    }

    outFile.close();
}

void loadDataFromFile()
{
    ifstream inFile("accounts.txt");

    if (!inFile)
    {
        cout << "No existing data found." << endl;
        return;
    }

    inFile >> totalAccounts;
    for (int i = 0; i < totalAccounts; i++)
    {
        inFile >> accountNumbers[i] >> customerNames[i] >> passwords[i] >> balances[i];
    }

    inFile.close();
}

void manager()
{
    system("cls");
    int choice;
    system("cls");
    string manager_Username = "manager";
    string manager;
    string password = "12345";
    string pass;
    bool found = false;
    cout << "\n Enter your username: ";
    cin >> manager;
    cout << "\n Enter your Password: ";
    cin >> pass;
    if (manager == manager_Username && pass == password)
    {
        found = true;
    }
    else
    {
        cout << "Invalid Username or Password" << endl;
        found = false;
        return;
    }
    while (found)
    {
        system("cls");
        cout << "\n\t Welcome Manager" << endl;
        cout << "\n 1.Create Account " << endl;
        cout << "\n 2.Balance Inquiry " << endl;
        cout << "\n 3.Display All Account " << endl;
        cout << "\n 4.Close Account " << endl;
        cout << "\n 5.Logout " << endl;
        cout << "\n 6.Exit" << endl;
        cout << "\nEnter Your Choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            balanceInquiry();
            break;
        case 3:
            displayAccounts();
            break;
        case 4:
            closeAccount();
            break;
        case 5:
            mainpanel();
            break;
        case 6:
            exit(0);
        default:
            cout << "You have entered an invalid choice" << endl;
        }
        system("pause");
    }
}

void employee()
{
    int choice;

    while (true)
    {
        system("cls");
        cout << "\nWelcome to Employee Section\n";
        cout << "1. Deposit\n";
        cout << "2. Withdrawal\n";
        cout << "3. Balance Inquiry\n";
        cout << "4. Display All Accounts\n";
        cout << "5. Bill Payment\n";
        cout << "6. Back to Main.\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            deposit();
            break;
        case 2:
            withdrawal();
            break;
        case 3:
            balanceInquiry();
            break;
        case 4:
            displayAccounts();
            break;
        case 5:
            billpayment();
            break;
        case 6:
            mainpanel();
        case 7:
            cout << "Exiting program.\n";
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";
        }
        system("pause");
    }
}
void atm()
{
    system("cls");
    int option, amount;
    int accountNumber;

    cout << "Enter account number: ";
    cin >> accountNumber;

    int index = findAccountIndex(accountNumber);
    if (index == -1)
    {
        cout << "Account not found." << endl;
        return;
    }

    while (true)
    {
        system("cls");
        cout << "ATM Menu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Back" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Your balance is: " << balances[index] << endl;
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (amount > balances[index])
            {
                cout << "Insufficient balance." << endl;
            }
            else
            {
                balances[index] -= amount;
                cout << "Amount withdrawn: " << amount << endl;
                cout << "Remaining balance: " << balances[index] << endl;
            }
            break;
        case 3:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            balances[index] += amount;
            cout << "Amount deposited: " << amount << endl;
            cout << "New balance: " << balances[index] << endl;
            break;
        case 4:
            mainpanel();
        case 5:
            cout << "Thank you for using our ATM. Goodbye!" << endl;
            return;
        default:
            cout << "Invalid option. Please choose again." << endl;
            break;
        }
        system("pause");
    }
}

int findAccountIndex(int accountNumber)
{
    for (int i = 0; i < totalAccounts; i++)
    {
        if (accountNumbers[i] == accountNumber)
        {
            return i;
        }
    }
    return -1;
}

void createAccount()
{
    if (totalAccounts >= MAX_ACCOUNTS)
    {
        cout << "Error: Maximum number of accounts reached." << endl;
        return;
    }
    system("cls");
    int accountNumber;
    string customerName;
    string password;
    double balance = 0.0;

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, customerName);

    cout << "Set account password: ";
    cin >> password;

    accountNumbers[totalAccounts] = accountNumber;
    customerNames[totalAccounts] = customerName;
    passwords[totalAccounts] = password;
    balances[totalAccounts] = balance;

    totalAccounts++;
    cout << "Account created successfully." << endl;
    saveDataToFile();
}

void balanceInquiry()
{
    system("cls");
    int accountNumber;

    cout << "Enter account number: ";
    cin >> accountNumber;

    int index = findAccountIndex(accountNumber);
    if (index == -1)
    {
        cout << "Account not found." << endl;
        return;
    }

    cout << "Account balance: " << balances[index] << endl;
}

void closeAccount()
{
    system("cls");
    int accountNumber;

    cout << "Enter account number: ";
    cin >> accountNumber;

    int index = findAccountIndex(accountNumber);
    if (index == -1)
    {
        cout << "Account not found." << endl;
        return;
    }
    for (int i = index; i < totalAccounts - 1; i++)
    {
        accountNumbers[i] = accountNumbers[i + 1];
        customerNames[i] = customerNames[i + 1];
        passwords[i] = passwords[i + 1];
        balances[i] = balances[i + 1];
    }

    totalAccounts--;
    cout << "Account closed successfully." << endl;
    saveDataToFile();
}

void displayAccounts()
{
    system("cls");
    cout << "Accounts in the bank:" << endl;
    for (int i = 0; i < totalAccounts; i++)
    {
        cout << "Account Number:\t" << accountNumbers[i] << "\t Customer Name:\t" << customerNames[i]
             << " \tBalance:\t" << balances[i] << endl;
    }
}

void deposit()
{
    system("cls");
    int accountNumber;
    double amount;

    cout << "Enter account number: ";
    cin >> accountNumber;

    int index = findAccountIndex(accountNumber);
    if (index == -1)
    {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter the amount to deposit: ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount. Deposit amount must be positive.\n";
        return;
    }

    balances[index] += amount;
    cout << "Deposit successful. New balance: " << balances[index] << endl;
    saveDataToFile();
}

void withdrawal()
{
    system("cls");
    int accountNumber;
    double amount;

    cout << "Enter account number: ";
    cin >> accountNumber;

    int index = findAccountIndex(accountNumber);
    if (index == -1)
    {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter the amount to withdraw: ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount. Withdrawal amount must be positive.\n";
        return;
    }

    if (balances[index] < amount)
    {
        cout << "Insufficient balance.\n";
        return;
    }

    balances[index] -= amount;
    cout << "Withdrawal successful. New balance: " << balances[index] << endl;
    saveDataToFile();
}
void billpayment()
{
    system("cls");
    int choice, accountNumber, bill_number, amount;
    cout << "1.Electricity bill" << endl;
    cout << "2.Sui gas bill" << endl;
    cout << "3.Water bill" << endl;
    cout << "Select which bill you want to pay(1-3):";
    cin >> choice;

    int index; // Declare index here once

    switch (choice)
    {
    case 1:
        cout << "Enter your Electricity bill number:";
        cin >> bill_number;
        cout << "Enter bill amount:";
        cin >> amount;
        if (amount <= 0)
        {
            cout << "Invalid amount. Amount must be positive.\n";
            return;
        }

        if (balances[index] < amount)
        {
            cout << "Insufficient amount.\n";
            return;
        }

        balances[index] -= amount;
        cout << "Enter your account number:";
        cin >> accountNumber;
        index = findAccountIndex(accountNumber); // Assign value here
        break;
    case 2:
        cout << "Enter your Sui Gas bill number:";
        cin >> bill_number;
        cout << "Enter bill amount:";
        cin >> amount;
        if (amount <= 0)
        {
            cout << "Invalid amount. Amount must be positive.\n";
            return;
        }

        if (balances[index] < amount)
        {
            cout << "Insufficient amount.\n";
            return;
        }

        balances[index] -= amount;
        cout << "Enter your account number:";
        cin >> accountNumber;
        index = findAccountIndex(accountNumber); // Assign value here
        break;
    case 3:
        cout << "Enter your Water bill number:";
        cin >> bill_number;
        cout << "Enter bill amount:";
        cin >> amount;
        if (amount <= 0)
        {
            cout << "Invalid amount. Amount must be positive.\n";
            return;
        }

        if (balances[index] < amount)
        {
            cout << "Insufficient amount.\n";
            return;
        }

        balances[index] -= amount;
        cout << "Enter your account number:";
        cin >> accountNumber;
        index = findAccountIndex(accountNumber); // Assign value here
        break;
    }

    if (index == -1)
    {
        cout << "Account not found.\n";
        return;
    }

    cout << "Bill is paid successfully";
    saveDataToFile();
}

void mainpanel()
{
    loadDataFromFile();
    system("cls");
    int a;
    cout << "\n\t\t\t************** Bank Management System ************** " << endl;
    cout << "\n 1.Manager " << endl;
    cout << "\n 2.Employee " << endl;
    cout << "\n 3.ATM " << endl;
    cout << "\n 4.Exit " << endl;
    cout << "\n Enter Your Choice: ";
    cin >> a;
    switch (a)
    {
    case 1:
        manager();
        break;
    case 2:
        employee();
        break;
    case 3:
        atm();
        break;
    case 4:
        exit(0);
    default:
        cout << "\n Invalid Choice " << endl;
    }
}
int main()
{

    mainpanel();

    return 0;
}
