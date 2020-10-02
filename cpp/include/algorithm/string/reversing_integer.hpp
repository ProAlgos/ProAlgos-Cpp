/*
    Reversing Integer
    -------------
    This algorithm takes a non negative integer and outputs the reversed integer in the form of a string.
    Time complexity
    ---------------
    O(N), where N equals number of digits in the integer.
    Space complexity
    ----------------
    O(N), where N equals number of digits in the intger.
*/

#ifndef REVERSING_INTEGER_HPP
#define REVERSING_INTEGER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string reverse(int x){
       std::string s=to_string(x);
       std::string r='';
       for(int i=s.length()-1; i>=0; --i){
           r+=s[i];
       }       
return r;
}

#endif // REVERSING_INTEGER_HPP
