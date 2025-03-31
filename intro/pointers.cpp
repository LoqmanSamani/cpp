#include<iostream>




int main(){
    /*
    pointer: a pointer is a variable which stores the memory address of another variable.
    sometimes it is easier to work with a memory address instead of the original variable.

    &: address-of operator
    *: dereference operator
    */

    std::string name = "Loqman";
    std::string *pname = &name;

    std::cout << "Variable: " << name << std::endl; // Variable: Loqman
    std::cout << "Pointer of the Variable: " << pname << std::endl; // Pointer of the Variable: 0x7ffc645f0f70

    int age = 34;
    int *page = &age;

    std::cout << age << std::endl;
    std::cout << page << std::endl;

    std::string names[] = {"loqman", "saman", "ali", "ahmad"};
    std::string *pnames = names; // no need to use address-0f operator, because the array is already a pointer.

    std::cout << names << std::endl;
    std::cout << pnames << std::endl;

    return 0;
}