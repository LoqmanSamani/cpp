#include<iostream>

int main (){
    // Array

    std::string cars[] = {"Corvette", "Dodge", "Benz", "BMW"};
    std::cout << cars << std::endl; // returns the memory adress where the array is located. (0x7fffbb40fb20)

    // to access the values inside the array we should use index
    std::cout << cars[0] << std::endl;
    std::cout << cars[1] << std::endl;
    std::cout << cars[2] << std::endl;
    std::cout << cars[3] << std::endl;

    // reasign values inside the array
    cars[0] = "Mustang";
    std::cout << cars[0] << std::endl;

    int nums[10]; // an empty array of size 10.

    int count = 0;
    for (int i = 100; i <= 1000; i += 100){
        nums[count] = i;
        count++;
    }
    std::cout << nums[0] << " ";
    std::cout << nums[1] << " ";
    std::cout << nums[2] << " ";
    std::cout << nums[3] << " ";
    std::cout << nums[4] << " ";
    std::cout << nums[5] << " ";
    std::cout << nums[6] << " ";
    std::cout << nums[7] << " ";
    std::cout << nums[8] << " ";
    std::cout << nums[9] << std::endl;
    
    return 0;
}