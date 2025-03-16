#include <iostream>
#include <vector>

// this line of code gives the original data type
// (std::vector<std::pair<std::string, int>>) a new short name (pairlist_t)
typedef std::vector<std::pair<std::string, int>> pairlist_t; 
typedef std::string text_t;
typedef int number_t;

// instead of typedef we can also use "using" command as follows:
using true_false = bool;



int main(){
    /*
    typedef = reserved keyword to create an
    additional name (alias) for another datatype.
    new identifier for an existing type.
    helps with readability and reduces typo.
    */
    pairlist_t  pairlist;
    text_t example = "this is an example which shows how to use typedef text_t";
    number_t num_exp = 1234;
    true_false working = true;

    //std::cout << pairlist << std::endl;
    std::cout << example << std::endl;
    std::cout << num_exp << "\n";
    std::cout << working << std::endl;

    return 0;
}