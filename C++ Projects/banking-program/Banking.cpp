#include <iostream>
#include <iomanip>

void showBalance(double Balance);
double deposit();
double withdraw(double Balance);

int main(){
    
    double balance = 123;
    int choice = 0;

    do{
    

        std::cout << "******************\n";
        std::cout << "Enter your choice:\n";
        std::cout << "******************\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";

        std::cin >> choice;

        switch(choice){
            case 1: showBalance(balance);
                    break;
            case 2: balance += deposit();
                    showBalance(balance);
                    break;
            case 3: balance -= withdraw(balance);
                    showBalance(balance);
                    break;
            case 4: std::cout << "Thanks for Visiting!\n";
                    break;
            default: std::cout << "Invalid choice\n";

        }

    }while(choice != 4);
    

    return 0;
}

// Function to display balance
void showBalance(double balance){
    std::cout << "Your balance is $" <<  std::setprecision(2) << std::fixed << balance << "\n";
}

// Function to deposit money
double deposit(){
    
    double amount = 0;
    std::cout << "Enter amount to be deposited: ";
    std::cin >> amount;

    if(amount > 0){ // make sure the amount is a positive number
        return amount;
    }
    else{ // if it is not a positive number, than it is not valid and return 0.
        std::cout << "That is not a valid amount\n";
        return 0;
    }
}

// Function to withdraw money.
double withdraw(double balance){

    double amount = 0;
    std::cout << "Enter amount to be withdrawn: ";
    std::cin >> amount;
    
    if (amount > balance){ // make sure amount being withdraw isn't greater than balance
        std::cout << "Insufficient Funds\n";
        return 0;
    }
    else if(amount < 0){ // make sure that there is no negative numbers entered
        std::cout << "That's not a valid amount\n";
    }
    else{ // if no other issues, then return the amount to be withdrawn
        return amount;
    }
    return 0;
}
