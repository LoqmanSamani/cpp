#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>





class Display {
    //private:
        //bool found_by_name;

    public:
        bool found_by_name;
        int index;
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

            int line_index;
            while (std::getline(file, line)) {
                if (trim(line) == id) return true;
                line_index++;
            }
            index = line_index;

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
            if (id.empty()){
                found_by_name = true;
            }else{
                found_by_name = false;
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
                    check(id); // to store the index
                    if (line_id == trim(id)) return line;
                } else if (!first_name.empty() && !last_name.empty()) {
                    if (line_first == trim(first_name) && line_last == trim(last_name)) {
                        data += line + "|";
                    }
                }
            }

            return data;
        }

        std::map<std::string, std::string> retrive_grades(std::string& d1){

            std::map<std::string, std::string> courses_grades;
            std::vector<std::string> f1;
            std::stringstream ss1(d1);
            std::string val1;

            while (std::getline(ss1, val1, ';')) {
                f1.push_back(val1);
            }
            
            for (int i = 0; i < f1.size(); i++){
                std::vector<std::string> f2;
                std::stringstream ss2(f1[i]);
                std::string val2;
                while (std::getline(ss2, val2, ':')) {
                    f2.push_back(val2);
                }
                courses_grades[f2[0]] = f2[1];
            }
            return courses_grades;
        }

        void display_data(const std::string& data_line) {
            
            if (data_line.empty()) {
                std::cout << "No matching student found.\n";
                return;
            }

            std::vector<std::string> sts;
            std::stringstream ss_(data_line);
            std::string val_;
            while (std::getline(ss_, val_, '|')){
                sts.push_back(val_);
            }

            std::cout << "---------------------------\n";
            std::cout << "Retrived Information" << "\n";
            std::cout << "  Matches Found : " << sts.size() << "\n";
            std::cout << "---------------------------\n";

            for (int i=0; i < sts.size(); i++){
                std::vector<std::string> fields;
                std::stringstream ss(sts[i]);
                std::string val;

                while (std::getline(ss, val, ',')) {
                    fields.push_back(val);
                }

                if (fields.size() < 10) {
                    std::cout << "Corrupted student data.\n";
                    return;
                }

                std::map <std::string, std::string > courses_grades = retrive_grades(fields[9]);
                if (sts.size()> 1){
                    std::cout << "                 \n";
                    std::cout << "      Match: " << i+1 << "\n";
                    std::cout << "----------------------\n";
                    std::cout << "Name: " << fields[0] << " " << fields[1] << "\n";
                    if (found_by_name){
                        std::cout << "ID: " << "*********" << "\n";
                    }else{
                        std::cout << "ID: " << fields[2] << "\n";
                    }
                    
                    std::cout << "Major: " << fields[3] << "\n";
                    std::cout << "Gender: " << fields[4] << "\n";
                    std::cout << "Age: " << fields[5] << "\n";
                    std::cout << "Email: " << fields[6] << "\n";
                    std::cout << "Address: " << fields[7] << "\n";
                    std::cout << "Phone: " << fields[8] << "\n";
                    std::cout << " Course " << "..." << " Grade " << "\n";

                    for (const auto& [course, grade] : courses_grades){
                        std::cout << " " << course << "-->" << grade << "\n";
                    }

                }else{
                    std::cout << "Name: " << fields[0] << " " << fields[1] << "\n";
                    if (found_by_name){
                        std::cout << "ID: " << "*********" << "\n";
                    }else{
                        std::cout << "ID: " << fields[2] << "\n";
                    }
                    std::cout << "Major: " << fields[3] << "\n";
                    std::cout << "Gender: " << fields[4] << "\n";
                    std::cout << "Age: " << fields[5] << "\n";
                    std::cout << "Email: " << fields[6] << "\n";
                    std::cout << "Address: " << fields[7] << "\n";
                    std::cout << "Phone: " << fields[8] << "\n";
                    std::cout << " Course " << "..." << " Grade " << "\n";

                    for (const auto& [course, grade] : courses_grades){
                        std::cout << " " << course << "-->" << grade << "\n";
                    }
                }
    
            }
        }       
        
};

