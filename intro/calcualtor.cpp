#include <iostream>



// procidure one 

int main (){

    // a simple calculator which supports the four main operators (+, -, *, /).
    
    double num1;
    char opt;
    double num2;

    std::cout << "**********CALCULATOR************" << std::endl;
    
    std::cout << "Enter number one: ";
    std::cin >> num1;
    std::cout << "Enter the operator: ";
    std::cin >> opt;
    std::cout << "Enter number two: ";
    std::cin >> num2;

    if (opt == '+'){
        std::cout << "Result is: " << num1 + num2 << std::endl;
    }
    else if (opt == '-'){
        std::cout << "Result is: " << num1 - num2 << std::endl;
    }
    else if (opt == '*'){
        std::cout << "Result is: " << num1 * num2 << std::endl;
    }
    else if (opt == '/'){
        if (num2 != 0){
            std::cout << "Reslut is: " << num1 / num2 << std::endl;
        } else{
            std::cout << "Errror: zero division!!!" << std::endl;
        }   
    }
    else{
        std::cout << "please enter a supported operator (+, -, * and /) ." << std::endl;
    }

    std::cout << "********************************" << std::endl;

    return 0;
}


//------------------------------------------------------------------------------------

// procidure two

int main() {

    // a simple calculator which supports the four main operators (+, -, *, /).

    double num1, num2;
    char opt;

    std::cout << "**********CALCULATOR************" << std::endl;
    
    std::cout << "Enter number one: ";
    std::cin >> num1;
    std::cout << "Enter the operator: ";
    std::cin >> opt;
    std::cout << "Enter number two: ";
    std::cin >> num2;
    
    switch (opt) {
        case '+':
            std::cout << "Result is: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Result is: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result is: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0)
                std::cout << "Result is: " << num1 / num2 << std::endl;
            else
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            break;
        default:
            std::cout << "Please enter a supported operator (+, -, *, /)." << std::endl;
    }

    std::cout << "********************************" << std::endl;
    
    return 0;
}

