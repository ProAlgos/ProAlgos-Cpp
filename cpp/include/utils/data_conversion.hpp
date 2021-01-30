/*
    Data Conversion
    -------------------
    Upper/Lower case algorithm using bit manipulation.

    Time complexity
    ---------------
    O(N), where N is the length of the input.

    Space complexity
    ----------------
    O(N), where N is the result.
 */

#ifndef DATA_CONVERSION_HPP
#define DATA_CONVERSION_HPP

#include <string>

#define UPPER_CASE_BIT_MASK 0b11011111
#define LOWER_CASE_BIT_MASK 0b00100000

bool is_letter(char c) {
    char lower_cased_char = (char)(c | LOWER_CASE_BIT_MASK);
    return lower_cased_char >= 'a' && lower_cased_char <= 'z';
}

std::string make_upper_case(const std::string& input) {
    std::string result;
    for (auto c: input) {

        if (is_letter(c)) {
            result += c & UPPER_CASE_BIT_MASK;
        }
        else {
            result += c;
        }

    }
    return result;
}

std::string make_lower_case(const std::string& input) {
    std::string result;
    for (auto current_char: input) {

        if (is_letter(current_char)) {
            result += current_char | LOWER_CASE_BIT_MASK;
        }
        else {
            result += current_char;
        }

    }
    return result;
}

#endif //DATA_CONVERSION_HPP
