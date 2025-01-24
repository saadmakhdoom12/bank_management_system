# Bank Management System

A C++ console application for managing bank operations with different user roles including Manager, Employee, and ATM user interface.

## Features

### Manager Operations

- Create new bank accounts
- View balance inquiries
- Display all account details
- Close existing accounts
- Secure login (Username: manager, Password: 12345)

### Employee Operations

- Handle deposits
- Process withdrawals
- Check account balances
- View all accounts
- Process bill payments (Electricity, Gas, Water)

### ATM Operations

- Check account balance
- Withdraw money
- Deposit money
- Secure account-based access

## Technical Details

- Language: C++
- Data Storage: File-based persistence (accounts.txt)
- Maximum Accounts: 100

## How to Run

1. Compile the code using a C++ compiler:

```cpp
g++ bank_management_system.cpp -o bank_system
```
