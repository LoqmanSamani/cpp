#include "add_std.hpp"
#include "display.hpp"
#include "update.hpp"
#include <iostream>



using namespace std;
int main() {
    // student management system program
    // a map to store course names and their corresponding grades for a student
    map<string, int> grades = {
        {"math", 89},
        {"phisics", 95},
        {"biology", 78}
    };

    // creates a new Student object with sample data, including name, ID, major, gender, age, email, address, phone number, and grades
    Student st1("Loqman1", "Samani", "st123456", "biology", 'm', 21, "loqman@gmail.com", "123 Main St", 123456789, grades);
    
    cout << st1.first_name << endl;
    // add the student to the database (ids.csv and stds.csv) if the ID doesn't already exist
    st1.add_student();
    // display information about the student management system and required data fields
    st1.system_info();

    // create a Display object to retrieve and show student data
    Display d;
    // retrieve student data by ID from stds.csv
    string found = d.retrive_data("st123456");
    // display the retrieved student information in a formatted manner
    d.display_data(found);
   
    // create an Update object to retrieve, display, and modify student data
    Update u;
    // retrieve student data by ID from stds.csv (reusing variable name 'found')
    found = u.retrive_data("st123456");
    // print the raw retrieved data string for debugging or verification
    cout << found << endl;
    // display the retrieved student information using Update's display method
    u.display_data(found);
    // prompt the user to update specific fields of the student's data and apply changes to the database
    u.update(found);

    return 0;
}