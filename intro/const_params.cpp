#include<iostream>

void print_info(const std::string name, const int age);

int main(){

    // const parameters
    std::string name = "loqman";
    int age = 30;
    print_info(name, age);

    return 0;
}

void print_info(const std::string name, const int age){

    // these two line of code run into error, 
    // because name and age are defined as constants.
    // name = "ahmaw";
    // age = 41;

    std::cout << name << std::endl;
    std::cout << age << std::endl;
}
