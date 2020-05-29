/*
    Data validation
    ---------------
    This utility function contains two sub-funtions :
    
    1) make_upper_case() : converts the characters in a string to upper case .
    
    2) make_lower_case() : converts the characters in a string to lower case . 

    Time complexity
    ---------------
    O(n), where n is the length of the string .
*/

#ifndef DATA_VALIDATION_HPP
#define DATA_VALIDATION_HPP

#include <string>

using std::string;

/*
    make_upper_case()
    -----------------
    This function returns a given string into upper case . 
    Loop invariant : Selects each character and converts it to upper case .

    Return value
    ------------
    string having all the characters in upper case .
*/

string make_upper_case(string str)
{
    //converting each character to upper case using for loop
    for (auto &c : str)
    {
        c = std::toupper(c); // using the function toupper() for conversion
    }
    return str; // returning the converted string
}

/*
    make_lower_case()
    -----------------
    This function returns a give string into lower case .
    Loop invariant : Selects each character and converts it to lower case .

    Return value
    ------------
    string having all the characters in lower case .
*/

string make_lower_case(string str)
{
    // converting each character to lower case using for loop
    for (auto &c : str)
    {
        c = std::tolower(c); //using the function tolower() for conversion
    }
    return str; //returning the converted string
}

#endif // DATA_VALIDATION_HPP