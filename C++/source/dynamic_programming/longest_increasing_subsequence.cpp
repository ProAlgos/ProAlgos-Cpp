/*
   Longest Increasing Subsequence
   ------------------------------
   Given an unsorted array of integers, return the longest increasing subsequence

   Time complexity
   --------------
   O(N), where N is size of array

   Space complexity
   ---------------
   O(N), where N is size of array
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int find_prev_smaller(const vector<int> &a, int x) {
    for(int i = x-1; i >= 0; i--) {
        if(a[i] < a[x]) {
            return i;
        }
    }
    return -1;
}

int index_of_max(const vector<int> &a) {
    int max = INT_MIN;
    int max_i = 0;
    for(int i = 0; i < (int)a.size(); i++) {
        if(a[i] > max) {
            max = a[i];
            max_i = i;
        }
    }
    return max_i;
}

vector<int> longest_increasing_subsequence(const vector<int> &a) {
    vector<int> lis_count(a.size());
    vector<int> lis_prev(a.size());
    vector<int> ans;

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
    for(int i = 1; i < (int)a.size(); i++) {
        int previous_smaller_index = find_prev_smaller(a, i);
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

    for(int i = index_of_max(lis_count); i >= 0; i = lis_prev[i]) {
        ans.push_back(a[i]);
    }

    /*
       Reverse the vector ans so that it has values in ascending order
     */
    reverse(ans.begin(), ans.end());
    return ans;
}

#ifndef LONGEST_INCREASING_SUBSEQUENCE_TEST
int main() {
    return 0;
}
#endif
