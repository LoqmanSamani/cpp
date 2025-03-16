#include <iostream>

namespace first{
    int x = 3;
}
namespace second{
    int x = 6;
}
namespace third{
    std::string x = "this is a string example of namespace x.";
}
namespace forth{
    bool x = true;
}

int main(){
    /*
    namespace = provides a solution for preventing name conflicts in large projects.
    each entity needs a unique name.
    namespace allows for identical names of entities as long as their namespaces are different.
    */ 
    int x = 0; 
    
    std::cout << "start" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << x << std::endl; // returns the local x.
    std::cout << "-------------------" << std::endl;
    std::cout << first::x << std::endl; // returns the first namespace x.
    std::cout << "-------------------" << std::endl;
    std::cout << second::x << std::endl; // returns the second namespace x.
    std::cout << "-------------------" << std::endl;
    std::cout << third::x << std::endl; // returns the last (third) namespace x.
    std::cout << "-------------------" << std::endl;
    std::cout << "finish" << std::endl;

    // we can also use this line to define which x should be returned. "using namespace first;"
    using namespace forth;
    std::cout << x << std::endl;

    return 0;
}