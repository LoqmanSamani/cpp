#ifndef BORROW_HPP
#define BORROW_HPP


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <stdexcept>
#include <filesystem>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "book.hpp"
#include "user.hpp"




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
                std::cin.ignore();
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
                break; 
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

        void borrow(std::string isbn, std::string id) {

            User user;
            if (user.id_check(id) != 1) {
                throw std::runtime_error("Wrong user ID!");
            }
    
            std::ifstream books("books.csv");
            if (!books.is_open()) {
                throw std::runtime_error("Could not access books database!");
            }
            std::ofstream temp_books("temp_books.csv");
            if (!temp_books.is_open()) {
                books.close();
                throw std::runtime_error("Could not create temporary book database!");
            }
            std::vector<std::string> book_info;
            std::string book;
            bool found = false;
            while (std::getline(books, book)) {
                std::vector<std::string> book_;
                std::stringstream ss(book);
                std::string item;
                while (std::getline(ss, item, '|')) {
                    book_.push_back(item);
                }
                if (book_.size() >= 6 && trim(isbn) == trim(book_[0]) && trim(book_[5]) == "1") {
                    book_[5] = "0";
                    book_info = book_;
                    found = true;
                    std::string data = trim(book_[0]) + "|" + trim(book_[1]) + "|" + 
                                       trim(book_[2]) + "|" + trim(book_[3]) + "|" + 
                                       trim(book_[4]) + "|" + trim(book_[5]);
                    temp_books << data << std::endl;  
                } else {
                    temp_books << book << std::endl;
                }
            }
            books.close();
            temp_books.close();
    
            if (!found) {
                std::filesystem::remove("temp_books.csv");
                throw std::runtime_error("Book not found or not available!");
            }
    
            try {
                std::filesystem::remove("books.csv");
                std::filesystem::rename("temp_books.csv", "books.csv");
            } catch (const std::filesystem::filesystem_error& e) {
                throw std::runtime_error("Error replacing file: " + std::string(e.what()));
            }
    
            auto checkout = current_date();
            auto due = due_date();
            std::string borrow_ = trim(id) + "|" + trim(book_info[0]) + "|" + checkout + "|" + due;
            std::ofstream borr("borrows.csv", std::ios::app);
            if (!borr.is_open()) {
                throw std::runtime_error("Could not access borrows database!");
            }
            borr << borrow_ << std::endl;
            borr.close();
            std::cout << "Borrow database updated!\n";
            std::cout << "The book with title: " << book_info[1] << " and ISBN: " << isbn 
                      << " is successfully borrowed to user with ID: " << id 
                      << " until " << due << std::endl;
        }

        void return_book(std::string isbn, std::string id){

            double fee = 0.0;
            double per_day = 0.25;
            User user;
            Book book;

            if (user.id_check(id) != 1) {
                throw std::runtime_error("Wrong user ID!");
            }
            if (!book.isbn_check(isbn)) {
                throw std::runtime_error("Wrong book ISBN!");
            }
            std::ifstream borr("borrows.csv");
            if (!borr.is_open()) {
                throw std::runtime_error("Could not access borrows database!");
            }
            std::ofstream temp_borr("temp_borrows.csv");
            if (!temp_borr.is_open()) {
                borr.close();
                throw std::runtime_error("Could not create temporary borrows database!");
            }
            std::string line;
            bool found = false;
            std::vector<std::string> borrow_record;
            while (std::getline(borr, line)) {
                std::vector<std::string> record;
                std::stringstream ss(line);
                std::string item;
                while (std::getline(ss, item, '|')) {
                    record.push_back(item);
                }
                if (record.size() >= 4 && trim(id) == trim(record[0]) && trim(isbn) == trim(record[1])) {
                    found = true;
                    borrow_record = record;
                    fee = days_difference(trim(record[3])) * per_day;
                    continue;
                }
                temp_borr << line << std::endl;
            }
            borr.close();
            temp_borr.close();
            if (!found) {
                std::filesystem::remove("temp_borrows.csv");
                throw std::runtime_error("Borrow record not found!");
            }
            try {
                std::filesystem::remove("borrows.csv");
                std::filesystem::rename("temp_borrows.csv", "borrows.csv");
            } catch (const std::filesystem::filesystem_error& e) {
                throw std::runtime_error("Error replacing file: " + std::string(e.what()));
            }
            std::ifstream books("books.csv");
            if (!books.is_open()) {
                throw std::runtime_error("Could not access books database!");
            }
            std::ofstream temp_books("temp_books.csv");
            if (!temp_books.is_open()) {
                books.close();
                throw std::runtime_error("Could not create temporary books database!");
            }
            std::string line_;
            std::string book_title;
            while (std::getline(books, line_)) {
                std::vector<std::string> book;
                std::stringstream ss(line_);
                std::string item;
                while (std::getline(ss, item, '|')) {
                    book.push_back(item);
                }
                if (book.size() >= 6 && trim(isbn) == trim(book[0]) && trim(book[5]) != "1") {
                    book[5] = "1";
                    book_title = trim(book[1]);
                    std::string data = trim(book[0]) + "|" + trim(book[1]) + "|" + 
                                       trim(book[2]) + "|" + trim(book[3]) + "|" + 
                                       trim(book[4]) + "|" + trim(book[5]);
                    temp_books << data << std::endl;
                } else {
                    temp_books << line_ << std::endl;
                }
            }

            books.close();
            temp_books.close();

            try {
                std::filesystem::remove("books.csv");
                std::filesystem::rename("temp_books.csv", "books.csv");
            } catch (const std::filesystem::filesystem_error& e) {
                throw std::runtime_error("Error replacing file: " + std::string(e.what()));
            }
            std::cout << std::fixed << std::setprecision(2); // Format fee
            if (fee <= 0.0) {
                std::cout << "Book with title: " << book_title << " and ISBN: " << isbn 
                          << " returned by user with ID: " << id << ". Congrats! You are on time!\n";
            } else {
                std::cout << "Book with title: " << book_title << " and ISBN: " << isbn 
                          << " returned by user with ID: " << id 
                          << ". You are late! Please pay $" << fee << " to the library!\n";
            }
        }

    private:

        std::map<int, std::string> find_indices(std::string isbn = "", std::string title = "", std::string author = ""){

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
        std::string current_date(){
            auto now = std::chrono::system_clock::now();
            std::time_t now_time = std::chrono::system_clock::to_time_t(now);
            std::tm local_tm = *std::localtime(&now_time);
            std::ostringstream oss;
            oss << std::put_time(&local_tm, "%Y-%m-%d");
            std::string date_str = oss.str();
            return date_str;
        }
        std::string due_date(){
            auto now = std::chrono::system_clock::now();
            auto due = now + std::chrono::hours(14 * 24); // +14 days
            std::time_t due_time = std::chrono::system_clock::to_time_t(due);
            std::tm local_tm = *std::localtime(&due_time);
            std::ostringstream oss;
            oss << std::put_time(&local_tm, "%Y-%m-%d");
            return oss.str();
        }
        int days_difference(const std::string& date) {
            std::tm tm = {};
            std::istringstream ss(date);
            ss >> std::get_time(&tm, "%Y-%m-%d");
            if (ss.fail()) {
                throw std::runtime_error("Invalid date format! Use YYYY-MM-DD.");
            }
            auto given_time = std::chrono::system_clock::from_time_t(std::mktime(&tm));
            auto now = std::chrono::system_clock::now();
            auto duration = now - given_time;
            auto days = std::chrono::duration_cast<std::chrono::hours>(duration).count() / 24;
            return static_cast<int>(days);
        }

        std::string trim(const std::string& str) {
            size_t first = str.find_first_not_of(' ');
            if (first == std::string::npos) return "";
            size_t last = str.find_last_not_of(' ');
            return str.substr(first, (last - first + 1));
        }
        
};


#endif // BORROW_HPP