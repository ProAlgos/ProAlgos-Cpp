/*
    Edit distance
    -------------
    This algorithm finds the minimum number of edits which are required
    to convert string1 to string2. Edit here means either insert, remove
    or replace. The algorithm implemented here uses dynamic programming.

    Time complexity
    ---------------
    O(M*N), where M and N are the lengths of the two strings.

    Space complexity
    ----------------
    O(M*N), where M and N are the lengths of the two strings.
*/

#ifndef EDIT_DISTANCE_HPP
#define EDIT_DISTANCE_HPP

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
            if (i == 0) {       // str1 is empty
                dp[i][j] = j;   // insert all characters of str2
            }
            else if (j == 0) {  // str2 is empty
                dp[i][j] = i;   // remove all characters of str1
            }
            else if (str1[i-1] == str2[j-1]) {  // the last characters are same
                dp[i][j] = dp[i-1][j-1];    // ignore it and recur for remaining string
            }
            else {
                // check for minimum when last character is different.
                // operations are: insert, remove and replace
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

    return dp[length1][length2];    // the edit distance
}

#endif // EDIT_DISTANCE_HPP
