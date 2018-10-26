#include<bits/stdc++.h>
using namespace std;
int computePath(vector <vector<int>> &board, const vector<vector <int>> &conflicts,int i,int j)
{
    if(i == board.size()-1 && j == board[0].size()-1)
    {
        board[i][j] = 1;
        return 1;
    }
    if(board[i][j] != -1)
        return board[i][j];
    if(i== board.size()-1)
    {
        if(conflicts[i][j+1] != -1)
        {
            board[i][j] = computePath(board,conflicts,i,j+1);
            return board[i][j];
        }
        else
        {
            board[i][j] = 0;
            return 0;
        }
    }
    if(j == board[0].size() -1)
    {
        if(conflicts[i+1][j] != -1)
        {
            board[i][j] = computePath(board,conflicts,i+1,j);
            return board[i][j];
        }
        else
        {
            board[i][j] = 0;
            return 0;
        }
    }
    if(conflicts[i+1][j] != -1 && conflicts[i][j+1] != -1)
    {
        board[i][j] = computePath(board,conflicts,i+1,j) + computePath(board,conflicts,i,j+1);
        return board[i][j];
    }
    if(conflicts[i+1][j] != -1)
    {
        board[i][j] = computePath(board,conflicts,i+1,j);
        return board[i][j];
    }
    else
    {
        board[i][j] = computePath(board,conflicts,i,j+1);
        return board[i][j];
    }

}


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
    for(int i = 0; i <= m ; i++)
    {
        vector <int> temp;
        for(int j = 0; j <= n; j++)
            temp.push_back(0);
        conflicts.push_back(temp);
    }
    for(int i = 0; i < noOfConflict ; i++)
    {
        int tempX,tempY;
        cin >> tempX >> tempY;
        conflicts[tempX][tempY] = -1;
    }
    cout << board.size() << board[0].size() << endl;
    int i =  computePath(board,conflicts,0,0);
    cout << " The number of possible paths are : " << board[0][0] << endl;


}
