#include <iostream>

int main(){

    /*
    how to use arithmatic operators (+ * - /) in C++
    */
    int students = 30;
    students += 2; // or students = students + 2
    students++; // increments by one.

    students -= 5;
    students--;
    students /= 2;
    students *= 44;

    int remainder = students % 3;
    students = students / 3 + 5 - 7 * 13;


    std::cout << students << std::endl;
    std::cout << remainder << std::endl;

    return 0;
}