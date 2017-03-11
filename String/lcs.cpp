/*
    Longest Common Subsequence Algorithm:
    Given two strings s1 and s2, returns the longest common subsequence (not substring) of both.
    It is a classic Dynamic Programming example for string processing.
    
    Time Complexity:
    O(NM), where N is the length of the string s1 and M the length of string s2.
    
    Space Complexity:
    0(NM), where N is the length of the string s1 and M the length of string s2.    
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector< vector<int> > lcs(string s1, string s2){
	//A (m+1 x n+1) cost matrix
	vector< vector<int> > costs(s1.length()+1, vector<int>(s2.length()+1, 0));
	
	for( int i=1; i<s1.length()+1; i++ ){
		for( int j=1; j<s2.length()+1; j++ ){
			if(s1[i-1] == s2[j-1])
				//When the strings math, add 1
				costs[i][j] = costs[i-1][j-1]+1;
			else
				//If there is no match, pick the maximum neighbor
				costs[i][j] = max(costs[i-1][j], costs[i][j-1]);
		}
	}
	
	return costs;
}


string search(string s1, string s2){
	//get the matrix with costs
	vector< vector<int> > costs = lcs(s1, s2);

	//indexes starting at last position
	int i=costs.size()-1, j=costs[0].size()-1;
	string output;
	
	while(i != 0 && j != 0){
		if(s1[i-1] == s2[j-1]){
			//if there is a match, save the char of this position
			output += s1[i-1];
			i--;
			j--;
		}else if(costs[i-1][j] > costs[i][j-1]){
			//move to the left
			i--;
		}else{
			//move to the right
			j--;
		}
	}
	//return the reversed version of the string
	return 	string(output.rbegin(), output.rend());
}


int main() {
    string s1, s2;
    cout << "Enter the first string : ";
    getline(cin, s1);

    cout << "\nEnter the second string : ";
    getline(cin, s2);

    string lcso = search(s1, s2);

    cout << "\nLargest Common Subsequence found : " << lcso << endl;

    return 0;
}

