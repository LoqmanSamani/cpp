#include <iostream>
#include <cmath>



int main (){
    // calculates the hypotenuse of a triangle

    double a;
    double b;
    double c;
    double a_square;
    double b_square;

    std::cout << "Enter side A: ";
    std::cin >> a;

    std::cout << "Enter side B: ";
    std::cin >> b;

    a_square = std::pow(a, 2);
    b_square = std::pow(b, 2);

    c = std::sqrt(a_square + b_square);

    std::cout << "The hypotenuse (C) of the triangle is: "<< c << std::endl;

    return 0;
}