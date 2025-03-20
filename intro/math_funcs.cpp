#include <iostream> // C++ standard library header used for input and output (I/O) operations
#include <cmath> // a C++ header file


int main(){

    double x = 8;
    double y = 12;
    double x_ = - x;
    double a;
    double z;
    double h;
    double i;
    double j;
    double k;
    double l;
    double b;

    z = std::max(x, y);
    h = std::min(x, y);
    i = std::pow(x, y);
    j = std::sqrt(y);
    k = std::abs(x_);
    l = std::round(x = 8.5543);
    b = std::ceil(x = 8.432); // round up
    a = std::floor(x = 8.999999922); // round down


    std::cout << z << std::endl;
    std::cout << h << std::endl;
    std::cout << i << std::endl;
    std::cout << j << std::endl;
    std::cout << k << std::endl;
    std::cout << l << std::endl;
    std::cout << b << std::endl;
    std::cout << a << std::endl;

    return 0;
}