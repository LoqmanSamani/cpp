#include<iostream>


void qustion_(int rand_choice);

int main(){

    // Quiz Game !!!

    int answers[] = {0, 1, 0, 3, 2, 1, 1, 3, 0, 0};
    

    int rand_choice;
    int input_answer;
    bool right = false;

    do{
        std::cout << "************** Quiz Game ******************" << std::endl;

        std::cout << "Enter an integer number in range [1-10]: ";
        std::cin >> rand_choice;

        if (std::cin.fail() || rand_choice < 1 || rand_choice > 10){

            std::cout << "Wrong input!!! try again." << std::endl;
            std::cin.clear(); 
            std::cin.ignore(1000, '\n');  
            continue;  

        }else{

            qustion_(rand_choice);
            std::cin >> input_answer;

            if (std::cin.fail() || input_answer < 1 || input_answer > 4){

                std::cout << "Wrong input!!! try again." << std::endl;
                std::cin.clear();  
                std::cin.ignore(1000, '\n');  
                continue;
            }else{
                if (input_answer-1 == answers[rand_choice-1]){
                    std::cout << "Congrats! yous answer is correct :)" << std::endl;
                    right = true;
                }else{
                    std::cout << "Sorry! wrong answer :( try again! " << std::endl;
                }

            }
            
        }

        std::cout << "*******************************************" << std::endl;

    }while (!right);


    return 0;
}

void qustion_(int rand_choice){

    std::string questions[] = {
        "1. What is the keyword to define a constant variable in C++?",
        "2. Which data type is used to store a single character?",
        "3. How many bytes does an int usually take in C++?",
        "4. What is the file extension for C++ source files?",
        "5. Is Python statically typed?",
        "6. What is the output of '5 + 3 * 2' in C++?",
        "7. Which loop executes at least once regardless of the condition?",
        "8. Is Java an object-oriented programming language?",
        "9. Which function is the entry point in a C++ program?",
        "10. What operator is used for pointer dereferencing?"
    };
    std::string answers[10][4] = {
        {"const", "final", "static", "define"},
        {"string", "char", "int", "bool"},
        {"4", "2", "8", "16"},
        {".cc", ".c", ".hpp", ".cpp"},
        {"yes", "sometimes", "no", "not sure"},
        {"16", "11", "10", "8"},
        {"for", "do-while" ,"while", "if"},
        {"no", "sometimes", "maybe", "yes"},
        {"main", "start", "entry", "init"},
        {"*", "&", "->", "."}
    };

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << questions[rand_choice-1] << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Which one is the correct answer ?" << std::endl;
    std::cout << "1. " << answers[rand_choice-1][0] << std::endl;
    std::cout << "2. " << answers[rand_choice-1][1] << std::endl;
    std::cout << "3. " << answers[rand_choice-1][2] << std::endl;
    std::cout << "4. " << answers[rand_choice-1][3] << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;

}