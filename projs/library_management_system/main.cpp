#include "book.hpp"
#include "user.hpp"
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
        User user;
        user.update_user("1123223455");

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}