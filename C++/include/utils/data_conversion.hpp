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
#define UP_A 65
#define UP_Z 91

#define LOW_A 97
#define LOW_Z 122

using std::string;

/*
    make_upper_case()
    -----------------
    This function returns a given string into upper case . 
    Loop invariant : Iterates through every charachter of the string and convert it to upper case

    Return value
    ------------
    string having all the characters in upper case .
*/

std::string make_upper_case(string str)
{
    std::string upper; // defined a string variable to store the convereted string
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str.at(i) >= LOW_A && str.at(i) <= LOW_Z) // checking for the characters that lie between the ASCII values
        {
            upper += (str.at(i) - 32); // subtracting 32 to get the character in the range 65 - 97
        }
        else
        {
            upper += str.at(i);
        }
    }
    return upper; // returning the converted string to upper case
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

std::string make_lower_case(string str)
{
    std::string lower; // defined a variable to store the converted the string
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str.at(i) >= UP_A && str.at(i) <= UP_Z) // condition to check if the characters lie in the given ASCII range
        {
            lower += (str.at(i) + 32); // adding 32 to convert the characters in lower case
        }
        else
        {
            lower += str.at(i);
        }
    }
    return lower; // returning the given string in lower case
}

#endif // DATA_VALIDATION_HPP
