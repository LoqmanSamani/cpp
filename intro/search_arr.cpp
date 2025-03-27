#include<iostream>


void iter_arr(double arr[], int size);


int main (){

    double obj = 2.1;
    
    double arr1[] = {2.1, 3.4, 6.5};
    double arr2[] = {2.1, 3.4, 6.5, 2.1, 5.6, 2.1, 6.5};
    double arr3[] = {2.3, 3.4, 6.5, 6.5};

    int size1 = sizeof(arr1)/sizeof(double);
    int size2 = sizeof(arr2)/sizeof(double);
    int size3 = sizeof(arr3)/sizeof(double);

    double idxs1[size1];
    int num_found1 = 0;

    double idxs2[size2]; 
    int num_found2 = 0;

    double idxs3[size3]; 
    int num_found3 = 0;


    int count1 = 0;
    for (int i = 0; i < size1; i++){

        if (arr1[i] == obj){
            idxs1[count1] = i;
            count1++;
            num_found1++;
        }
    }

    int count2 = 0;
    for (int i = 0; i < size2; i++){

        if (arr2[i] == obj){
            idxs2[count2] = i;
            count2++;
            num_found2++;
        }
    }

    int count3 = 0;
    for (int i = 0; i < size3; i++){

        if (arr3[i] == obj){
            idxs3[count3] = i;
            count3++;
            num_found3++;
        }
    }

    std::cout << "Array 1: # found objects: " << num_found1 << " Indices: "; 
    iter_arr(idxs1, num_found1);
    std::cout << "\n";

    std::cout << "Array 2: # found objects: " << num_found2 << " Indices: "; 
    iter_arr(idxs2, num_found2);
    std::cout << "\n";
    
    std::cout << "Array 3: # found objects: " << num_found3 << " Indices: "; 
    iter_arr(idxs3, num_found3);
    std::cout << "\n";
    
    
    return 0;
}


void iter_arr(double arr[], int size){

    for(int i = 0; i < size; i++){

        std::cout<<arr[i]<<" ";
    }   
}