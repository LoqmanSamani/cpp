#include <iostream>
#include <string>
#include <type_traits>





template <typename T, typename U>
auto max(T x, T y, U z) {
    auto max_xy = (x >= y) ? x : y;
    return (max_xy >= z) ? max_xy : z;
}


template <typename T, typename U>
auto min(U x, T y, T z) {
    auto min_yz = (y <= z) ? y : z;
    return (x <= min_yz) ? x : min_yz;
}


template <typename T>
typename std::enable_if<!std::is_same<T, std::string>::value, T>::type
mean(T x, T y, T z) {
    return (x + y + z) / 3;
}


template typename std::enable_if<!std::is_same<double, std::string>::value, double>::type 
mean<double>(double, double, double);



// specialization of max for string comparison with numeric
template <typename U>
auto max(std::string x, std::string y, U z) {
    std::string z_str = std::to_string(z);
    if (x >= y && x >= z_str) return x;
    else if (y >= x && y >= z_str) return y;
    else return z_str;
}

// specialization of min for string comparison with numeric
template <typename U>
auto min(U x, std::string y, std::string z) {
    std::string x_str = std::to_string(x);
    if (x_str <= y && x_str <= z) return x_str;
    else if (y <= x_str && y <= z) return y;
    else return z;
}



int main() {
    int x = 6, y = 4;
    double z = 3.654;
    int a = 133;
    double b = 5.6, c = 32.544;
    
    std::cout << "Max (int): " << max(x, y, z) << std::endl;
    std::cout << "Min (double): " << min(a, b, c) << std::endl;
    std::cout << "Mean (double): " << mean((double)a, b, c) << std::endl;
    
    std::string h = "432.5", g = "32";
    double j = 34.54;
    std::cout << "Max (string): " << max(h, g, j) << std::endl;
    std::cout << "Min (string): " << min(j, h, g) << std::endl;
    
    return 0;
}