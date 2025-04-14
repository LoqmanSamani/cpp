#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <stdexcept>
#include <filesystem>



/*
User Management:
Register a user (name, ID, email, phone number).

Remove or update user information.

Store users in a file (users.csv).
*/

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
            
        void add_user() {
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
    
    private:
        int find_index(const std::string& id) {
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
            return -1;
        }
    
        int id_check(const std::string& id) {
            int index = find_index(id);
            if (index == -1 || index == -2) return 0; // ID is unique (file missing or no match)
            return 1; // ID exists
        }
    
        void store_user(std::string& data) {
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


int main() {
    try {
        // Test adding books
        //Book book1("1984", "George Orwell", "1234434532", "Secker & Warburg", "1949", true);
        //book1.add_book();

        //Book book2("Dune", "Frank Herbert", "2345678901", "Chilton Books", "1965", true);
        //book2.add_book();

        // Test deleting a book
        //Book b;
        //b.del_book("1234434532");
        //Book b1;
        //b1.update_book("1234434532");
        User user1("112223455", "Loq", "Sam", "21", "male","loqsam@gmail.com" , "017338221");
        user1.add_user();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}