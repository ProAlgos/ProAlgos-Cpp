#ifndef LONGEST_BITONIC_SUBSEQUENCE
#define LONGEST_BITONIC_SUBSEQUENCE

/*
Longest Bitonic Subsequence
---------------------
This algorithm finds the length of the longest bitonic subsequence in a sequence of numbers

Time complexity
----------------
O(n^2) where n is the number of elements in the initial list

Space complexity
---------------
O(n)

*/

#include<stdio.h> 
#include<stdlib.h> 
  
/*
 *	Function finds the length of the longest_bitonic_subsequence 
 */
int longest_bitonic_subsequence( int arr[], int n ) 
{ 
   int i, j; 
  
   /* Allocate memory for LIS[] and initialize LIS values as 1 for 
      all indexes */
   int *lis = new int[n]; 
    // lis[i] ==> Longest Increasing subsequence ending with arr[i] 

   for (i = 0; i < n; i++) 
      lis[i] = 1; 
  
   /* Compute LIS values from left to right */
   for (i = 1; i < n; i++) 
      for (j = 0; j < i; j++) 
         if (arr[i] > arr[j] && lis[i] < lis[j] + 1) 
            lis[i] = lis[j] + 1; 
  
   /* Allocate memory for lds and initialize LDS values for 
      all indexes */
   int *lds = new int [n]; 
     //  lds[i] ==> Longest decreasing subsequence starting with arr[i] 
   for (i = 0; i < n; i++) 
      lds[i] = 1; 
  
   /* Compute LDS values from right to left */
   for (i = n-2; i >= 0; i--) 
      for (j = n-1; j > i; j--) 
         if (arr[i] > arr[j] && lds[i] < lds[j] + 1) 
            lds[i] = lds[j] + 1; 
  
  
   /* Return the maximum value of lis[i] + lds[i] - 1*/
   int max = lis[0] + lds[0] - 1; 
   for (i = 1; i < n; i++) 
     if (lis[i] + lds[i] - 1 > max) 
         max = lis[i] + lds[i] - 1; 
   return max; 
} 
#endif
