#include "add_std.hpp"
#include <iostream>

using namespace std;


int main (){

    map<string, int> grades = {
        {"math", 89},
        {"phisics", 95},
        {"biology", 78}
    };

    Student st1("Loqman1", "Samani", "st123456", 'm', 21, "loqman@gmail.com", "123 Main St", 123456789, grades);
    Student st2("Loqman2", "Samani", "st1243456", 'm', 21, "loqman@gmail.com", "123 Main St", 123456789, grades);
    Student st3("Loqman3", "Samani", "st123456", 'm', 21, "loqman@gmail.com", "123 Main St", 123456789, grades);

    //cout << st1.first_name << std::endl;
    st1.add_student();
    st2.add_student();
    st3.add_student();

    //st1.system_info();

    return 0;
}