
/*
  Longest Increasing Subsequence
  ------------------------------
  Given an unsorted array of integers, return the longest increasing subsequence length
  Time complexity
  --------------
  O(N^2), where N is size of array
  Space complexity
  ---------------
  O(N), where N is size of array
  Author
  ------
  Shikhar Jaiswal(@shikherjaiswal)
*/
#ifndef longest_increasing_subsequence_hpp
#define longest_increasing_subsequence_hpp
#include <vector>
int lis( std :: vector< int > arr, int n ) {
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );
    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++ ) {
        lis[i] = 1;
    }
    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ ){
        for (j = 0; j < i; j++ )  {
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ ) {
        if (max < lis[i]) {
            max = lis[i];
        }
    }
    /* Free memory to avoid memory leak */
    free(lis);
    return max;
}
#endif
