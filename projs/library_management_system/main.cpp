#include <iostream>
#include <fstream>
#include <stdexcept>
#include "user.hpp"
#include "book.hpp"
#include "borrow.hpp"

int main() {
    try {
        // Clear CSV files to ensure a clean slate for testing
        // Comment out if you want to preserve existing data
        std::ofstream("users.csv").close();
        std::ofstream("books.csv").close();
        std::ofstream("borrows.csv").close();

        // -----------------------------------
        // Test 1: Add a User
        // Purpose: Verify that a user can be added to users.csv
        // Expected: User is added, no errors
        // -----------------------------------
        std::cout << "\n=== Test 1: Adding a User ===\n";
        User user1("112223455", "John", "Doe", "30", "male", "john.doe@gmail.com", "123456789");
        user1.add_user();
        std::cout << "User with ID 112223455 added successfully.\n";

        // -----------------------------------
        // Test 2: Check User Existence
        // Purpose: Verify that id_check confirms the added user
        // Expected: id_check("112223455") returns 1
        // -----------------------------------
        std::cout << "\n=== Test 2: Checking User Existence ===\n";
        User user_check;
        if (user_check.id_check("112223455") == 1) {
            std::cout << "User ID 112223455 found in users.csv.\n";
        } else {
            throw std::runtime_error("Test 2 failed: User ID 112223455 not found!");
        }

        // -----------------------------------
        // Test 3: Add Books
        // Purpose: Add two books to books.csv for borrowing tests
        // Expected: Books are added, no errors
        // -----------------------------------
        std::cout << "\n=== Test 3: Adding Books ===\n";
        Book book1("1984", "George Orwell", "123434532", "Secker & Warburg", "1949", true);
        book1.add_book();
        std::cout << "Book '1984' with ISBN 123434532 added.\n";
        Book book2("Dune", "Frank Herbert", "23678901", "Chilton Books", "1965", true);
        book2.add_book();
        std::cout << "Book 'Dune' with ISBN 23678901 added.\n";

        // -----------------------------------
        // Test 4: Check Book Existence
        // Purpose: Verify that isbn_check confirms the added books
        // Expected: isbn_check returns true for both ISBNs
        // -----------------------------------
        std::cout << "\n=== Test 4: Checking Book Existence ===\n";
        Book book_check;
        if (book_check.isbn_check("123434532")) {
            std::cout << "Book with ISBN 123434532 found in books.csv.\n";
        } else {
            throw std::runtime_error("Test 4 failed: Book ISBN 123434532 not found!");
        }
        if (book_check.isbn_check("23678901")) {
            std::cout << "Book with ISBN 23678901 found in books.csv.\n";
        } else {
            throw std::runtime_error("Test 4 failed: Book ISBN 23678901 not found!");
        }

        // -----------------------------------
        // Test 5: Search Books
        // Purpose: Test searching books by title
        // Expected: Displays books with title "Dune"
        // Note: Requires user input (enter "2" for title, then "Dune")
        // -----------------------------------
        std::cout << "\n=== Test 5: Searching Books by Title ===\n";
        Borrow borrow;
        std::cout << "Please select option 2 and enter 'Dune' when prompted.\n";
        borrow.search();

        // -----------------------------------
        // Test 6: Borrow a Book
        // Purpose: Test borrowing a book (updates availability, creates borrow record)
        // Expected: Book "1984" borrowed, availability set to 0, record in borrows.csv
        // -----------------------------------
        std::cout << "\n=== Test 6: Borrowing a Book ===\n";
        borrow.borrow("123434532", "112223455");

        // -----------------------------------
        // Test 7: Return Book (On Time)
        // Purpose: Test returning a book before due date
        // Expected: Borrow record removed, availability set to 1, "on time" message
        // -----------------------------------
        std::cout << "\n=== Test 7: Returning a Book (On Time) ===\n";
        borrow.return_book("123434532", "112223455");

        // -----------------------------------
        // Test 8: Borrow Again for Late Return
        // Purpose: Re-borrow the book to test late return
        // Expected: Same as Test 6
        // -----------------------------------
        std::cout << "\n=== Test 8: Borrowing Again for Late Return Test ===\n";
        borrow.borrow("123434532", "112223455");

        // -----------------------------------
        // Test 8.5: Set Past Due Date
        // Purpose: Modify borrows.csv to set a past due date for Test 9
        // Expected: borrows.csv updated with due date 2025-04-10
        // -----------------------------------
        std::cout << "\n=== Test 8.5: Setting Past Due Date for Late Return ===\n";
        {
            std::ifstream borr_in("borrows.csv");
            std::ofstream borr_out("temp_borrows.csv");
            std::string line;
            while (std::getline(borr_in, line)) {
                std::vector<std::string> record;
                std::stringstream ss(line);
                std::string item;
                while (std::getline(ss, item, '|')) {
                    record.push_back(item);
                }
                if (record.size() >= 4 && record[1] == "123434532") {
                    record[3] = "2025-04-10"; // Set past due date
                    borr_out << record[0] << "|" << record[1] << "|" << record[2] << "|" << record[3] << "\n";
                } else {
                    borr_out << line << "\n";
                }
            }
            borr_in.close();
            borr_out.close();
            std::filesystem::remove("borrows.csv");
            std::filesystem::rename("temp_borrows.csv", "borrows.csv");
            std::cout << "borrows.csv updated with due date 2025-04-10 for ISBN 123434532.\n";
        }

        // -----------------------------------
        // Test 9: Return Book (Late)
        // Purpose: Test returning a book after due date
        // Expected: Borrow record removed, availability set to 1, fine calculated
        // -----------------------------------
        std::cout << "\n=== Test 9: Returning a Book (Late) ===\n";
        borrow.return_book("123434532", "112223455");

        // -----------------------------------
        // Test 10: Delete User
        // Purpose: Verify that a user can be deleted from users.csv
        // Expected: User removed, no errors
        // -----------------------------------
        std::cout << "\n=== Test 10: Deleting a User ===\n";
        User user_del;
        user_del.del_user("112223455");
        std::cout << "User with ID 112223455 deleted successfully.\n";

        // -----------------------------------
        // Test 11: Delete Book
        // Purpose: Verify that a book can be deleted from books.csv
        // Expected: Book removed, no errors
        // -----------------------------------
        std::cout << "\n=== Test 11: Deleting a Book ===\n";
        Book book_del;
        book_del.del_book("23678901");
        std::cout << "Book with ISBN 23678901 deleted successfully.\n";

        // -----------------------------------
        // Test 12: Error Handling (Invalid Borrow)
        // Purpose: Test borrowing with invalid user ID
        // Expected: Exception thrown, error message displayed
        // -----------------------------------
        std::cout << "\n=== Test 12: Borrowing with Invalid User ID ===\n";
        try {
            borrow.borrow("123434532", "999999999");
            std::cout << "Test 12 failed: Should have thrown an error!\n";
        } catch (const std::exception& e) {
            std::cout << "Expected error caught: " << e.what() << "\n";
        }

        // -----------------------------------
        // Test 13: Error Handling (Invalid Return)
        // Purpose: Test returning a non-existent borrow record
        // Expected: Exception thrown, error message displayed
        // -----------------------------------
        std::cout << "\n=== Test 13: Returning Non-Existent Borrow ===\n";
        User new_user("999999999", "Jane", "Smith", "25", "female", "jane.smith@gmail.com", "987654321");
        new_user.add_user();
        try {
            borrow.return_book("123434532", "999999999");
            std::cout << "Test 13 failed: Should have thrown an error!\n";
        } catch (const std::exception& e) {
            std::cout << "Expected error caught: " << e.what() << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\nAll tests completed successfully!\n";
    return 0;
}