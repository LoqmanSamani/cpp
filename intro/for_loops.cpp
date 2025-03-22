#include<iostream>

int main(){


    // int i = 1: it specifies the start of for loop.
    // i <= 10: specifies the condition.
    // i++: it is the increment by one.
    for (int i = 1; i <= 10; i++){
        std::cout << "Happy new year " << "(" << i << ")" << std::endl;
    }

    for (int i=-12; i<=10; i+=2){
        std::cout << i << std::endl;
    }
    std::cout << "it is done !" << std::endl;

    return 0;
}