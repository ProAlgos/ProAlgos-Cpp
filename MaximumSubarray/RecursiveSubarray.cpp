// This is a recursive algorithm to solve the Maximum Subarray Sum Problem
// As a recursive, divide-and-conqure algorithm, this runs in O(n log n)
// Thus, Kadane's algorithm (which runs in O(n)) is more efficient and a better choice.
// This is included as an example of a recursive solution.

#include <stdio.h>

// helper function - returns the maximum of 2 integers
int max(int a, int b) 
    { 
        if (a > b)
            return a;
        else
            return b;
    }

// helper function - returns the maximum of 3 integers
int max(int a, int b, int c) 
    { 
        return max(max(a, b), c);
    }

// Helper function - handles case when max sub array exists both in low
// and high arrays (i.e. when the subarray spans over the midpoint)
int maxMiddleSum(int theArray[], int low, int middle, int high)
{
    int sum = 0;
    int leftSum = -1;
    //loop through left side of theArray (low values)
    for (int i = middle; i >= low; i--)
    {
        sum = sum + theArray[i];
        //update value of sum of left side of array if it holds
        //the highest sum found so far
        if (sum > leftSum)
          leftSum = sum;
    }

    // Include elements on right of mid
    sum = 0;
    int rightSum = -1;
    //loop through the right side of theArray (high values)
    for (int i = middle+1; i <= high; i++)
    {
        sum = sum + theArray[i];
        //update value of sum of right side of array if it holds
        //the highest sum found so far
        if (sum > rightSum)
          rightSum = sum;
    }

    // Return sum of numbers left and right of the middle
    return leftSum + rightSum;
}

// Recursive function - calls itself on left, center, and middle of theArray
// Recursion ends when there is only 1 element left in theArray
int maxSubArraySum(int theArray[], int low, int high)
{
   // Base Case - only 1 element left in array
   if (low == high)
     return theArray[low];

   // Compute middle point of array, truncating division results
   int middle = (low + high)/2;

   //returns the maximum of 3 dunction calls
   //recursive calls: calls maxSubArray on theArray 2 times.
   //call 1: spans theArray low (element 0) to middle point
   //call 2: spans theArray middle point +1 to high (last element)
   //call 3: calls maxMiddleSum to check for maxSum for an array that spans the middle point
   return max(maxSubArraySum(theArray, low, middle),
              maxSubArraySum(theArray, middle+1, high),
              maxMiddleSum(theArray, low, middle, high));
}

//main function to demonstrate the functionality of maxSubarray

int main()
{
   //the contiguous subarray with the largest sum is 4, -1, 2, 1, with sum 6.
   //see     https://en.wikipedia.org/wiki/Maximum_subarray_problem
   //for answer verification
   int theArray[] = {-2,1,-3,4,-1,2,1,-5,4};
   int n = sizeof(theArray)/sizeof(theArray[0]);
   int maxSum = maxSubArraySum(theArray, 0, n-1);
   printf("Maximum sum of continuous array is %d\n", maxSum);
   return 0;
}