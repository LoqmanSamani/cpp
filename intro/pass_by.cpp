#include<iostream>


void swap1(std::string var1, std::string var2);
void swap2(std::string &var1, std::string &var2);

int main(){
    // diffetence between pass by value and pass by reference.
    std::string var1 = "fire";
    std::string var2 = "water";
    std::string var3 = "this";
    std::string var4 = "that";
    
    // this is an instance of passed by value.
    // it does not work because the swap fucntion accepts only two copy of var1 and var2.
    swap1(var1, var2);

    // this is an example of pass by reference (memory location of the variables)
    swap2(var3, var4);

    std::cout << var1 << std::endl;
    std::cout << var2 << std::endl;

    std::cout << var3 << std::endl;
    std::cout << var4 << std::endl;

    return 0;
}

void swap1(std::string var1, std::string var2){

    std::string temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}

void swap2(std::string &var1, std::string &var2){

    std::string temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}