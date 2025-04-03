#include<iostream>


class Animal{
    public:
        bool alive = true;

    void eat(){
        std::cout << "This animal is eating!" << std::endl;
    }
};


class Dog: public Animal{ 

    public:
    void bark(){
        std::cout << "The dog goes woof!" << std::endl;
    }      

};

class Cat: public Animal{ 

    public:
    void meow(){
        std::cout << "The cat goes meow!" << std::endl;
    }        

};



int main(){

    // inheritance: a class can recieve methods and attibutes form another class.
    // children classes inherite from parent classes.
    // helps to reuse similar code found within multiple classes.

    Dog dog;
    Cat cat;

    std::cout << dog.alive << std::endl;
    std::cout << cat.alive << std::endl;

    dog.eat();
    dog.bark();
    cat.eat();
    cat.meow();
    
    return 0;
}