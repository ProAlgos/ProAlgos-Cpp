/*
    8Puzzle problem
    ----------------
    Given a 3×3 board with 8 tiles (every tile has one number from 1 to 8) and one empty space. The objective is to place the numbers on 
    tiles  in order using the empty space. We can slide four adjacent (left, right, above and below) tiles into the empty space.
	
	A* Algorithm :
		Time complexity
    		---------------
    		O(4 to the power d ), where d is the depth of the shallowest goal node and 4 is branching factor here
    		Space complexity
    		----------------
    		O(4 to the power d ), where d is the depth of the shallowest goal node and 4 is branching factor here (in worst case)
*/


#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;

int n;
int goal[4][4],board[4][4];
int zx,zy;
int gx, gy;
struct node {
	struct node* par;  //parent pointer to trace the path from start state to goal state
	int fn,hn,gn;
	int arr[4][4];
	int zx, zy;
}*head;

struct node *initialize(struct node*par){       //initialize as parent node
	struct node* p = (struct node*) malloc(sizeof(struct node));
	int i,j;
	if(par == NULL){
		for(i =0; i<n ; i++){
			for(j =0; j<n;j++){
				p->arr[i][j] = board[i][j];
			}
		}
		p->zx = zx;
		p->zy = zy;
		p->par = par;
		p->fn = p->hn = p->gn =0;
		return p;
	}
	p->zx = par->zx;
	p->zy = par->zy;
	for(i =0; i<n ; i++){
		for(j =0; j<n;j++){
			p->arr[i][j] = par->arr[i][j];
		}
	}
	p->par = par;
	p->fn = p->gn = p->hn = 0;
	return p;
}

vector <struct node*> closedlist;
vector<struct node* > openlist;
vector<struct node* > generated;

struct node* move_up(struct node *p,int a,int b){
	int t = p->arr[a-1][b];
	p->arr[a-1][b] = p->arr[a][b];
	p->arr[a][b] = t;
	p->zx = a-1;
	p->zy = b;
	return p;	
}
struct node* move_left(struct node *p,int a,int b){
	int t = p->arr[a][b-1];
	p->arr[a][b-1] = p->arr[a][b];
	p->arr[a][b] = t;
	p->zx = a;
	p->zy = b-1;
	return p;	
}
struct node* move_right(struct node *p,int a,int b){
	int t = p->arr[a][b+1];
	p->arr[a][b+1] = p->arr[a][b];
	p->arr[a][b] = t;
	p->zx = a;
	p->zy = b+1;
	return p;	
}
struct node* move_down(struct node *p,int a,int b){
	int t = p->arr[a+1][b];
	p->arr[a+1][b] = p->arr[a][b];
	p->arr[a][b] = t;
	p->zx = a+1;
	p->zy = b;
	return p;	
}
bool check_goal(struct node* p){
	int i,j;
	if(p != NULL ){
		for (i= 0; i<n; i++){
			for(j=0; j<n; j++){
				if(goal[i][j] != p->arr[i][j])
					return false;
			}
		}
		return true;
	}
	return false;
}
void printans(struct node *p){
    	int c= closedlist.size();
	int d = generated.size();
    	cout <<"no of nodes explored are " << c << " and no of nodes generated are " << d <<endl;
	int j,k;
    	/*for(int i =0;i<c; i++){
		for(j=0; j<n; j++){
			for (k= 0; k<n; k++){
				cout << closedlist[i]->arr[j][k] <<" ";
			}
			cout <<endl;
		}
		cout <<closedlist[i]->hn <<endl;
    	}*/
    	int len;
    	stack<struct node *> ss;
    	while(p && p->par){
         	ss.push(p);
         	p = p->par;
    	}
    	ss.push(p);
    	len = ss.size()-1;
	cout <<"sol at depth "<<len<<endl;
    	while(!ss.empty()){
        	struct node * w = ss.top();
        	ss.pop();
		for(j=0; j<n; j++){
			for (k= 0; k<n; k++){
				cout << w->arr[j][k] <<" ";
			}
			cout <<endl;
		}
		cout <<endl;

    	}
   // cout <<"solution found at depth (from root to goal )  "<< len <<" and total iterations are "<< c <<endl;
}


bool visited(struct node* p) {
	int i, c = generated.size();
	if(p != NULL ){
		for(i =0; i<c; i++){
			int j,k;
			int cnt = 0;
			for(j=0; j<n; j++){
				for (k= 0; k<n; k++){
					if(generated[i]->arr[j][k] == p->arr[j][k])
						cnt++;
				}
			}
			if(cnt == n*n) return true;
		}
	}
	return false;
}

bool cmp(const struct node* a, const struct node* b) 
{   
	return a->fn < b->fn;
} 
//No of misplaced tiles 
 /*
int hn_func(struct node* p){
	if(p ==NULL)return 0;
	int i,j,k,l;
	for(i =0; i<n ;i++){
		for(j=0; j<n; j++){		
			if(p->arr[i][j] != goal[i][j] && p->arr[i][j] != 0){
				(p->hn)++;
			}
		}
	}
	return p->hn;
}
 */
//Manhattan distance
int hn_func(struct node* p){
	int i,j,k,l;
	for(i =0; i<n ;i++){
		for(j=0; j<n; j++){		
			for(k=0; k<n; k++){
				for(l =0; l<n; l++){
					if(p->arr[i][j] == goal[k][l] && p->arr[i][j] != 0){
						p->hn += abs(i-k )+ abs(j-l);
					}
				}
			}
		}
	}
	return p->hn;
}
int gn_func(struct node* p){
	int c=0;
    	while(p ){
         	p = p->par;
		c++;
    	}
    	return c;
}
int fn_func(struct node* p){
	p->hn = hn_func(p);
	p->gn = gn_func(p);
	p->fn = p->hn +p->gn;
	return p->fn;
}


int astar_npuzzle(){
	closedlist.clear();
	openlist.clear();
	generated.clear();
	cout <<"astar\n";
	head = initialize(NULL);
	head->fn = fn_func(head);
	openlist.push_back(head);
	generated.push_back(head);
	while(! openlist.empty()){
		sort(openlist.begin(), openlist.end(), cmp);
		struct node * p = openlist.front();
		openlist.erase(openlist.begin());
		int a =p->zx;
		int b = p->zy;
		
		//cout <<a << " ," <<b <<endl;
		closedlist.push_back(p);
		if(check_goal(p)){
			//cout<< "found ans\n";
			printans(p);
			return 1;
		}
		if(closedlist.size()> 4000) { cout << "not found even after 4000 nodes explored\n"; return 0;}
		if(a-1 >=0  ){
			struct node * q = initialize(p);
			q = move_up(q, a,b);
			q->fn = fn_func(q);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if( b-1 >=0  ){
			struct node * q = initialize(p);
			q = move_left(q, a,b);
			q->fn = fn_func(q);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if( b+1 <n ){
			struct node * q = initialize(p);
			q = move_right(q, a,b);
			q->fn = fn_func(q);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if(a+1 <n  ){
			struct node * q = initialize(p);
			q = move_down(q, a,b);
			q->fn = fn_func(q);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
	}

	return 0;
}
int main(){
	n=3;
	int i,j;
	for(i =0;i<n; i++){
		for(j=0; j<n; j++){
			cin >> board[i][j];
			if(board[i][j] == 0){
				zx = i;
				zy = j;
			}
		}
	}
	for(i =0;i<n; i++){
		for(j=0; j<n; j++){
			cin >> goal[i][j];
			if(goal[i][j] == 0){
				gx = i;
				gy = j;
			}
		}
	}
	//printmat(board->arr);
	//printmat(finall->arr);
	int k= astar_npuzzle();

	return 0;
}

