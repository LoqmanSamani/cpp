#include<iostream>


// declare the fucntion to write it after the main.
void HappyBirthday(std::string name, int age);


int main (){

    std::string name;
    int age;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "How old are you!: ";
    std::cin >> age;

    HappyBirthday(name, age);
    HappyBirthday(name, age);
    HappyBirthday(name, age);
    
    return 0;
}

// a function which we will use inside the main function.
void HappyBirthday(std::string name, int age){

    std::cout << "Happy birhtday "<<name<<" !. you are know "<<age<<" :)\n";
    std::cout << "Happy birhtday "<<name<<" !. you are know "<<age<<" :)\n";
    std::cout << "Happy birhtday "<<name<<" !. you are know "<<age<<" :) \n \n";
}