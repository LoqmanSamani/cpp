#include<iostream>

int main(){
    /*
    null value: a special value that means something has no value.
    when a pointer is holding a null value,
    the pointer is not pointing in anything (null pointer).

    nullptr: keyword represents a null pointer literal.

    nullptrs are helpfull when determining
    if an address was succussfully assigned to a pointer.
    */

    int *pointer = nullptr;
    int x = 123;

    pointer = &x;

    if (pointer == nullptr){
        std::cout << "Address was not assigned!" << std::endl;
    }else{
        std::cout << "Address is succussfully assigned: " << std::endl;
        std::cout << pointer << std::endl; // 0x7fff0f51bfec
        std::cout << *pointer << std::endl; // 123
    }

    return 0;
}