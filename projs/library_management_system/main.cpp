#include "book.hpp"
#include "user.cpp"
#include <iostream>




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
        Book b1;
        b1.update_book("1234434532");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}