/*
    Bucket sort
    -----------
    A sorting algorithm that works by distributing the elements of an array into a number of buckets.
    Each bucket is then sorted individually, either using a different sorting algorithm, or by recursively
    applying the bucket sorting algorithm.
    Time complexity
    ---------------
    O(N^2), where N is the number of elements.
    Space complexity
    ----------------
    O(N), where N is the number of elements.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
void bucketSort(float arr[], int n)
{
    vector<float> b[n];
    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i]; // Index in bucket
       b[bi].push_back(arr[i]);
    }
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];
}
 
int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);
 
    cout << "Sorted array is \n";
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}
