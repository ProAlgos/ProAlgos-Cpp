/*
	String Splice Function
	----------------------
	Breaks a given sentence into individual words and returns
	a string.
	The function takes two arguments as input a string and the
	position of word you want to get in return.
	For Example if you call:
	splice("Hello I am Utkarsh", 4)
	The returned value will be "Utkarsh".

	Time complexity
	---------------
	O(n), where n is the length of the string.

	Space complexity
	----------------
	O(n), where n is the length of the string.
*/

#include <iostream>
#include <string.h>

using namespace std;

string splice(string sentence, int word)
{
   string words[sentence.length()];		//initilized an array of strings to store words.
   int i = 0, pos = NULL;		//iterative variables.

    do
    {
      pos = sentence.find(" ");
      words[i] = sentence.substr(0,pos);
       sentence = sentence.substr(pos+1);
       i++;
    }while(pos != string::npos);

    return words[word-1];		//returns the desired word.
}

/*
int main(){
    string test = "I knew you were trouble when you walked in";
    cout<<splice(test,4);
    return 0;
}
*/
