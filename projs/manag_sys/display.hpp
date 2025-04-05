#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Display {
public:

    // trims leading/trailing spaces from a string
    std::string trim(const std::string& str) {

        size_t first = str.find_first_not_of(' ');
        if (first == std::string::npos) return "";
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }

    // check if student id exists in ids.csv
    bool check(const std::string& id) {
        std::ifstream file("ids.csv");
        std::string line;

        if (!file.is_open()) {
            std::cerr << "Could not open ids.csv\n";
            return false;
        }

        while (std::getline(file, line)) {
            if (trim(line) == id) return true;
        }

        return false;
    }

    // retrieve student data by ID or full name
    std::string retrive_data(std::string id = "", std::string first_name = "", std::string last_name = "") {
        std::ifstream st_file("stds.csv");
        std::string line, data;
        if (!st_file.is_open()) {
            std::cerr << "Could not open stds.csv\n";
            return "";
        }

        while (std::getline(st_file, line)) {
            std::vector<std::string> values;
            std::stringstream ss(line);
            std::string val;

            while (std::getline(ss, val, ',')) {
                values.push_back(val);
            }

            if (values.size() < 3) continue;  // invalid line

            std::string line_id = trim(values[2]);
            std::string line_first = trim(values[0]);
            std::string line_last = trim(values[1]);

            if (!id.empty()) {
                if (line_id == trim(id)) return line;
            } else if (!first_name.empty() && !last_name.empty()) {
                if (line_first == trim(first_name) && line_last == trim(last_name)) {
                    data += line + "|";
                }
            }
        }

        return data;
    }

    void display_data(const std::string& data_line) {
        
        if (data_line.empty()) {
            std::cout << "No matching student found.\n";
            return;
        }

        std::vector<std::string> fields;
        std::stringstream ss(data_line);
        std::string val;

        while (std::getline(ss, val, ',')) {
            fields.push_back(val);
        }

        if (fields.size() < 10) {
            std::cout << "Corrupted student data.\n";
            return;
        }

        std::cout << "----------------------\n";
        std::cout << "Name: " << fields[0] << " " << fields[1] << "\n";
        std::cout << "ID: " << fields[2] << "\n";
        std::cout << "Major: " << fields[3] << "\n";
        std::cout << "Gender: " << fields[4] << "\n";
        std::cout << "Age: " << fields[5] << "\n";
        std::cout << "Email: " << fields[6] << "\n";
        std::cout << "Address: " << fields[7] << "\n";
        std::cout << "Phone: " << fields[8] << "\n";
        std::cout << "Grades: " << fields[9] << "\n";
        std::cout << "----------------------\n";
    }
};