/*
    Longest Decreasing Subsequence
    -----------------
    Given an array of N integers, find the length of the longest decreasing 
    subsequence.

    Time complexity
    ---------------
    O(N^2), where N is the size of array

    Space complexity
    ----------------
    O(N).
*/

#include <bits/stdc++.h> 
using namespace std; 
  
// Function for finding longest decreasing subsequence
int longest_decreasing_subsequence(int *arr, int n) 
{ 
    int decreasing_sequence[n]; 
  
    //Decreasing sequence is 1 for each number individually
    for (int i = 0; i < n; i++) 
        decreasing_sequence[i] = 1; 
  
    // Compute decresing sequence from every index 
    for (int i = 1; i < n; i++) 
        for (int j = 0; j < i; j++) 
            if (arr[i] < arr[j] && decreasing_sequence[i] < decreasing_sequence[j] + 1) 
                decreasing_sequence[i] = decreasing_sequence[j] + 1; 
  
    //Find the max value
    int maxval = 0; 
    for (int i = 0; i < n; i++) 
        if (maxval < decreasing_sequence[i]) 
            maxval = decreasing_sequence[i]; 
  
    // Return maximum length
    return maxval; 
} 

// Driver Code 
int main() 
{ 
    int n;
    cout << "Enter array size\n";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter array elements space separated\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Length of Longest Decreasing Subsequence is " << longest_decreasing_subsequence(arr, n); 
    return 0; 
} 
