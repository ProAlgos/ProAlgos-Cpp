/*
<Floyd Warshall Algorithm>
-------------------
<An algorithm to solve All Pairs Shortest Path Problem using graphs>

Time complexity
---------------
O(n^3), where <n is equal to number vertices of the graph>

Space complexity
----------------
O(n^3), where <n is equal to number vertices of the graph>
*/
#include <iostream>
using namespace std;

void floyds(int b[][50],int size)
{
    int i, j, k;
    for (k = 0; k < size; k++)
    {
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if ((b[i][k] * b[k][j] != 0) && (i != j))
                {
                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
                    {
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < size; i++)
    {
        cout<<"\nMinimum Cost With Respect to Node:"<<i<<endl;
        for (j = 0; j < size; j++)
        {
            cout<<b[i][j]<<"\t";
        }
 
    }
    cout<<endl;
}
int main()
{
    int b[50][50];
    int size;
    cout<<"\nEnter size of matrix :";
    cin>>size;

    cout<<"\nEnter values of adjacency matrix\n\n";
    for (int i = 0; i < size; i++)
    {
        cout<<"\nEnter values for "<<(i+1)<<" row"<<endl;
        for (int j = 0; j < size; j++)
        {
            cin>>b[i][j];
        }
    }
    floyds(b,size);
    
}