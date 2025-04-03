#include<iostream>


class Stove{

    public: // can be accessed from outside the class.
        int temperature = 0;

};

class Stove1{

    private: // can't be accessed from outside the class.
        int temperature = 200;

    public:
        int get_temperature(){ // getter function. used to read the private atrribute
            return temperature;
        }
        void set_temperature(int temp){ // setter function: uded to change a private atribute.

            this -> temperature = temp;
        }

};


int main(){
    // Abstraction: hidding unnecessary data from outside a class.
    // getter: function that makes a private attribute readable.
    // setter: function that makes a private attribure writeable.

    Stove stove;
    Stove1 stove1;

    stove.temperature = 1000000; // changes the temperature attribute.

    // stove1.temperature = 1000; // will run into an error

    std::cout << "The temperature setting is: " << stove.temperature << std::endl;
    std::cout << stove1.get_temperature() << std::endl; // access the private attribute.

    // access the private attribute after changing with setter function.
    stove1.set_temperature(6785);
    std::cout << stove1.get_temperature() << std::endl; 


    return 0;
}