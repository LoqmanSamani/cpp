#include<iostream>

int main(){
    // Memory adress: location in memory where data is stored.
    // it can be accessed whit & (address of) operator.

    std::string name = "Loqman";
    int int_num = 123;
    double float_num = 123.433;
    char letter = 'A';
    bool isit = true;

    // memory addresses. inputs are showed in hexadecimal
    std::cout << &name << std::endl;
    std::cout << &int_num << std::endl;
    std::cout << &float_num << std::endl;
    std::cout << static_cast<void*>(&letter) << std::endl;
    std::cout << &isit << std::endl;

    return 0;
}