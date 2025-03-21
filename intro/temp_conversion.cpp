#include <iostream>

int main() {

    char temp_unit; 
    double temp; 

    std::cout << "Enter the temperature unit (C for Celsius, F for Fahrenheit, K for Kelvin): ";
    std::cin >> temp_unit;
    std::cout << "Now enter the temperature: ";
    std::cin >> temp;

    switch (temp_unit) {
        case 'C':
        case 'c':
            std::cout << "Temp in Celsius: " << temp << " C" << std::endl;
            std::cout << "Temp in Fahrenheit: " << (temp * 9.0 / 5) + 32 << " F" <<  std::endl;
            std::cout << "Temp in Kelvin: " << temp + 273.15 << " K" << std::endl;
            break;

        case 'F':
        case 'f':
            std::cout << "Temp in Celsius: " << (temp - 32) * 5.0 / 9 << " C" <<  std::endl;
            std::cout << "Temp in Fahrenheit: " << temp << " F" << std::endl;
            std::cout << "Temp in Kelvin: " << (temp - 32) * (5.0 / 9) + 273.15 << " K" << std::endl;
            break;

        case 'K':
        case 'k':
            std::cout << "Temp in Celsius: " << temp - 273.15 << " C" << std::endl; 
            std::cout << "Temp in Fahrenheit: " << ((temp - 273.15) * 9.0 / 5) + 32 << " F" << std::endl;
            std::cout << "Temp in Kelvin: " << temp << " K" << std::endl;
            break;

        default:
            std::cout << "Please enter a valid unit (C, F, K)!!!" << std::endl;
    }

    return 0;
}