#include<iostream>

int num1 = 6; // global variable

void print_global_var();
void print_local_var(int num);
void scope_var();


int main (){
    // local variable: declared inside a function.
    // global variable: declared outside functions.

    int num2 = 5; // local variable

    print_global_var();
    print_local_var(num2);

    // scope resolution operator: if a variable (same name) defined as both glocal and local.
    // operating function uses the local one by default.
    // using scope resolution operator (::), the function will use the global one.
    scope_var();

    return 0;
}


void print_global_var(){
    std::cout << num1 << std::endl;
}

void print_local_var(int num){
    std::cout << num << std::endl;
}

void scope_var(){
    int num1 = 12;
    std::cout << ::num1 << std::endl; // returns the global variable (6)
}