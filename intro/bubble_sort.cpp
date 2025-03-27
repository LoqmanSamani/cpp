#include<iostream>


int main(){
    // bubble sort algorithm

    int arr[] = {1, 4, 7, 9, 2, 55, 65, 21, 43, 87, 89, 10, 6, 6, 3, 4, 0};
    int size = sizeof(arr)/ sizeof(arr[0]);

    int temp_store;

    for (int i = 0; i < size; i++){

        for(int j = 0; j < size - 1 - i; j++){ 

            if (arr[j] > arr[j+1]){

                temp_store = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp_store;
            }
                       
        }
    }
    
    for (int obj: arr){
        std::cout << obj << " ";
    }
    std::cout << std::endl;

    return 0;
}