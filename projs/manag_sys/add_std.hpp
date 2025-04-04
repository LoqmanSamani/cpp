#include<iostream>
#include <map>
#include <fstream>
#include <string>



class Student{

    public:
        std::string first_name;
        std::string last_name;
        std::string id;
        char gender; // m: male, f:female, d: diverse
        std::string email;
        int phone_num;
        std::string address;
        std::map<std::string, int> courses_grades;
        int age;
        

        Student(
            std::string first_name, std::string last_name, std::string id, char gender, int age, std::string email = " ",
            std::string address = " ", int phone_num = 0, std::map<std::string, int> courses_grades = {}
        ){
            this -> first_name = first_name;
            this -> last_name = last_name;
            this -> id = id;
            this -> gender = gender;
            this -> age = age;
            this -> email = email;
            this -> address = address;
            this -> phone_num = phone_num;
            this -> courses_grades = courses_grades;
        }

        void system_info(){
            std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "-                                      Student Management Information                                      -" << std::endl;
            std::cout << "-                         To add a new student the following information is needed                         -" << std::endl;
            std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "- 1. first_name (string): first name of the student                                                        -"<< std::endl;
            std::cout << "- 2. last_name (string): last name of the student                                                          -" << std::endl;
            std::cout << "- 3. id (string): student id. e.g., st186432                                                               -" << std::endl;
            std::cout << "- 4. gender (char): student gender (m: male, f: female and d: diverse)                                     -" << std::endl;
            std::cout << "- 5. age (int): student age in year                                                                        -" << std::endl;
            std::cout << "- 6. email (string, opt): email address of the studnet                                                     -" << std::endl;
            std::cout << "- 7. address (string, opt): address. e.g., 205 E Webster St.                                               -" << std::endl;
            std::cout << "- 8. phone_num (int, opt): phone number of the student                                                     -" << std::endl;
            std::cout << "- 8. courses_grades (dict, opt): a map which allignes each course(key, string) to its grade(value, int)    -" << std::endl;
            std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
    
        }

        // checks if student id already exists in ids.csv
        bool check() {

            std::ifstream file("ids.csv");
            std::string line;
            if (file.is_open()) {
                while (std::getline(file, line)) {
                    if (line == id) {
                        return true; 
                    }
                }
                file.close();
            }
            return false; 
        }

        void add_student() {

            if (check()) {
                std::cout << "Student with ID (" << id << ") already exists! Not adding again.\n";
                return;
            }
        
            
            std::ofstream id_out("ids.csv", std::ios::app);
            if (id_out.is_open()) {
                id_out << id << "\n";
                id_out.close();
            } else {
                std::cerr << "Error: Could not open 'ids.csv' to store student ID.\n";
                return;
            }
        
            
            std::string data = first_name + "," + last_name + "," + id + "," + gender + "," +
                               std::to_string(age) + "," + email + "," + address + "," +
                               std::to_string(phone_num) + ",";
        
            for (const auto& [course, grade] : courses_grades) {
                data += course + ":" + std::to_string(grade) + ";";
            }
        
            store_info(data);
        }
        

        void store_info(const std::string& student_data){

            std::ofstream file("students.csv", std::ios::app); // create if does not exist.
            if(file.is_open()){
                file << student_data << std::endl;
                file.close();
                std::cout << "student (" << id << ") info is added successfully to the data bank!" << std::endl;
            }else{
                std::cerr << "Error: could not open or create the data bank!!!" << std::endl;
            }
        }       

};