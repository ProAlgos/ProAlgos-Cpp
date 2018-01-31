/*
   Longest Increasing Subsequence
   ------------------------------
   Given an unsorted array of integers, return the longest increasing subsequence

   Time complexity
   --------------
   O(N^2), where N is size of array

   Space complexity
   ---------------
   O(N), where N is size of array
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

/*
    Returns index i of the closest smaller value to current_index 
    in vector input, such that i < current_index
 */
int find_prev_smaller(const vector<int> &input, int current_index) {
    for(int i = current_index - 1; i >= 0; i--) {
        if(input[i] < input[current_index]) {
            return i;
        }
    }
    return -1;
}

/*
    Returns index of the max value in input vector
 */
int index_of_max(const vector<int> &input) {
    int max = INT_MIN;
    int max_i = 0;
    for(int i = 0; i < (int)input.size(); i++) {
        if(input[i] > max) {
            max = input[i];
            max_i = i;
        }
    }
    return max_i;
}

vector<int> longest_increasing_subsequence(const vector<int> &input) {
    vector<int> lis_count(input.size());
    vector<int> lis_prev(input.size());

    /*
        Initializing index 0.
        prev is -1 and count is 0, since it has no prev values
     */
    lis_count[0] = 1;
    lis_prev[0] = -1;

    /*
       For each element, lis_count is the max of
       lis_count of prev element or
       1 + lis_count of the closest element smaller than it.
       If an element has no smaller before it, then values 
       are same as that of index 0
     */
    for(int i = 1; i < (int)input.size(); i++) {
        int previous_smaller_index = find_prev_smaller(input, i);
        if(previous_smaller_index == -1) {
            lis_count[i] = 1;
            lis_prev[i] = -1;
        } else if(lis_count[i-1] > lis_count[previous_smaller_index] + 1) {
            lis_count[i] = lis_count[i-1];
            lis_prev[i] = i-1;
        } else {
            lis_count[i] = 1 + lis_count[previous_smaller_index];
            lis_prev[i] = previous_smaller_index;
        }
    }
    
    /*
       Find the max value of lis_count to find the size and last index of the LIS.
       From there, you can backtrack to the value where lis_prev is -1.
       Add all these values to the vector ans
     */
    vector<int> ans;
    for(int i = index_of_max(lis_count); i >= 0; i = lis_prev[i]) {
        ans.push_back(input[i]);
    }

    /*
       Reverse the vector ans so that it has values in ascending order
     */
    reverse(ans.begin(), ans.end());
    return ans;
}

#ifndef LONGEST_INCREASING_SUBSEQUENCE_TEST
int main() {
    /*
        Take input from user and print longest_increasing_subsequence
     */
    int n;
    cout << "Enter size of the input array" << endl;
    cin >> n;
    vector<int> input(n);
    cout << "Enter the input array" << endl;
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    cout << "Longest Increasing Subsequence is" << endl;
    vector<int> ans = longest_increasing_subsequence(input);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
#endif
