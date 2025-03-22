#include<iostream>
#include<ctime>
#include<cstdlib>


int main ()
{
    // pseudo-random: it is not completely random.

    srand(time(NULL)); // seed the random number generator with the current time.
                      // `time(NULL)` returns the current time in seconds since Jan 1, 1970.
                      // using this as a seed ensures different random numbers in each program execution.
    int num;

    int num1 = (rand() % 6) + 1; // it returns a random number between 1 and 6!
    int num2 = (rand() % 6) + 1;
    int num3 = (rand() % 6) + 1;
    num = num1 + num2 + num3;

    if (num < 9){
        std::cout << "you got a number bellow 9. you are out!" << "your number: " << num << "[" << num1<<num2<<num3 << "]" << std::endl;
    } else{
        std::cout << "you got a number equal or above 9. you win !" << "your number: " << num << "[" << num1<<num2<<num3 << "]" << std::endl;
    }
}