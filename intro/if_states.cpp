#include <iostream>

int main(){

    // if statement in C++ 
    int age;
    int my_age = 33;

    std::cout << "Enter your age: ";
    std::cin >> age;

    if (age < my_age){
        std::cout << "Congrats! you are younger than me :)" << std::endl;
    }
    else if (age > my_age){
        std::cout << "Sorry! you are older than me :(" << std::endl;
    }
    else {
        std::cout << "We are both the same age !!!" << std::endl;
    }

    return 0;
}