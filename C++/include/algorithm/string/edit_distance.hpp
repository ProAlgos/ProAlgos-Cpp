/*
    Edit Distance Algorithm
    -----------------------
    This algorithm finds the minimum number of edits which are required 
    to convert string1 to string2. Edit here means either insert,remove 
    or replace. The algorithm implemented here uses dynamic programming.

    Time Complexity
    ---------------
    O(m*n)  
    where-
    m is length of string1
    n is length of string2

    Space Complexity
    ----------------
    O(m*n)
    where-
    m is length of string1
    n is length of string2
*/



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
    get_edit_distance
    -----------------
    This function takes arguments as two strings : str1,str2 . Then it finds 
    the minimum number of edits required to change str1 to str2.
*/

int get_edit_distance (std::string str1, std::string str2) {
    int length1 = str1.length(); //length of str1
    int length2 = str2.length(); //length of str2
    std::vector<std::vector<int>> dp (length1 + 1, std::vector<int> (length2 + 1));
    int temp = 0;
	
    for (int i = 0; i <= length1; i++) {
        for (int j = 0; j <= length2; j++) {
            if (i == 0) {
                dp[i][j] = j;			//if str1 is empty, insert all characters of str2
            }
            else if (j == 0) {
                dp[i][j] = i;           //if str2 is empty, remove all characters of str1
            }
            else if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];     //if last charcters are same, ignore it and recur for remaining string
            }
            else {   //check for minimum when last charcter is different, operations are : insert, remove and replace
                if (dp[i-1][j] < dp[i][j-1]) {
                    temp = dp[i-1][j];     
                }
                else {
                    temp = dp[i][j-1];
                }
                if (dp[i-1][j-1] < temp) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + temp ;
                }
            }
        }
    }
    return dp[length1][length2]; //returning edit distance
}
