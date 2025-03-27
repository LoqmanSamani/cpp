#include<iostream>


double get_sum(double arr[], int size);

int main (){

    double arr1[] = {1.2, 4., 4.3, 6.7, 8.9}; 
    double sum = get_sum(arr1, sizeof(arr1)/ sizeof(double));
    std::cout << sum << std::endl;

    double sum1 = 0.0;
    double arr2[] = {2., 4., 6., 1.};
    for (double obj: arr2){
        sum1 += obj;
    }
    std::cout << sum1 << std::endl;

    return 0;
}

double get_sum(double arr[], int size){
    double sum = 0.0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}