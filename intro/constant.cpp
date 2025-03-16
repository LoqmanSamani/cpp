#include <iostream>


int main(){

    // the const keyword specifies that a variable's value is constant
    // tells the compiler to preventing any cahnge to this value,
    // which manns it is only readable (read-only)
    // example: a program to calculate the circomference of a circle.
    const double PI = 3.14159; // it is defined as an constant and can not be modified.
    double r = 3.354; // it is not constant and can be modified.
    r = 5.433; // modified radius.
    double circomference = 2 * PI * r;

    const int light_speed = 2999999999;
    // light_speed = 23455; leads to an error,because it is a constant.

    std::cout << light_speed << std::endl;
    std::cout << circomference << " cm" << std::endl;
    
    return 0;
}
