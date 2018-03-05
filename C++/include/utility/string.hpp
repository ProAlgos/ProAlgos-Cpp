/*
	Split string Function
	----------------------
	Breaks a given sentence into individual parts (namely words) defined
	by a character (named delimiter) and returns all the splitted words
	as a vector of string.
	The function takes two arguments as input a string sentence and a
	character delimiter (Eg: ' ', '-', 'c', '!').

	Time complexity
	---------------
	O(n), where n is the length of the string.

	Space complexity
	----------------
	O(n), where n is the length of the string.
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split_string(std::string sentence, char delimiter)
{
   std::vector<std::string> words;      //vector to  store the splitted words.
   int pos;     //stores the position of the delimiter.

    do
    {
      pos = sentence.find(delimiter);
      words.push_back(sentence.substr(0,pos));
      sentence = sentence.substr(pos+1);
    }while(pos != std::string::npos);

    return words;       //returns all the splited parts.
}
