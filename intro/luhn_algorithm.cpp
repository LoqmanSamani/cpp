#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



int main() {
    /*
    Luhn Algorithm
    Steps:
    1. Double every second digit from right to left,
    if doubled number is two digits, split them.
    2. Add all single digits from step one.
    3. Add all odd numbered digits from right to left.
    4. Sum results from step 2 & 3.
    5. If step 4 is divisible by 10, # is valid.
    */

    std::string card_id;
    std::vector<int> digits;
    int sum = 0;

    std::cout << "Enter your 16-digits credit card id: ";
    std::getline(std::cin, card_id);

    // Remove any non-digit characters
    card_id.erase(std::remove_if(card_id.begin(), card_id.end(), 
                  [](char c) { return !std::isdigit(c); }), card_id.end());

    // Validate input length
    if (card_id.length() != 16) {
        std::cout << "Invalid card number length!" << std::endl;
        return 1;
    }

    // Process digits from right to left
    for (int i = card_id.length() - 1; i >= 0; i--) {
        int digit = card_id[i] - '0';
        
        // Every second digit (from right) gets doubled
        if ((card_id.length() - i) % 2 == 0) {
            digit *= 2;
            // If doubled digit is 2 digits, sum its digits
            if (digit > 9) {
                digit = digit / 10 + digit % 10;
            }
        }
        
        sum += digit;
    }

    // Check if sum is divisible by 10
    if (sum % 10 == 0) {
        std::cout << "Valid Credit Card Number!" << std::endl;
    } else {
        std::cout << "Invalid Credit Card Number!" << std::endl;
    }

    return 0;
}