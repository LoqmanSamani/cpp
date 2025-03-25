#include <iostream>
#include <iomanip>


void show_balance(double balance);
double deposit(double balance);
double withdraw(double balance);



int main() {
    double balance = 1000;
    int choice = 0;

    do {
        std::cout << "********************\n";
        std::cout << "Enter your choice: " << std::endl;
        std::cout << "********************\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        std::cin.clear();
        fflush(stdin);

        switch (choice) {
            case 1: show_balance(balance); break;
            case 2: balance = deposit(balance); break;
            case 3: balance = withdraw(balance); break;
            case 4: std::cout << "Exiting the program. Thank you!\n"; break;
            default: std::cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n";
        }
    } while (choice != 4);

    return 0;
}


void show_balance(double balance) {
    std::cout << "Account Balance: $" << std::setprecision(2) << std::fixed << balance << std::endl;
}


double deposit(double balance) {
    double value;
    std::cout << "***************************\n";
    std::cout << "Your choice: Deposit money.\n";
    std::cout << "***************************\n";
    std::cout << "How much money do you want to deposit? ";
    std::cin >> value;

    if (value <= 0) {
        std::cout << "Invalid deposit amount. Please enter a positive number.\n";
        return balance;
    }

    balance += value;
    std::cout << "Your new balance: $" << balance << "\n";
    return balance;
}


double withdraw(double balance) {
    double value;
    std::cout << "****************************\n";
    std::cout << "Your choice: Withdraw money.\n";
    std::cout << "****************************\n";
    std::cout << "How much money do you need? ";
    std::cin >> value;

    if (value <= 0) {
        std::cout << "Invalid withdrawal amount. Please enter a positive number.\n";
        return balance;
    }

    if (value > balance) {
        std::cout << "Insufficient funds! You cannot withdraw more than your balance.\n";
        return balance;
    }

    balance -= value;
    std::cout << "Your new balance: $" << balance << "\n";
    return balance;
}