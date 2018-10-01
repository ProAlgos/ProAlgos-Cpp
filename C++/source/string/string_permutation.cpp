/*
    String Permutation Algorithm
    ------------------------------------
    Given a string, print all its permutations.

    Time complexity
    ----------------
    O(N!), where N is the string length.

    Space complexity
    ----------------
    O(N), where N is the string length.
*/

#include <bits/stdc++.h> 
using namespace std; 
  
void permute(string str) 
{ 
    // Sort lexicographically 
    sort(str.begin(), str.end()); 

    do 
    { 
       cout << str << endl; 
    } while (next_permutation(str.begin(), str.end())); 
} 
  
int main() 
{ 
    string str;
    cout << "Enter a string:\n";
    cin >> str;
    cout << "Permutations are:\n";
    permute(str); 
    return 0; 
} 
