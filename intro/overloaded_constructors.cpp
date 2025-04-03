#include<iostream>




class Pizza{

    public:

        std::string topping1;
        std::string topping2;
        std::string topping3;
        //double price1;
        //double price2;
        //double price3;

    Pizza(){

    }

    Pizza(std::string topping1){
        this -> topping1 = topping1;
    }

    Pizza(std::string topping1, std::string topping2){
        this -> topping1 = topping1;
        this -> topping2 = topping2;
    }

    Pizza(std::string topping1, std::string topping2, std::string topping3){

        this -> topping1 = topping1;
        this -> topping2 = topping2;
        this -> topping3 = topping3;
    }

    void available_toppings(){

        std::string toppings[] = {
            "pepperoni", "sausage", "mushrooms",
            "onions", "black olives", "cheese"
            };

        double prices[] = {
            12.50, 10.20, 9.50, 8.00, 11.10, 8.90 
        };

        std::cout << "---Available Toppings ---" << std::endl;
        int counter = 1;
        for (std::string topp : toppings){
            std::cout << counter << "." << topp << "   ...   $" << prices[counter-1] << std::endl;
            counter ++;
        }
    }
    void compute_price(std::string topping1, std::string topping2 = " ", std::string topping3 = " "){

        std::string toppings[] = {
            "pepperoni", "sausage", "mushrooms",
            "onions", "black olives", "cheese"
            };
            
        double prices[] = {
            12.50, 10.20, 9.50, 8.00, 11.10, 8.90 
        };

        
        bool availables[] = { false, false, false};
        int indices[] = {-1, -1, -1};
        
        
        if (topping1 != " "){

            for (int i = 0; i < sizeof(toppings)/sizeof(std::string); i++){
                
                    if (topping1 == toppings[i]){
                        availables[0] = true;
                        indices[0] = i;
                    }
                }   
        }else{
            indices[0] = 100;
        }

        if (topping2 != " "){

            for (int i = 0; i < sizeof(toppings)/sizeof(std::string); i++){
                
                    if (topping2 == toppings[i]){
                        availables[1] = true;
                        indices[1] = i;
                    }
                }   
        }else{
            indices[1] = 100;
        }

        if (topping3 != " "){

            for (int i = 0; i < sizeof(toppings)/sizeof(std::string); i++){
                
                    if (topping3 == toppings[i]){
                        availables[2] = true;
                        indices[2] = i;
                    }
                }   
        }else{
            indices[2] = 100;
        }
        

        double p = 0;
        int count = 0;
        
        for (int i = 0; i < 3; i++){

            if (indices[i] > -1 && indices[i] < 100){
                p += prices[indices[i]]; 
                count++;   
            }
            else if (indices[i] == 100){
                count++;
            }
             
        }
    
        if (count == 3){
            std::cout << "Your pizza costs: $" << p << std::endl;
        }else{
            std::cout << "Sorry! Some of your pizza's materials are not available!" << std::endl;
        }
    }

};




int main() {

    // overloaded constructors: multiple constructors
    // with same name but different parameters.


    
    Pizza p1;
    p1.available_toppings();
    
    Pizza pizza1("pepperoni");
    Pizza pizza2("sausage", "mushrooms");
    Pizza pizza3("onions", "black olives", "cheese");
    
    std::cout << "\nCalculating Prices:\n";
    pizza1.compute_price("pepperoni");
    pizza2.compute_price("sausage", "mushrooms");
    pizza3.compute_price("onions", "black olives", "cheese");
    p1.compute_price("error");

    return 0;
}