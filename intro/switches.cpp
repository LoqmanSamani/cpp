#include <iostream>



int main(){
    // switch: an alternative to if else statement. 
    // it compairs one value against maching cases.

    
    int month;
    std::cout << "Enter the month (1 - 12): ";
    std::cin >> month;

    
    switch (month){

        case 1:
            std::cout << "It is January!" << std::endl;
            break;
        case 2:
            std::cout << "It is February!" << std::endl;
            break;
        case 3:
            std::cout << "It is Mars!" << std::endl;
            break;
        case 4:
            std::cout << "It is April!" << std::endl;
            break;
        case 5:
            std::cout << "It is May!" << std::endl;
            break;
        case 6:
            std::cout << "It is June!" << std::endl;
            break;
        case 7:
            std::cout << "It is July!" << std::endl;
            break;
        case 8:
            std::cout << "It is August!" << std::endl;
            break;
        case 9:
            std::cout << "It is September!" << std::endl;
            break;
        case 10:
            std::cout << "It is October!" << std::endl;
            break;
        case 11:
            std::cout << "It is November!" << std::endl;
            break;
        case 12:
            std::cout << "It is December!" << std::endl;
            break;
        default:
           std::cout << "Please enter a valid value (an integer number between 1 and 12)!!!" << std::endl;


    }

    char grade;
    std::cout << "Enter your math test grade: ";
    std::cin >> grade;


    switch(grade){

        case 'A':
            std::cout << "Excellent!" << "\n";
            break;

        case 'B':
            std::cout << "Good job!" << '\n';
            break;

        case 'C':
            std::cout << "Not bad!" << "\n";
            break;

        case 'D':
            std::cout << "You can do better!" << "\n";
            break;

        case 'E':
            std::cout << "Try it again!" << "\n";
            break;

        default:
           std::cout << "Please enter a valid grade (A-E)!" << "\n";

    }

    return 0;
}
