#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <stdexcept>
#include <filesystem>
#include "book.hpp"




/*
Borrowing System:
Allow users to borrow a book (link user ID to book ISBN).

Record the checkout date and set a due date (e.g., 14 days later).

Mark books as returned and update availability.

Store borrowing records in a file (borrows.csv).

*/

class Borrow{
    public:
        void search(){
            
            int opt;
            std::string isbn, title, author;
            while (true) {
                std::cout << "-------------------" << std::endl;
                std::cout << "   Search with !?" << std::endl;
                std::cout << "-------------------" << std::endl;
                std::cout << " 1. ISBN \n 2. Title \n 3. Author\n";
                std::cin >> opt;
                std::cin.ignore(); // clear newline
                switch(opt) {
                    case 1: 
                        std::cout << "Enter book ISBN: ";
                        std::getline(std::cin, isbn); 
                        break;
                    case 2: 
                        std::cout << "Enter book title: ";
                        std::getline(std::cin, title);
                        break;
                    case 3: 
                        std::cout << "Enter book author: ";
                        std::getline(std::cin, author);
                        break;
                    default:
                        std::cout << "Wrong option! Try again.\n";
                        continue;
                }
                break; // exit loop on valid option
            }

            std::map<int, std::string> founds = find_indices(isbn, title, author);
            std::cout << "-----------------------------------------------------------------------" << std::endl;
            std::cout << "                                 Results                               " << std::endl;
            std::cout << "-----------------------------------------------------------------------" << std::endl;
            std::cout << "   ISBN  *  Title  *  Author  *  Publication  *  Year  *  Available    " << std::endl;
            std::cout << "-----------------------------------------------------------------------" << std::endl;
            if (founds.empty()) {
                std::cout << "No books found matching the criteria.\n";
            } else {
                for (const auto& pair : founds) {
                    std::vector<std::string> items;
                    std::string item;
                    std::stringstream ss(pair.second);
                    while (std::getline(ss, item, '|')) {
                        items.push_back(item);
                    }
                    if (items.size() >= 6) {
                        for (int i = 0; i < items.size(); i++) {
                            if (i == items.size() - 1) {
                                std::cout << (trim(items[i]) == "1" ? "True" : "False") << std::endl;
                            } else {
                                std::cout << items[i] << " * ";
                            }
                        }
                    }
                }
            }
            std::cout << "-----------------------------------------------------------------------" << std::endl;
        }

    private:

        std::map<int, std::string> find_indices(std::string isbn = "", std::string title = "", std::string author = "") {
            std::map<int, std::string> availability;
            std::ifstream file("books.csv");
            if (!file.is_open()) {
                throw std::runtime_error("Could not access books database!");
            }
            std::string line;
            int inx = 0;
            while (std::getline(file, line)) {
                std::vector<std::string> items;
                std::string item;
                std::stringstream ss(line);
                while (std::getline(ss, item, '|')) {
                    items.push_back(item);
                }
                if (items.size() >= 6) { // Validate fields
                    if (!isbn.empty() && trim(items[0]) == trim(isbn)) {
                        availability[inx] = line;
                    } else if (!title.empty() && trim(items[1]) == trim(title)) {
                        availability[inx] = line;
                    } else if (!author.empty() && trim(items[2]) == trim(author)) {
                        availability[inx] = line;
                    }
                }
                inx++;
            }
            return availability;
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
        //Book book1("1984", "George Orwell", "123434532", "Secker & Warburg", "1949", true);
        //book1.add_book();

        //Book book2("Dune", "Frank Herbert", "23678901", "Chilton Books", "1965", true);
        //book2.add_book();

        // Test deleting a book
        //Book b;
        //b.del_book("1234434532");
        //Book b1;
        //b1.update_book("1234434532");
        //User user1("1123223455", "Loq", "Sam", "21", "male","loqsam@gmail.com" , "017338221");
        //user1.add_user();
        //User user;
        //user.del_user("13455");
        //User user1("13545455", "L21oq", "Samani", "21", "male", "loqsam@gmail.com", "017338221");
        //user1.add_user();
        //User user;
        //user.del_user("13455");
        //User user;
        //user.update_user("1123223455");
        Borrow b;
        b.search();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}