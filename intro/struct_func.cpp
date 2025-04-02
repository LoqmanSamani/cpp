#include<iostream>



struct cars{
    std::string name;
    double max_speed;
    int rank;
};


void print_info(cars car);
void change_rank(cars &car, int new_rank);

int main(){

    cars car1;
    cars car2;
    cars car3;

    car1.name = "benz";
    car1.max_speed = 342.543;
    car1.rank = 2;

    car2.name = "audi";
    car2.max_speed = 300.5;
    car2.rank = 3;

    car3.name = "bmw";
    car3.max_speed = 350;
    car3.rank = 1;

    std::cout << &car1 << std::endl;

    print_info(car1);
    change_rank(car1, 1);
    print_info(car1);

    std::cout << &car2 << std::endl;

    print_info(car2);
    change_rank(car2, 3);
    print_info(car2);

    std::cout << &car3 << std::endl;
    
    print_info(car3);
    change_rank(car3, 2);
    print_info(car3);


    return 0;
}

void print_info(cars car){
    std::cout << &car << std::endl;
    std::cout << "--------CAR INFORMATION-------" << std::endl;
    std::cout << "      Car Name: " << car.name << std::endl;
    std::cout << "      Car Max Speed: " << car.max_speed << std::endl;
    std::cout << "      Car Rank: " << car.rank << std::endl;
}

void change_rank(cars &car, int new_rank){
    car.rank = new_rank;   
}