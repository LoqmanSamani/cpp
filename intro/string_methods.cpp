#include <iostream>


int main(){
    /*
    some usefull string methods
    */
   
    std::string user_name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, user_name);

    // user_name.clear(); it deletes the uder name.
    // user_name.find("l"); finds the index of a charater. indexing in c++ is like python (starts form 0)
    // user_name.at(3); it returns the character placed in the given index.
    // user_name.erase(0, 4); it erases the characters between two given indices.
    user_name.append("@gmail.com");
    user_name.insert(0, "@");
    

    if (user_name.empty()){
        std::cout << "Please enter a user name. it can not be empty! \n";
    }
    else if  (user_name.length() > 30){
        std::cout << "Input user-name can not be longer than 12 characters! \n";
    }
    else{
        std::cout << "Welcome " << user_name << std::endl;
    }
    

    return 0;
}