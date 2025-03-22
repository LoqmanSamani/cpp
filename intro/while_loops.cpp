#include <iostream>
#include <string>


int main() {

    // while loops

    std::string name;
    std::string c;
    double num;

    // do while loop
    do {
        std::cout << "Enter a positive number: ";
        std::cin >> num;
    } while (num < 0);
    std::cout << "The number is: " << num << std::endl;

    
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // while loop
    if (name.empty()) {
        std::cout << "Please enter your name!" << std::endl;
    } else {
        while (name.length() > 0) {
            c = name.at(0);
            name.erase(0, 1);
            std::cout << c << std::endl;
        }
    }
    
    return 0;
}