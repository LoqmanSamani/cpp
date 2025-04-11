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

Book Management:
Add a new book (title, author, ISBN, genre, publication year).

Remove a book by ISBN.

Update book details (e.g., change availability status).

Store books in a file (books.csv).


*/

class Book {
    public:
        std::string title;
        std::string author;
        std::string isbn;
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


    private:

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




int main() {
    try {
        // Test adding books
        Book book1("1984", "George Orwell", "1234434532", "Secker & Warburg", "1949", true);
        book1.add_book();

        Book book2("Dune", "Frank Herbert", "2345678901", "Chilton Books", "1965", true);
        book2.add_book();

        // Test deleting a book
        //Book b;
        //b.del_book("1234434532");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}