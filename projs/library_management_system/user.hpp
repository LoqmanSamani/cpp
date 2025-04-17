#ifndef USER_HPP
#define USER_HPP



#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <stdexcept>
#include <filesystem>





class User {

    public:
        std::string id;
        std::string first_name;
        std::string last_name;
        std::string age;
        std::string gender;
        std::string email;
        std::string phone_num;
        
        User(
            std::string id = "", std::string first_name = "",
            std::string last_name = "", std::string age = "", 
            std::string gender = "", std::string email = "",
            std::string phone_num = ""
        ): 
            id(id), first_name(first_name), last_name(last_name),
            age(age), gender(gender), email(email), phone_num(phone_num) {} 
            
        void add_user(){

            if (trim(id).empty()) {
                std::cerr << "Error: ID cannot be empty!" << std::endl;
                return;
            }
            if (trim(first_name).empty()) {
                std::cerr << "Error: First Name cannot be empty!" << std::endl;
                return;
            }
            if (trim(last_name).empty()) {
                std::cerr << "Error: Last Name cannot be empty!" << std::endl;
                return;
            }
            std::string data = trim(id) + "|" + trim(first_name) + "|" + trim(last_name) + "|" + 
                               (trim(age).empty() ? "None" : trim(age)) + "|" + 
                               (trim(gender).empty() ? "None" : trim(gender)) + "|" + 
                               (trim(email).empty() ? "None" : trim(email)) + "|" +
                               (trim(phone_num).empty() ? "None" : trim(phone_num));
            
            int check = id_check(id);
            if (check == 0) {
                store_user(data);
            } else {
                std::cout << "Error: The ID (" << id << ") already exists in users.csv!" << std::endl;
            }
        }

        void del_user(std::string id){

            std::string error = "The user with account ID: " + id + " does not exist!";
            int check = id_check(id);
            if (check == 1) {
                remove_user(id);
            } else if (check == -2) {
                throw std::runtime_error("Could not open users.csv!");
            } else {
                throw std::runtime_error(error);
            }
        }
    
        void update_user(std::string id){

            std::string error = "The user with account ID: " + id + " does not exist!";
            int check = id_check(id);
            if (check == 1) {
                update_user_(id);
            } else if (check == -2) {
                throw std::runtime_error("Could not open users.csv!");
            } else {
                throw std::runtime_error(error);
            }
        }
        int id_check(const std::string& id){

            int index = find_index(id);
            if (index == -1 || index == -2) return 0; // ID is unique (file missing or no match)
            return 1; // ID exists
        }

    private:

        void update_user_(const std::string id){

            std::string error = "Could not open users.csv!";
            std::string error1 = "Could not create temp_user.csv!";
            std::ifstream file("users.csv");

            if (!file.is_open()) {
                throw std::runtime_error(error);
            }

            std::ofstream temp_file("temp_user.csv");
            if (!temp_file.is_open()) {
                file.close();
                throw std::runtime_error(error1);   
            }

            std::vector<std::string> lines;
            std::string user_line;
            std::vector<std::string> user_infos;
            int line_index = 0;
            while (std::getline(file, user_line)) {
                lines.push_back(user_line);
                std::vector<std::string> infos;
                std::stringstream ss(user_line);
                std::string info;
                while (std::getline(ss, info, '|')) {
                    infos.push_back(info);
                }
                if (infos.size() >= 7 && trim(infos[0]) == trim(id)) {
                    user_infos = infos;
                    break;
                }
                line_index++;
            }

            file.close();

            if (user_infos.empty()) {
                temp_file.close();
                std::filesystem::remove("temp_user.csv");
                throw std::runtime_error("User not found!");
            }

            int index;
            std::vector<std::string> items = {
                "Account ID", "First Name", "Last Name",
                "Age", "Gender", "Email", "Phone Number"
            };
            std::string check, new_info1, new_info2;
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << "Which user information do you want to change?" << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << " 1. Account ID: " << user_infos[0] << std::endl;
            std::cout << " 2. First Name: " << user_infos[1] << std::endl;
            std::cout << " 3. Last Name: " << user_infos[2] << std::endl;
            std::cout << " 4. Age: " << user_infos[3] << std::endl;
            std::cout << " 5. Gender: " << user_infos[4] << std::endl;
            std::cout << " 6. Email: " << user_infos[5] << std::endl;
            std::cout << " 7. Phone Number: " << user_infos[6] << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << ">>> ";
            std::cin >> index;

            if (index < 1 || index > 7) {
                temp_file.close();
                std::filesystem::remove("temp_user.csv");
                throw std::runtime_error("The input should be a number in range (1, 7)!");
            }

            std::cin.ignore(); // Clear newline
            std::cout << "Enter current " << items[index-1] << ": ";
            std::getline(std::cin, check);
            if (trim(check) != trim(user_infos[index-1])) {
                temp_file.close();
                std::filesystem::remove("temp_user.csv");
                throw std::runtime_error("False input!");
            }

            std::cout << "Enter new " << items[index-1] << ": ";
            std::getline(std::cin, new_info1);
            std::cout << "Enter new " << items[index-1] << ": ";
            std::getline(std::cin, new_info2);
            if (trim(new_info1) != trim(new_info2)) {
                temp_file.close();
                std::filesystem::remove("temp_user.csv");
                throw std::runtime_error("Wrong inputs!");
            }

            user_infos[index-1] = trim(new_info1);
            std::string data = trim(user_infos[0]) + "|" + trim(user_infos[1]) + "|" + 
                            trim(user_infos[2]) + "|" + trim(user_infos[3]) + "|" + 
                            trim(user_infos[4]) + "|" + trim(user_infos[5]) + "|" + 
                            trim(user_infos[6]);

            for (int i = 0; i < lines.size(); i++) {
                if (i == line_index) {
                    temp_file << data << "\n";
                } else {
                    temp_file << lines[i] << "\n";
                }
            }
            temp_file.close();

            try {
                std::filesystem::remove("users.csv");
                std::filesystem::rename("temp_user.csv", "users.csv");
            } catch(const std::filesystem::filesystem_error& e) {
                throw std::runtime_error("Error replacing file: " + std::string(e.what()));
            }
            std::cout << "The user with library ID: " << id << " is successfully updated!" << std::endl;
        }

        void remove_user(const std::string& id){

            std::string error = "Could not open users.csv!";
            std::string error1 = "Could not create temp_user.csv!";

            std::ifstream file("users.csv");
            if (!file.is_open()){
                throw std::runtime_error(error);
            }

            std::ofstream temp_file("temp_user.csv");
            if (!temp_file.is_open()){
                file.close();
                throw std::runtime_error(error1);   
            }

            std::string line;
            while (std::getline(file, line)){
                std::vector<std::string> infos;
                std::stringstream ss(line);
                std::string info;
                while (std::getline(ss, info, '|')) {
                    infos.push_back(info);
                }
                if (trim(infos[0]) != trim(id)){
                    temp_file << line << "\n";
                }
            }

            file.close();
            temp_file.close();

            try {
                std::filesystem::remove("users.csv");
                std::filesystem::rename("temp_user.csv", "users.csv");
            }
            catch(const std::filesystem::filesystem_error& e){
                throw std::runtime_error("Error replacing file: " + std::string(e.what()));
            }
            std::cout << "The user with library ID:" << id << " is successfully removed from the library databank!" << std::endl;
        }

        int find_index(const std::string& id){

            std::ifstream file("users.csv");
            if (!file.is_open()) {
                return -2; // File doesn't exist or can't be opened
            }
            std::string line;
            int count = 0;
            while (std::getline(file, line)) {
                std::vector<std::string> vals;
                std::stringstream ss(line);
                std::string val;
                while (std::getline(ss, val, '|')) {
                    vals.push_back(val);
                }
                if (!vals.empty() && trim(vals[0]) == id) {
                    return count;
                }
                ++count;
            }
            file.close();
            return -1;
        }
    
        void store_user(std::string& data){

            std::ofstream users("users.csv", std::ios::app);
            if (users.is_open()) {
                users << data << '\n';
                std::cout << "The new user with ID: " << id << " is successfully added to users.csv!\n";
            } else {
                std::cout << "Error: Could not open or create users.csv!" << std::endl;
            }
        }
    
        std::string trim(const std::string& str) {

            size_t first = str.find_first_not_of(' ');
            if (first == std::string::npos) return "";
            size_t last = str.find_last_not_of(' ');
            return str.substr(first, (last - first + 1));
        }
};


#endif // USER_HPP