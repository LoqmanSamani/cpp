#include<iostream>




class Student{

    public:
        std::string first_name;
        std::string last_name;
        int age;
        double gpa;
    
    
    Student(std::string first_name, std::string last_name, int age, double gpa){ // the constructor of the class. i think it is like __init__ method in python!!!

        this -> first_name = first_name;
        this -> last_name = last_name;
        this -> age = age;
        this -> gpa = gpa;
    }

    /*
    Student(std::string x, std::string y, int z, double a){
        first_name = x;
        last_name = y;
        age = z;
        gpa = a;
    }
    */
    
        void graduate(int year){
            std::cout << first_name << " " << last_name << " will be graduated in " << year << "." << std::endl;
        }

};

int main(){

    // constructor: a special method which is automatically called
    //              when an object is instantiated.
    //              useful for assigning values to attributes as arguments.

    Student st1("Loqman", "Samani", 25, 4.7);
    st1.graduate(2025);

    std::cout << st1.first_name << " " << st1.last_name << std::endl;
    std::cout << st1.age << std::endl;
    std::cout << st1.gpa << std::endl;

    return 0;
}