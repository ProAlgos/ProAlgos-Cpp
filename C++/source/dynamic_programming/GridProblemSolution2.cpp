#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cout << "Enter the cordinate of top right corner of the Grid : ";
    cin >> m >> n;
    vector <vector <int>> board;
    for(int i = 0; i <= m ; i++)
    {
        vector <int> temp;
        for(int j = 0; j <= n; j++)
            temp.push_back(-1);
        board.push_back(temp);
    }
    cout << "Enter the number of cordinates through which user can't pass : ";
    int noOfConflict;
    cin >> noOfConflict;
    cout << "Enter the cordinates of through which user can't pass " << endl;
    vector <vector<int>> conflicts;
    for(int i = 0; i < noOfConflict ; i++)
    {
        int tempX,tempY;
        cin >> tempX >> tempY;
        board[tempX][tempY] = 0;
    }
    for(int i = 0; i <=m; i++)
    {
        if(board[i][0] != 0)
        {
            board[i][0] = 1;
        }
    }
    for(int i = 0; i <= n; i++)
    {
        if(board[0][i] != 0)
            board[0][i] = 1;
    }
    for(int i = 1; i <=m; i++)
    {
        for(int j = 1; j <=n ; j++)
        {
            if(board[i][j] != 0)
            {
                board[i][j] = board[i-1][j] + board[i][j-1];
            }
        }
    }
    cout << " The number of possible paths are : " << board[m][n] << endl;


}
