#include<bits/stdc++.h>
using namespace std;
int d=8;
bool canPlace(int board[][8],int n,int curRow,int curCol){
   if(board[curRow][curCol]==0 && curRow>=0 && curRow<n && curCol>=0 && curCol<n)
   	return true;
   else return false;
}
bool solve(int board[][8],int n,int move_no,int curRow,int curCol){
	if(move_no==64){
		return true;
	}
	int rowDir[]={+2,+1,-1,-2,-2,-1,+1,+2};
	int colDir[]={+1,+2,+2,+1,-1,-2,-2,-1};
	for(int curDir=0;curDir<8;++curDir){
		int nextRow=curRow+rowDir[curDir];
		int nextCol=curCol+colDir[curDir];
		if(canPlace(board,n,nextRow,nextCol)){
			board[nextRow][nextCol]=move_no+1;
			bool canSuccess=solve(board,n,move_no+1,nextRow,nextCol);
			if(canSuccess) return true;
			else board[nextRow][nextCol]=0;
		}
	}
	return false;
}
printBoard(int board[][8],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<"\t";
		}
		cout<<endl;
	}
}
int main(){
	int board[8][8]={0};
    board[0][0]=1;
    bool ans=solve(board,8,1,0,0);
    if(ans){
    	printBoard(board,8);
    }
    else
    	cout<<"Can not be done"<<endl;
	return 0;
}