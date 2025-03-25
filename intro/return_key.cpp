#include <iostream>


double compute_area(double length, double width);
double compute_volume(double length, double width, double height);
std::string full_name_(std::string first_name, std::string last_name);


int main() {
    double length = 12.0;
    double width = 8.0;
    double height = 16.0;
    std::string first_name;
    std::string last_name;
    std::string full_name;

    double area = compute_area(length, width);
    double volume = compute_volume(length, width, height);

    std::cout << "Enter your first name: ";
    std::cin >> first_name;

    std::cout << "Enter your last name: ";
    std::cin >> last_name;

    full_name = full_name_(first_name, last_name);

    std::cout << "Area: " << area << " cm².\n";
    std::cout << "Volume: " << volume << " cm³.\n";
    std::cout << "Your full name: "<< full_name <<"" << std::endl; 

    return 0;
}


double compute_area(double length, double width) {
    return length * width;
}

double compute_volume(double length, double width, double height) {
    return length * width * height;
}

std::string full_name_(std::string first_name, std::string last_name){
    return first_name + " " + last_name;
}
