#include<iostream>


struct student{
    std::string name;
    int age;
    double gpa;
    bool enrolled;
};


int main(){
    // struct: a structure that groups related variables under one name.
    //         structs can contain many different data types-unlike arrays
    //         (string, int, bool, char, double etc.)
    //         variables in a struct are known as "members"
    //         members can be accessed with "."(Class Member Access Operator).

    student st1;
    student st2;
    student st3;

    st1.name = "Loqman";
    st1.age = 32;
    st1.gpa = 4.3;
    st1.enrolled = true;

    st2.name = "Ali";
    st2.age = 22;
    st2.gpa = 3.3;
    st2.enrolled = false;

    st3.name = "Saman";
    st3.age = 35;
    st3.gpa = 4.6;
    st3.enrolled = true;

    std::cout << "----Student 1 infos----" << std::endl;
    std::cout << "Name: " << st1.name << std::endl;
    std::cout << "Age: " << st1.age << std::endl;
    std::cout << "GPA: " << st1.gpa << std::endl;
    std::cout << "Is Enrolled: " << st1.enrolled << std::endl;

    std::cout << "----Student 2 infos----" << std::endl;
    std::cout << "Name: " << st2.name << std::endl;
    std::cout << "Age: " << st2.age << std::endl;
    std::cout << "GPA: " << st2.gpa << std::endl;
    std::cout << "Is Enrolled: " << st2.enrolled << std::endl;

    std::cout << "----Student 3 infos----" << std::endl;
    std::cout << "Name: " << st3.name << std::endl;
    std::cout << "Age: " << st3.age << std::endl;
    std::cout << "GPA: " << st3.gpa << std::endl;
    std::cout << "Is Enrolled: " << st3.enrolled << std::endl;
 

    return 0;
}