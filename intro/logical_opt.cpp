#include <iostream>

int main (){

    /*
    &&: checks if both conditions are true (and in python!)
    ||: checks if at least one of the condition is true (or in python!)
    !: reverses the logic of the condition, e.g., if it is true, it will be reversed to false!
    */

    // &&
    int temp;
    std::cout << "Enter the current temperature in cilicus: ";
    std::cin >> temp;
    if (temp > 0 && temp < 30){
        std::cout << "The current temperature is good!" << "\n";
    } else{
        std::cout << "The current temperature is bad!" << "\n";
    }
    
    // ||
    int rotation;
    std::cout << "Enter the rotation in degree: ";
    std::cin >> rotation;

    if (rotation >= 70 || rotation <= 0){
        std::cout << "it is the right rotation!" << "\n";
    } else{
        std::cout << "it is not a proper rotation!" << "\n";
    }

    // !
    int sunny = true;
    if (!sunny){
        std::cout << "It is cloudy outside!" << "\n";
    }else{
        std::cout << "It is sunny outside!" << "\n";
    }

    return 0;
}