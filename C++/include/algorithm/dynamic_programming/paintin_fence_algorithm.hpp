/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at 
most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.
*/


// C++ program for Painting Fence Algorithm 
#include<bits/stdc++.h> 
using namespace std; 
  
// Returns count of ways to color k posts 
// using k colors 
long countWays(int n, int k) 
{ 
    // To store results for subproblems 
    long dp[n + 1]; 
    memset(dp, 0, sizeof(dp)); 
    int mod = 1000000007; 
  
    // There are k ways to color first post 
    dp[1] = k; 
  
    // There are 0 ways for single post to 
    // violate (same color_ and k ways to 
    // not violate (different color) 
    int same = 0, diff = k; 
  
    // Fill for 2 posts onwards 
    for (int i = 2; i <= n; i++) 
    { 
        // Current same is same as previous diff 
        same = diff; 
  
        // We always have k-1 choices for next post 
        diff = dp[i-1] * (k-1); 
        diff = diff % mod; 
  
        // Total choices till i. 
        dp[i] = (same + diff) % mod; 
    } 
  
    return dp[n]; 
} 
  
// Driver code 
int main() 
{ 
    int n = 3, k = 2; 
    cout << countWays(n, k) << endl; 
    return 0; 
} 
