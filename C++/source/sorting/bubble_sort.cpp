#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
void bucketSort(float arr[], int n)
{
    vector<float> b[n];
    
    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i]; 
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
	 int n;
	 cin >> n;

    float arr[n];
  
    bucketSort(arr, n);
 
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}