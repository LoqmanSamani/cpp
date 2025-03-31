#include<iostream>


int main(){

    // dynamic memory: memory is allocated after 
    // the program is already compiled and running.
    // use 'new' operator to alocate memory 
    // in the heap rather than the stack.
    // useful when we do not know how much memeory we need.
    // makes our program more flexible, especially when accepting user input.

    // examples
    int *pnum = NULL;
    pnum = new int;

    *pnum = 21;
    std::cout << "address: " << pnum << std::endl; // 0x64228535e2b0
    std::cout << "value: " << *pnum << std::endl; // 21

    delete pnum; // freeing up the memory

    int *pgrades = NULL;
    int size;
    std::cout << "How many grades do you want to assign ? ";
    std::cin >> size;
    pgrades = new int[size];
    for (int i = 0; i < size; i++){
        std::cout << i+1 << ". ";
        std::cin >> pgrades[i];
    }
    for (int j = 0; j < size; j++){
        if (j == 0){
            std::cout << "Grades: ";
        }
        std::cout << pgrades[j] << " ";
    }
    std::cout << std::endl;

    delete[] pgrades;

    return 0;
}