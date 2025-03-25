#include<iostream>


void Pizza();
void Pizza(std::string type1);
void Pizza(std::string type1, std::string type2);
void Pizza(std::string type1, std::string type2, std::string type3);


int main (){
    std::string type1 = "pepperoni";
    std::string type2 = "mushroom";
    std::string type3 = "chicken";
    
    Pizza();
    Pizza(type1);
    Pizza(type1, type2);
    Pizza(type1, type2, type3);

    return 0;
}


void Pizza(){
    std::cout << "Your pizza is ready!" << std::endl;
}

void Pizza(std::string type1){
    std::cout << "Your " << type1 << " pizza is ready!" << std::endl;
}

void Pizza(std::string type1, std::string type2){
    std::cout << "Your " << type1 << " and " << type2 << " pizza are ready!" << std::endl;
}
void Pizza(std::string type1, std::string type2, std::string type3){
    std::cout << "Your " << type1 << ", " << type2 << " and " << type3 << " pizza are ready!" << std::endl;
}

