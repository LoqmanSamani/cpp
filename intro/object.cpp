#include<iostream>



class Human{

    public:
        std::string name = "Person"; // defined with default value
        std::string occupation = "A society member :)"; // defined with default value
        int age = 0; // defined with default value

        void eat(){
            std::cout << name << " is eating!" << std::endl;
        }
        void drink(){
            std::cout << name <<  " can also drink!" << std::endl;
        }
        void sleep(){
            std::cout << name << " also sleeps at night!" << std::endl;
        }

};



int main(){

    //  an introduction to object-oriented programing in C++
    // object: a collection of attributes and methods.
    //         which can have characteristics and could perform actions.
    //         can be used to mimic real world items (phone, book, etc.).
    //         created form a class which acts as a 'blue-print'.

    Human h1;
    h1.name = "Loqman 1";
    h1.age = 21;
    h1.occupation = "ML engineer 1";

    std::cout << h1.name << std::endl;
    std::cout << h1.age << std::endl;
    std::cout << h1.occupation << std::endl;

    h1.eat();
    h1.drink();
    h1.sleep();

    Human h2;
    h2.name = "Loqman 2";
    h2.age = 31;
    h2.occupation = "ML engineer 2";

    std::cout << h2.name << std::endl;
    std::cout << h2.age << std::endl;
    std::cout << h2.occupation << std::endl;

    h2.eat();
    h2.drink();
    h2.sleep();

    Human h3;
    h3.name = "Loqman 3";
    h3.age = 41;
    h3.occupation = "ML engineer 3";

    std::cout << h3.name << std::endl;
    std::cout << h3.age << std::endl;
    std::cout << h3.occupation << std::endl;

    h3.eat();
    h3.drink();
    h3.sleep();

    Human h4; // using default values!
    
    std::cout << h4.name << std::endl;
    std::cout << h4.age << std::endl;
    std::cout << h4.occupation << std::endl;

    h4.eat();
    h4.drink();
    h4.sleep();

    return 0;
}