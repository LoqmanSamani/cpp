#include <iostream>

int main(){
    /*
    type conversion: converting a variable from one type to another.
        implicit: automatic
        explicit: precede value with new data type
    */

    // implicit way
    int x = 3.14; // x is defined as integer, so the output is 3.
    std::cout << x << std::endl;
    
    // explicit 
    double pi = (int) 3.14; // it returns 3, because (int) changes the data type to integer.
    std::cout << pi << std::endl;

    char g = 100;
    std::cout << g << std::endl; // it will return "d" (the ascii letter correspond to 100)

    int correct = 8;
    int questions = 12;
    double grade = correct / (double) questions * 100; // without (double) it will return 0 %.S
    std::cout << grade << " %" << std::endl;
    

    return 0;
}