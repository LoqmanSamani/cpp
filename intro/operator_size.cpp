#include<iostream>

int main (){

    // sizeof(): determinds the size in bytes of a:
    // variable, data type, class, object, etc.

    double gpa = 3.6;
    std::cout << sizeof(gpa) << " bytes" << std::endl;

    std::cout << sizeof(double) << " double \n";     // 8 bytes
    std::cout << sizeof(int) << " int \n";           // 4 bytes
    std::cout << sizeof(bool) << " bool \n";         // 1 byte
    std::cout << sizeof(std::string) << " string\n"; // 32 bytes
    std::cout << sizeof(char) << "char \n"; // 1 bytes

    std::string str1 = "first";
    std::string str2 = "first stirng of a sentence";
    std::string str3 = "this is just a try to find out if string size affects the number of bytes used to create it...";

    std::cout << sizeof(str1) << std::endl; // 32 bytes
    std::cout << sizeof(str2) << std::endl; // 32 bytes
    std::cout << sizeof(str3) << std::endl; // 32 bytes

    double doub_array[] = {32.1, 32.4, 541.5, 6.0, 6};
    std::cout << sizeof(doub_array) << std::endl; // array sizes in bytes. 40(5*8).
    std::cout << sizeof(doub_array) / sizeof(doub_array[0]) << std::endl; // length of the array. 5

    return 0;
}