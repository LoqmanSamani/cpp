#include<iostream>

int main (){

    std::string students[] = {"st1", "st2", "st3", "st4", "st5"};
    char grades[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    
    for (int i = 0; i < (int) sizeof(students) / sizeof(students[0]); i++){
        std::cout << students[i] << std::endl;
    }

    for (int i = 0; i < (int) sizeof(grades) / sizeof(char); i++){
        std::cout << students[i] << std::endl;
    }

    return 0;
}