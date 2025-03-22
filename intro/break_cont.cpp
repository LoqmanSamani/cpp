#include<iostream>

int main(){

    // break: break out of a loop
    // continue: skip the corrent iteration

    for (int i = 1; i <= 20; i++){
        if (i == 13){
            break;
        }
        std::cout << i << " ";
        
    } // 1 2 3 4 5 6 7 8 9 10 11 12
    
    std::cout << std::endl;

    for (int i = 1; i <= 20; i++){
        if (i == 13){
            continue;
        }
        std::cout << i << " ";
    } // 1 2 3 4 5 6 7 8 9 10 11 12 14 15 16 17 18 19 20 

    std::cout << std::endl;

    return 0;
}