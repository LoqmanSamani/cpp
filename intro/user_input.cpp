#include <iostream>

int main(){
    // insertion operator: cout <<
    // extraction operator: cin >>

    std::string name;
    int age;
    std::string movie;

    std::cout << "What's your full name? ";
    std::getline(std::cin, name); // getline function is used to return both first and last name (connect parts of the string together !)

    std::cout << "How old are you? ";
    std::cin >> age;

    std::cin.ignore(); // <-- Ignore leftover newline character

    std::cout << "What's your favorite movie of all time? ";
    std::getline(std::cin, movie);
    

    std::cout << "Hello " << name << "!" << std::endl;
    std::cout << "I am also " << age << " years old!" << std::endl;
    std::cout << "I could not understand " << movie << " at all !" << std::endl;
    

    return 0;
}