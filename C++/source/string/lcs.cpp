/*
    Longest common subsequence algorithm
    ------------------------------------
    Given two strings, find their longest common subsequence (not sub-string).
    A classic dynamic programming algorithm for string processing.

    Time complexity
    ----------------
    O(M*N), where M and N are the lengths of the two strings.

    Space complexity
    ----------------
    O(M*N), where M and N are the lengths of the two strings.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> calc_lcs(const string& s1, const string& s2) {
    // M+1 by N+1 lengths matrix
    vector<vector<int>> lengths(s1.length()+1, vector<int>(s2.length()+1, 0));

    for (size_t i = 1; i < s1.length() + 1; i++) {
        for (size_t j = 1; j < s2.length() + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) 	// when the characters match, add 1
                lengths[i][j] = lengths[i - 1][j - 1] + 1;
            else	// pick the maximum neighbor
                lengths[i][j] = max(lengths[i - 1][j], lengths[i][j - 1]);
        }
    }

    return lengths;
}

string get_lcs(const string& s1, const string& s2) {
    vector<vector<int>> lengths = calc_lcs(s1, s2);

    size_t i = lengths.size() - 1;
    size_t j = lengths[0].size() - 1;
    
    string lcs;
    while (i != 0 and j != 0) {
        if (s1[i - 1] == s2[j - 1]) {	// if there's a match
            lcs += s1[i - 1];		// save the character
            i--, j--;
        }
        else if (lengths[i - 1][j] > lengths[i][j - 1])
            i--;	// move to the left
        else
            j--;	// move to the right
    }

    return string(lcs.rbegin(), lcs.rend());	// return the reversed string
}

int main() {
    string s1;
    cout << "Enter the first string:\n";
    getline(cin, s1);

    string s2;
    cout << "\nEnter the second string:\n";
    getline(cin, s2);

    string lcs = get_lcs(s1, s2);
    cout << "\nLargest common subsequence (of length " << lcs.length() << "):\n";
    cout << lcs << "\n";

    return 0;
}
