/*
	Split string Function
	----------------------
	Breaks a given string into individual parts (namely words) defined
	by a character (named delimiter) and returns all the splitted words
	as a vector of string.
	The function takes two arguments as input a string str and a
	character delimiter (Eg: ' ', '-', 'c', '!').

	Time complexity
	---------------
	O(n^2), where n is the length of the string.

	Space complexity
	----------------
	O(n), where n is the length of the string.
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split_string( const std::string& str, char delimiter)
{
   std::vector<std::string> words;      //vector to  store the splitted words.
   size_t pos, prev_pos = -1;     //stores the position of the delimiter.

    do
    {
      pos = str.find(delimiter, prev_pos + 1);
      words.push_back(str.substr(prev_pos + 1, pos - prev_pos - 1));
      prev_pos = pos;
    }while(pos != std::string::npos);

    return words;       //returns all the splited parts.
}
