
/*
Name: Painting Fence Algorithm

----------------------------------------------------------------------------------------------------
Description: Given a fence with n posts and k colors,this algorithm finds out the number of ways of painting the fence such that at most 2 adjacent posts have the same color.
Since answer can be large return it modulo 10^9 + 7.`

----------------------------------------------------------------------------------------------------

Time complexity:
The time of execution of this problem largely depends on the for loop and the value of n (number of post). In worst case senario n will be extremely large.  

Lets see how many times the loop in coutWays function runs:


When n = 1 , loop runs 0 time
When n = 2 , loop runs 1 time 
When n = 3 , loop runs 2 times
When n = 4 , loop runs 3 times and so on.

Total number of times the loop runs is 0+1+2+3+.....(n-1) = (n*(n-1))/2,

so time complexity should be O(n^2)

----------------------------------------------------------------------------------------------------

Space complexity:

It is the amount of memory used by an algorithm. In the following program we used long and int. 

long - 4 bytes
int - 2 bytes

int are n, k, i, mod, same, diff

6*2 = 12 bytes

long are dp = 4 bytes.

with 6 int elements and 1 long element, we have 7 unit spaces . 

so space complexity will be O(7). 

----------------------------------------------------------------------------------------------------

*/

#ifndef PAINTING_FENCE_HPP
#define PAINTING_FENCE_HPP
 
#include<bits/stdc++.h> 
using namespace std; 
  
// Returns count of ways to color k posts 
// using k colors 
long Paintingfence(int n, int k) 
{ 
    // To store results for subproblems

    long *dp = new long[n+1];    
 
    //long dp[n + 1]; 
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

#endif //PAINTING_FENCE_HPP
  

