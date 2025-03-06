#include<iostream>

int main(){

    /*
    we can also combine both step declaration and assignment into one step
    e.g., int x = 5 which is the same as int x; x = 5
    */
    int x; // declaration of a variable int stands for integer.
    x = 5; // assignment step
    int y = 6;

    int sum = x + y;
    std::cout <<sum << "\n";

    std::cout << x << "\n";
    std::cout << y <<std::endl;

    // double (float)
    double z = 1.2321;
    std::cout << z << std::endl;

    // single char or character. 
    char u = 'A';
    char h = 'E'; // like my grade in scientific methodology 1 :(
    std::cout << u << "\n";
    std::cout << h;

    // boolean (true or false)
    bool student = true;
    bool hungry = false;
    std::cout << "\n" <<student << "\n" << hungry << std::endl;

    // string
    std::string sentence = "this is the first string variable which i define!";
    std::string sentence1 = "the second sentence which i define.";
    std::string sentence2 = "the last sentence which i defined.";
    std::string name = "Loqman";


    std::cout << "\n" << sentence;
    std::cout << "\n" << sentence1;
    std::cout << "\n" << sentence2;
    std::cout << "\n" << "my name is " << name << " :)";

    // the code above (output lines) can be simplified as: std::cout << x << "\n" << y; // outputs

    return 0;
}