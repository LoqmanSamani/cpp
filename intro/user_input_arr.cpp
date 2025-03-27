#include<iostream>

int main(){

    // assingning user input values to an array
    
    std::string names[5];
    std::string name;

    int size = sizeof(names)/sizeof(std::string);

    for (int i = 1; i <= size; i++){
        std::cout << "Enter the name or 'q' to quit # " << i << ": ";
        std::getline(std::cin, name);

        if (name == "q"){
            break;
        }else{
            names[i-1] = name;
        }
    }
    for (int i = 0; !names[i].empty(); i++){
        std::cout << names[i] << std::endl;
    }


    return 0;
}