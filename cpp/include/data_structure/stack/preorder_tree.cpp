#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int info;
		node* left= NULL;
		node* right= NULL;
};
node* new_node(int item){
	node* new_n;
	new_n= new node;
	new_n->info= item;
	new_n->left= NULL;
	new_n->right= NULL;
	return new_n;
}
void pre_traverse(node* root){
	if(root==NULL){
		cout<<"empty tree, underflow condition!!"<<endl;
		return;
	}
	stack<node*> mystack;
	mystack.push(root);
	
	while(mystack.empty()==false){
		node * node= mystack.top();
		cout<<" "<< node->info<<" ";
		mystack.pop();
		if(node->right!=NULL)
		mystack.push(node->right);
		if(node->left!=NULL)
		mystack.push(node->left);
	}
}
int main(){
	// check traversal
	return 0;
}