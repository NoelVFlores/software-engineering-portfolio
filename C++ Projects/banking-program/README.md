# 🏦 Simple Banking Program (C++)

This is a command-line banking system written in C++ that allows users to check their account balance, deposit funds, and withdraw money. It features basic input validation, formatted output, and a looped menu interface for continuous interaction until the user chooses to exit.

## 🎯 Features

- Check current account balance
- Deposit money (only positive values accepted)
- Withdraw money (with insufficient funds protection)
- Menu-driven interaction with looped execution
- Properly formatted currency output using `iomanip`

## 💻 Sample Interaction

******************
Enter your choice:
******************
1. Show Balance
2. Deposit Money
3. Withdraw Money
4. Exit
1
Your balance is $123.00
******************
Enter your choice:
******************
1. Show Balance
2. Deposit Money
3. Withdraw Money
4. Exit
2
Enter amount to be deposited: 45.12
Your balance is $168.12
******************
Enter your choice:
******************
1. Show Balance
2. Deposit Money
3. Withdraw Money
4. Exit
3
Enter amount to be withdrawn: 60.56 
Your balance is $107.56
******************
Enter your choice:
******************
1. Show Balance
2. Deposit Money
3. Withdraw Money
4. Exit
4
Thanks for Visiting!

### ✅ Validations Included

- Prevents negative deposits or withdrawals
- Checks for insufficient funds before withdrawal
- Rejects invalid menu choices

## 🧠 Concepts Used

- Functions with parameters and return values
- Loops (`do-while`) and conditionals (`switch`, `if-else`)
- `iomanip` for output formatting
- Basic user input handling with `std::cin`
