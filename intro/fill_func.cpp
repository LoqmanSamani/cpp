#include<iostream>


int main(){
    // fill(): fill a range of elements with a specified value
    //     fill(begin, end, value)

    int size;
    std::string food1;
    std::cout << "Size of the array: ";
    std::cin >> size;
    std::cout << "Fill Value: ";
    std::cin >> food1;

    std::string food2 = "Hamburger";
    std::string food3 = "Hotdog";


    std::string foods[size];

    fill(foods, foods + size, food1);
    fill(foods + 3 , foods + (size/2), food2);
    fill(foods + (size/2), foods + size - 3, food3);
    //----------------------------------------------
    fill(foods + (size/3), foods + size - (size/3), food1);
    fill(foods, foods + (size/3), food2);
    fill(foods + size - (size/3), foods + size, food3);

    
    for (std::string f: foods){
        std::cout << f << std::endl;    
    }

    return 0;
}