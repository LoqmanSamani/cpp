#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    int guessed_num;
    int low_bound;
    int up_bound;
    int rand_num;

    std::cout << "********* Guessing Numbers *********" << std::endl;
    std::cout << "Enter lower bound: ";
    std::cin >> low_bound;
    std::cout << "Enter upper bound: ";
    std::cin >> up_bound;

    if (low_bound >= up_bound) {
        std::cout << "Error: Lower bound must be smaller than the upper bound!" << std::endl;
    } else {
        std::srand(time(0)); // Seed the random number generator

        rand_num = low_bound + std::rand() % (up_bound - low_bound + 1); 
        
        std::cout << "Enter a number between [" << low_bound << ", " << up_bound << "]: ";
        std::cin >> guessed_num;

        if (guessed_num < low_bound || guessed_num >= up_bound) {
            std::cout << "Invalid input! Your number is out of range." << std::endl;
        } else if (guessed_num == rand_num) {
            std::cout << "Congrats! You won!!!" << std::endl;
        } else {
            std::cout << "Sorry, you lost!" 
                      << " Your entered number: " << guessed_num 
                      << ". The random number was: " << rand_num << "." << std::endl;
        }
    }

    std::cout << "************************************" << std::endl;

    return 0;
}