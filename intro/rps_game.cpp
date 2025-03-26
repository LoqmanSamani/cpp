#include<iostream>
#include<ctime>




int main (){

    // roch, paper, scissors game.
    // number one is roch, two is paper ans three is scissors.

    srand(time(0));
    int num_rounds = 0;
    int rand1; 
    int rand2;
    int rand3;
    bool win = false;

    do{
        
        rand1 = rand() % 3 + 1;
        rand2 = rand() % 3 + 1;
        std::cout << "Enter an integer number form the list [1(rock), 2(paper), 3(scissors)]: ";
        std::cin >> rand3;

        // check if input is invalid
        if (std::cin.fail() || rand3 < 1 || rand3 > 3) {
            std::cin.clear();  // clear the error flag
            std::cin.ignore(1000, '\n');  // discard invalid input
            std::cout << "Invalid input! Please enter 1, 2, or 3.\n";
            continue; 
        }

        switch(rand3){

            case 1:
                if (rand1 == 2 || rand2 == 2){
                    std::cout << "Sorry! you lost.\n";
                    std::cout << "1. your choice: "<<rand3<<" \n";
                    std::cout << "2. your opponet choice: "<<rand1<<"\n";
                    std::cout << "3. your opponet choice: "<<rand2<<"\n";
                    num_rounds++;
                }
                else if (rand1 == 3 && rand2 == 3){
                    std::cout << "Congrats! you won.\n";
                    std::cout << "1. your choice: "<<rand3<<" \n";
                    std::cout << "2. your opponet choice: "<<rand1<<"\n";
                    std::cout << "3. your opponet choice: "<<rand2<<"\n";
                    win = true;
                    num_rounds++;
                }
                else if (rand1 == 1 || rand2 == 1){

                    std::cout << "It is a tie!\n";
                    std::cout << "1. your choice: "<<rand3<<" \n";
                    std::cout << "2. your opponet choice: "<<rand1<<"\n";
                    std::cout << "3. your opponet choice: "<<rand2<<"\n";
                    num_rounds++;
                }
                break;

            case 2:
                if (rand1 == 3 || rand2 == 3){
                    std::cout << "Sorry! you lost.\n";
                    std::cout << "1. your choice: "<<rand3<<" \n";
                    std::cout << "2. your opponet choice: "<<rand1<<"\n";
                    std::cout << "3. your opponet choice: "<<rand2<<"\n";
                    num_rounds++;
                }
                else if (rand1 == 1 && rand2 == 1){
                    std::cout << "Congrats! you won.\n";
                    std::cout << "1. your choice: "<<rand3<<" \n";
                    std::cout << "2. your opponet choice: "<<rand1<<"\n";
                    std::cout << "3. your opponet choice: "<<rand2<<"\n";
                    win = true;
                    num_rounds++;
                }
                else if (rand1 == 2 || rand2 == 2){

                    std::cout << "It is a tie!\n";
                    std::cout << "1. your choice: "<<rand3<<" \n";
                    std::cout << "2. your opponet choice: "<<rand1<<"\n";
                    std::cout << "3. your opponet choice: "<<rand2<<"\n";
                    num_rounds++;
                }
                break;
                
            case 3:
                if (rand1 == 1 || rand2 == 1){
                    std::cout << "Sorry! you lost.\n";
                    std::cout << "1. your choice: "<<rand3<<" \n";
                    std::cout << "2. your opponet choice: "<<rand1<<"\n";
                    std::cout << "3. your opponet choice: "<<rand2<<"\n";
                    num_rounds++;
                }
                else if (rand1 == 2 && rand2 == 2){
                    std::cout << "Congrats! you won.\n";
                    std::cout << "1. your choice: "<<rand3<<" \n";
                    std::cout << "2. your opponet choice: "<<rand1<<"\n";
                    std::cout << "3. your opponet choice: "<<rand2<<"\n";
                    win = true;
                    num_rounds++;
                }
                else if (rand1 == 3 || rand2 == 3){

                    std::cout << "It is a tie!\n";
                    std::cout << "1. your choice: "<<rand3<<" \n";
                    std::cout << "2. your opponet choice: "<<rand1<<"\n";
                    std::cout << "3. your opponet choice: "<<rand2<<"\n";
                    num_rounds++;
                }
                break;     
        }

    } while(!win);
    std::cout << "You won after "<<num_rounds<<" round/s of the game." << std::endl;
    return 0;
}