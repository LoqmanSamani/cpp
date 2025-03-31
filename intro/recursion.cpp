#include<iostream>


void walk(int steps);
void factorial(int num, int &sum);

int main(){
    /*
    recursion
    */
   int sum = 1;
    walk(20);
    factorial(10, sum);

    std::cout << sum << std::endl;

    return 0;
}

void walk(int steps){
    /*
    for (int i = 0; i < steps; i++){
        std::cout << "you walk! ( step # " << i+1 << ")" << std::endl;
    }
    */
    if(steps > 0){
        std::cout << "you walk! ( steps reamain # " << steps << ")" << std::endl;
        walk(steps - 1);
    }
    
}

void factorial(int num, int &sum){
    if(num > 1){
        sum *= num;
        factorial(num - 1, sum);
    }
}