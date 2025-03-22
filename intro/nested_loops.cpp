#include<iostream>

int main (){
    
    // nested loops: loops inside loops

    std::string str = "this is an example sentence !";
    std::string ch1;
    std::string ch2;
    int counter = 0;

    for (int i = 0; i < str.length(); i += 2){
        for (int j = 0; j < str.length(); j++){
            ch1 = str.at(i);
            ch2 = str.at(j);
            std::cout << ch1.insert(1, ch2) << std::endl;
            counter += 1;
        }

    }

    std::cout << counter << std::endl;
    std::cout << "end of the code !" << std::endl;

    return 0;
}