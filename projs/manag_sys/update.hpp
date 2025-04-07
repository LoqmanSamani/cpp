#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <vector>
#include <regex>
#include "display.hpp"

class Update : public Display {
public:
    void update(std::string info) {
        std::string updated_info;
        std::string updated_id;
        int opt;

        if (!found_by_name) {
            std::cout << "Which one do you want to update:?! (enter the number of the option!)" << std::endl;
            std::cout << "--------------------------------------------------------------------" << std::endl;
            std::cout << "  1. first_name\n  2. last_name\n  3. student id\n  4. study major\n";
            std::cout << "  5. student gender\n  6. student age\n  7. email address\n";
            std::cout << "  8. address\n  9. phone_num\n 10. a grade\n";
            std::cout << "-------------------------------------------------------------------" << std::endl;

            std::cin >> opt;
            updated_info = change_info(info, opt);

            // Fix: update `updated_id` from updated_info if needed
            std::vector<std::string> parts;
            std::stringstream ss(updated_info);
            std::string val;
            while (std::getline(ss, val, ',')) {
                parts.push_back(val);
            }
            if (parts.size() >= 3) updated_id = parts[2];

            update_database("ids.csv", updated_id);
            update_database("stds.csv", updated_info);
        }
    }

    void update_database(std::string file_name, const std::string& data) {
        int idx = index;  // 'index' must be set externally

        std::ifstream infile(file_name);
        if (!infile.is_open()) {
            std::cerr << "Error: could not open file " << file_name << " for reading.\n";
            return;
        }

        std::vector<std::string> lines;
        std::string line;
        while (std::getline(infile, line)) {
            lines.push_back(line);
        }
        infile.close();

        if (idx < 0 || idx >= static_cast<int>(lines.size())) {
            std::cerr << "Error: index out of range.\n";
            return;
        }

        lines[idx] = data;

        std::ofstream outfile(file_name);
        if (!outfile.is_open()) {
            std::cerr << "Error: could not open file " << file_name << " for writing.\n";
            return;
        }

        for (const auto& l : lines) {
            outfile << l << '\n';
        }

        std::cout << "Line " << idx << " in " << file_name << " updated successfully.\n";
    }

    std::string change_info(std::string& info, int opt) {
        std::vector<std::string> messages = {
            "Enter the new first name: ",
            "Enter the new last name: ",
            "Enter the new id: ",
            "Enter the new major: ",
            "Enter the new gender: ",
            "Enter the new age: ",
            "Enter the new email: ",
            "Enter the new address: ",
            "Enter the new phone number: "
        };

        std::string new_info;

        // Grades update
        if (opt == 10) {
            std::vector<std::string> vals;
            std::stringstream ss(info);
            std::string val;
            while (std::getline(ss, val, ',')) {
                vals.push_back(val);
            }

            std::vector<std::string> courses;
            std::stringstream ss_courses(vals[9]); // fixed: get from the actual grades field
            std::string course_entry;
            while (std::getline(ss_courses, course_entry, ';')) {
                if (!course_entry.empty())
                    courses.push_back(course_entry);
            }

            std::cout << "   Courses & Grades" << std::endl;
            std::cout << "----------------------" << std::endl;
            for (int j = 0; j < courses.size(); j++) {
                std::cout << "   " << courses[j] << std::endl;
            }

            int opt1;
            std::cout << "What do you want to change?!" << std::endl;
            std::cout << " 1. change a grade.\n 2. add a new course.\n";
            std::cin >> opt1;

            if (opt1 == 1) {
                std::string new_grade;
                std::cout << "Enter the course and its updated grade in format (course:grade): ";
                std::cin >> new_grade;

                std::vector<std::string> c1;
                std::stringstream ss1(new_grade);
                std::string v1;
                while (std::getline(ss1, v1, ':')) {
                    c1.push_back(v1);
                }

                for (int k = 0; k < courses.size(); k++) {
                    std::vector<std::string> split_course;
                    std::stringstream ss_course(courses[k]);
                    std::string part;
                    while (std::getline(ss_course, part, ':')) {
                        split_course.push_back(part);
                    }

                    if (split_course[0] == c1[0]) {
                        courses[k] = new_grade;
                        break;
                    }
                }
            }
            else if (opt1 == 2) {
                std::string new_grade;
                std::cout << "Enter the course and its grade in format (course:grade): ";
                std::cin >> new_grade;

                std::vector<std::string> c2;
                std::stringstream ss2(new_grade);
                std::string v2;
                while (std::getline(ss2, v2, ':')) {
                    c2.push_back(v2);
                }

                if (c2.size() != 2) {
                    std::cout << "Wrong entry!" << std::endl;
                    return "";
                }
                else {
                    courses.push_back(new_grade);
                }
            }
            else {
                std::cout << "Wrong entry! Try again." << std::endl;
                return "";
            }

            for (int l = 0; l < 9; l++) {
                new_info += vals[l] + ",";
            }

            for (const auto& course : courses) {
                new_info += course + ";";
            }

            return new_info;
        }

        // Standard field update
        if (opt >= 1 && opt <= 9) {
            std::string new_val;
            std::cout << messages[opt - 1];
            std::cin >> new_val;

            std::vector<std::string> vals;
            std::stringstream ss(info);
            std::string val;
            while (std::getline(ss, val, ',')) {
                vals.push_back(val);
            }

            if (opt - 1 < vals.size()) {
                vals[opt - 1] = new_val;
            }

            for (int i = 0; i < vals.size(); ++i) {
                new_info += vals[i];
                if (i != vals.size() - 1)
                    new_info += ",";
            }

            return new_info;
        }

        std::cout << "Invalid option selected." << std::endl;
        return "";
    }
};


