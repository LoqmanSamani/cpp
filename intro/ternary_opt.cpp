#include <iostream>

int main(){

    // Ternary operator ?:
    // replacement to if/else statement

    
    // int grade = 60;

    /*
    if (grade >= 60){
        std::cout << "You pass!" << std::endl;
    }
    else{
        std::cout << "You fail!" << std::endl;
    }
    */
    
    // (grade >= 60) ? std::cout << "You pass!" << "\n" : std::cout << "You fail!" << std::endl; /// same as if/else statement above

    int num1;
    int num2;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "enter integer 1: ";
    std::cin >> num1;
    std::cout << "enter integer 2: ";
    std::cin >> num2;

    (num1 % 2 == 0) ? std::cout << "integer one is even" << "\n" : std::cout << "integer one is odd" << std::endl;
    (num2 % 2 == 0) ? std::cout << "integer two is even" << "\n" : std::cout << "integer two is odd" << std::endl;
    (num1 + num2 % 2 == 0) ? std::cout << "sum of two integer is even" <<  "(" << num1 + num2 << ")" <<"\n" : std::cout << "sum of two integer is odd" <<  "(" << num1 + num2 << ")" << std::endl;
    (num1 - num2 % 2 == 0) ? std::cout << "sub of two integer is even" <<  "(" << num1 - num2 << ")" <<"\n" : std::cout << "sub of two integer is odd" <<  "(" << num1 - num2 << ")" << std::endl;
    (num1 * num2 % 2 == 0) ? std::cout << "mul of two integer is even" <<  "(" << num1 * num2 << ")" <<"\n" : std::cout << "mul of two integer is odd" <<  "(" << num1 * num2 << ")" << std::endl;
    (num1 / num2 % 2 == 0) ? std::cout << "div of two integer is even" <<  "(" << num1 / num2 << ")" <<"\n" : std::cout << "div of two integer is odd" <<  "(" << num1 / num2 << ")" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    
    return 0;
}