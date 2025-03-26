#include<iostream>

int main (){

    std::string students[] = {"st1", "st2", "st3", "st4"};

    // foreach loop
    for (std::string st: students){
        std::cout << st << std::endl;
    }

    return 0;
}