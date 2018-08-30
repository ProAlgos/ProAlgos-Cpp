/*

Edit Distance Algorithm :-
--------------------------------
Description: Find the minimum number of operations required to convert one string into another.

Time Complexity :- O(m * n)
Space Complexity :- O(m * n)
                    Where m = length of string1 and n = string2

*/



#include<bits/stdc++.h>

using namespace std;
 
int min(int x, int y, int z) {
   return min(min(x, y), z);
}
 
 int editDist(string str1 , string str2 , int m ,int n) {
    if (m == 0) return n;
 
    if (n == 0) return m;
 
    if (str1[m-1] == str2[n-1])
        return editDist(str1, str2, m-1, n-1);
 
    return 1 + min ( editDist(str1,  str2, m, n-1),    
                     editDist(str1,  str2, m-1, n),   
                     editDist(str1,  str2, m-1, n-1)
                   );
}
 
int main()
{
    string str1 = "sunday";
    string str2 = "saturday";
 
    cout << editDist( str1 , str2 , str1.length(), str2.length());
 
    return 0;
}