#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <stdexcept>
#include <filesystem>






class Book {
    public:
        std::string isbn;
        std::string title;
        std::string author;
        std::string publication;
        std::string year;
        bool available;
    
        Book(std::string title = "", std::string author = "", std::string isbn = "",
             std::string publication = "", std::string year = "", bool available = true)
            : title(title), author(author), isbn(isbn), publication(publication),
              year(year), available(available) {}


        void add_book() {
        if (trim(isbn).empty()) {
            std::cerr << "Error: ISBN cannot be empty!" << std::endl;
            return;
        }
        if (isbn_check(isbn)) {
            std::cerr << "Error: The book with ISBN " << isbn << " already exists!" << std::endl;
            return;
        }

        // format: isbn|title|author|publication|year|available
        std::string data = isbn + "|" +
                            (trim(title).empty() ? "None" : title) + "|" +
                            (trim(author).empty() ? "None" : author) + "|" +
                            (trim(publication).empty() ? "None" : publication) + "|" +
                            (trim(year).empty() ? "None" : year) + "|" +
                            (available ? "1" : "0");

        store_book(data);
        }

        void del_book(std::string isbn) {
            int idx = find_index(isbn);
            if (idx == -1) {
                std::cout << "The requested book with ISBN: " << isbn << " does not exist!" << std::endl;
                return;
            }
            delete_book(idx);
            std::cout << "The book with ISBN: " << isbn << " is successfully deleted!" << std::endl;
        }

        void update_book(std::string isbn) {
            int idx = find_index(isbn);
            if (idx == -1) {
                std::cout << "The requested book with ISBN: " << isbn << " does not exist!" << std::endl;
                return;
            }
            bool success = update_book_(idx);
            if (success) {
                std::cout << "The book with ISBN: " << isbn << " is successfully updated!" << std::endl;
            }
        }
        
    private:
        bool update_book_(int idx) {
            std::ifstream file("books.csv");
            if (!file.is_open()) {
                throw std::runtime_error("Could not open books.csv");
            }
            std::string line;
            int count = 0;
            while (count < idx && std::getline(file, line)) {
                count++;
            }
            if (count != idx || !std::getline(file, line)) {
                file.close();
                throw std::out_of_range("Index out of range");
            }
            file.close();
        
            std::vector<std::string> infos;
            std::stringstream ss(line);
            std::string info;
            while (std::getline(ss, info, '|')) {
                infos.push_back(info);
            }
            if (infos.size() != 6) {
                throw std::runtime_error("Invalid book data format");
            }
        
            show_book(line);
            int idx_;
            std::cout << "Your choice: ";
            std::cin >> idx_;
            std::string alt_info, new_info1, new_info2;
            std::cin.ignore(); 
        
            if (idx_ == 1) {
                std::cout << "Enter Current ISBN: ";
                std::getline(std::cin, alt_info);
                if (trim(alt_info) != trim(infos[0])) {
                    std::cout << "False input! try again!!!" << std::endl;
                    return false; 
                } else {
                    std::cout << "Enter new ISBN: ";
                    std::getline(std::cin, new_info1);
                    std::cout << "Repeat new ISBN: ";
                    std::getline(std::cin, new_info2);
                    if (trim(new_info1) != trim(new_info2)) {
                        std::cout << "Error: new ISBN 1 & 2 are not the same!" << std::endl;
                        return false; 
                    }
                }
            }
            else if (idx_ == 2) {
                std::cout << "Enter Current Title: ";
                std::getline(std::cin, alt_info);
                if (trim(alt_info) != trim(infos[1])) {
                    std::cout << "False input! try again!!!" << std::endl;
                    return false;
                } else {
                    std::cout << "Enter new Title: ";
                    std::getline(std::cin, new_info1);
                    std::cout << "Repeat new Title: ";
                    std::getline(std::cin, new_info2);
                    if (trim(new_info1) != trim(new_info2)) {
                        std::cout << "Error: new title 1 & 2 are not the same!" << std::endl;
                        return false;
                    }
                }
            }
            else if (idx_ == 3) {
                std::cout << "Enter Current Author: ";
                std::getline(std::cin, alt_info);
                if (trim(alt_info) != trim(infos[2])) {
                    std::cout << "False input! try again!!!" << std::endl;
                    return false;
                } else {
                    std::cout << "Enter new Author: ";
                    std::getline(std::cin, new_info1);
                    std::cout << "Repeat new Author: ";
                    std::getline(std::cin, new_info2);
                    if (trim(new_info1) != trim(new_info2)) {
                        std::cout << "Error: new author 1 & 2 are not the same!" << std::endl;
                        return false;
                    }
                }
            }
            else if (idx_ == 4) {
                std::cout << "Enter Current Publication: ";
                std::getline(std::cin, alt_info);
                if (trim(alt_info) != trim(infos[3])) {
                    std::cout << "False input! try again!!!" << std::endl;
                    return false;
                } else {
                    std::cout << "Enter new Publication: ";
                    std::getline(std::cin, new_info1);
                    std::cout << "Repeat new Publication: ";
                    std::getline(std::cin, new_info2);
                    if (trim(new_info1) != trim(new_info2)) {
                        std::cout << "Error: new publication 1 & 2 are not the same!" << std::endl;
                        return false;
                    }
                }
            }
            else if (idx_ == 5) {
                std::cout << "Enter Current Year: ";
                std::getline(std::cin, alt_info);
                if (trim(alt_info) != trim(infos[4])) {
                    std::cout << "False input! try again!!!" << std::endl;
                    return false;
                } else {
                    std::cout << "Enter new Year: ";
                    std::getline(std::cin, new_info1);
                    std::cout << "Repeat new Year: ";
                    std::getline(std::cin, new_info2);
                    if (trim(new_info1) != trim(new_info2)) {
                        std::cout << "Error: new year 1 & 2 are not the same!" << std::endl;
                        return false;
                    }
                }
            }
            else if (idx_ == 6) {
                std::cout << "Enter Current Availability: ";
                std::getline(std::cin, alt_info);
                if (trim(alt_info) != trim(infos[5])) {
                    std::cout << "False input! try again!!!" << std::endl;
                    return false;
                } else {
                    std::cout << "Enter new Availability (0 or 1): ";
                    std::getline(std::cin, new_info1);
                    std::cout << "Repeat new Availability: ";
                    std::getline(std::cin, new_info2);
                    if (trim(new_info1) != trim(new_info2)) {
                        std::cout << "Error: new availability 1 & 2 are not the same!" << std::endl;
                        return false;
                    }
                    if (trim(new_info1) != "0" && trim(new_info1) != "1") {
                        std::cout << "Error: availability must be 0 or 1!" << std::endl;
                        return false;
                    }
                }
            }
            else {
                std::cout << "Error: false input index!" << std::endl;
                return false;
            }
        
            infos[idx_ - 1] = trim(new_info1);
        
            std::string updated_book = trim(infos[0]) + "|" +
                                      (trim(infos[1]).empty() ? "None" : trim(infos[1])) + "|" +
                                      (trim(infos[2]).empty() ? "None" : trim(infos[2])) + "|" +
                                      (trim(infos[3]).empty() ? "None" : trim(infos[3])) + "|" +
                                      (trim(infos[4]).empty() ? "None" : trim(infos[4])) + "|" +
                                      (trim(infos[5]).empty() ? "0" : trim(infos[5]));
        
            replace_book(idx, updated_book);
            return true; 
        }

        
        void show_book(std::string line){ 
            std::cout << "----------------------------------------------" << std::endl;
            std::cout << "Which information do you want to change (1-6)?" << std::endl;
            std::cout << "----------------------------------------------" << std::endl;
            show(line);
        }

        void show(std::string& line){

            std::vector<std::string> infos;
            std::stringstream ss(line);
            std::string info;
            while (std::getline(ss, info, '|')) {
                infos.push_back(info);
            }

            std::cout << "  1) ISBN: " << infos[0] << std::endl;
            std::cout << "  2) Title: " << infos[1] << std::endl;
            std::cout << "  3) Author: " << infos[2] << std::endl;
            std::cout << "  4) Publication: " << infos[3] << std::endl;
            std::cout << "  5) Year: " << infos[4] << std::endl;
            std::cout << "  6) Availability: " << infos[5] << std::endl;
            std::cout << "----------------------------------------------" << std::endl;
        }

        void replace_book(int idx, std::string& updated_book) {
            std::ifstream file("books.csv");
            if (!file.is_open()) {
                throw std::runtime_error("Could not open books.csv");
            }
        
            std::ofstream temp_file("temp_books.csv");
            if (!temp_file.is_open()) {
                file.close();
                throw std::runtime_error("Unable to create temporary file");
            }
        
            std::string line;
            int count = 0;
            bool found = false;
        
            while (std::getline(file, line)) {
                if (count != idx) {
                    temp_file << line << '\n';
                } else {
                    found = true;
                    temp_file << updated_book << '\n';
                }
                ++count;
            }
        
            file.close();
            temp_file.close();
        
            if (!found && idx >= 0) {
                std::filesystem::remove("temp_books.csv");
                throw std::out_of_range("Index " + std::to_string(idx) + " is out of range");
            }
        
            try {
                std::filesystem::remove("books.csv");
                std::filesystem::rename("temp_books.csv", "books.csv");
            } catch (const std::filesystem::filesystem_error& e) {
                throw std::runtime_error("Error replacing file: " + std::string(e.what()));
            }
        }


        void delete_book(int idx) {
            std::ifstream file("books.csv");
            if (!file.is_open()) {
                throw std::runtime_error("Could not open books.csv");
            }
    
            std::ofstream temp_file("temp_books.csv");
            if (!temp_file.is_open()) {
                file.close();
                throw std::runtime_error("Unable to create temporary file");
            }
    
            std::string line;
            int count = 0;
            bool found = false;
    
            while (std::getline(file, line)) {
                if (count != idx) {
                    temp_file << line << '\n';
                } else {
                    found = true;
                }
                ++count;
            }
    
            file.close();
            temp_file.close();
    
            if (!found && idx >= 0) {
                std::filesystem::remove("temp_books.csv");
                throw std::out_of_range("Index " + std::to_string(idx) + " is out of range");
            }
    
            try {
                std::filesystem::remove("books.csv");
                std::filesystem::rename("temp_books.csv", "books.csv");
            } catch (const std::filesystem::filesystem_error& e) {
                throw std::runtime_error("Error replacing file: " + std::string(e.what()));
            }
        }

        void store_book(std::string& data) {
            std::ofstream books("books.csv", std::ios::app);
            if (books.is_open()) {
                books << data << '\n';
                std::cout << "The new book with ISBN: " << isbn << " is successfully added to books.csv!\n";
                books.close();
            } else {
                std::cerr << "Error: Could not open books.csv!\n";
            }
        }

        int find_index(const std::string& isbn) {
            std::ifstream file("books.csv");
            if (!file.is_open()) {
                return -1;
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
                if (!vals.empty() && trim(vals[0]) == isbn) {
                    file.close();
                    return count;
                }
                ++count;
            }
            file.close();
            return -1;
        }
    
        bool isbn_check(const std::string& isbn) {
            return find_index(isbn) != -1;
        }

        std::string trim(const std::string& str) {
            size_t first = str.find_first_not_of(' ');
            if (first == std::string::npos) return "";
            size_t last = str.find_last_not_of(' ');
            return str.substr(first, (last - first + 1));
        }

};