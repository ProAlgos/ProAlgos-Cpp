//============================================================================
// Name        : ThreadedBinaryTree.cpp
// Author      : Snehal Khandve 
//============================================================================


/*
	Inorder traversal of a Binary tree can either be done using recursion or with the use of a auxiliary stack. 
	The idea of threaded binary trees is to make inorder traversal faster and do it without stack and without recursion. 
	A binary tree is made threaded by making all right child pointers that would normally be NULL point to the inorder successor of the node (if it exists).

	There are two types of threaded binary trees.
	Single Threaded: 
					Where a NULL right pointers is made to point to the inorder successor (if successor exists)

	Double Threaded: 
					Where both left and right NULL pointers are made to point to inorder predecessor and inorder successor respectively.

	Following code is an implemementation of Double threaded binary tree
*/


#ifndef THREADED_BINARY_TREE_HPP
#define THREADED_BINARY_TREE_HPP


#include <iostream>
#include <vector>

using namespace std;

class Threaded_Binary_Tree;

class node
{
	node *left_link , *right_link;
	int data;
	bool left_bit , right_bit;

public:
	node();
	node(int node_data);
	friend class Threaded_Binary_Tree;
};

node :: node()
{
	left_link = NULL;
	right_link = NULL;
	left_bit = right_bit = 0;
}

node :: node(int node_data)
{
	left_link = NULL;
	right_link = NULL;
	right_bit = left_bit = 0;
	data = node_data;
}

class Threaded_Binary_Tree
{
	node* root;				 //acts as a dummy node

public:

	Threaded_Binary_Tree();
	void create(vector<int>& values);
	void insert(int data);
	node* inorder_check(node*);
	vector<int> inorder_traversal();
	node* preorder_check(node*);
	vector<int> preorder_traversal();
};

Threaded_Binary_Tree :: Threaded_Binary_Tree()
{
	root = new node(9999);
	root->left_link = root;
	root->right_bit = 1;
	root->left_bit = 0;
	root->right_link = root;
}

vector<int> Threaded_Binary_Tree :: preorder_traversal()
{

	/*
		Preorder traversal is achieved by following traversal rule:
		Root node value , Left node value , Right node value

	*/

	/*
		This algorithm works in :
		Time complexity :
		O(log(n))

		
		Space complexity :
		O(1)   
		
		Unlike preorder_traversal() for simple binary trees which have
		Space complexity : O(n) 
		And this is the advantage of using Threaded Binary Tree .

	*/

	vector <int> preorder_values;
	preorder_values.clear();

	node *c = root->left_link;
	while(c != root)
	{
		preorder_values.push_back(c->data);
		c = preorder_check(c);
	}

	return preorder_values;
}

node* Threaded_Binary_Tree :: preorder_check(node *c)
{

	/*
		Checking if the pointers in the node are threads or links
	
	*/

	if(c->left_bit == 1)
	{
		return c->left_link;
	}
	while(c->right_bit == 0)
	{
		c=c->right_link;
	}
	return c->right_link;
}


vector<int> Threaded_Binary_Tree :: inorder_traversal()
{

	/*
		Inorder traversal is achieved by following traversal rule:
		 Left node value, Root node value , Right node value

	*/

	/*
		This algorithm works in :
		Time complexity :
		O(log(n))

		
		Space complexity :
		O(1)   
		
		Unlike preorder_traversal() for simple binary trees which have
		Space complexity : O(n) 
		And this is the advantage of using Threaded Binary Tree .

	*/

	vector <int> inorder_values;
	inorder_values.clear();

	node *c = root->left_link;
	while(c->left_bit == 1)
		c = c->left_link ;
	while(c!=root)
	{
		inorder_values.push_back(c->data);
		c = inorder_check(c);
	}

	return inorder_values;
}

node* Threaded_Binary_Tree :: inorder_check(node *c)
{

	/*
		Checking if the pointers in the node are threads or links
	
	*/

	if(c->right_bit == 0)
		return c->right_link;
	else
		c=c->right_link;
	while(c->left_bit == 1)
	{
		c = c->left_link;
	}
	return c;
}


void Threaded_Binary_Tree :: create(vector<int>& values)
{

	/*
		This algorithm works in :
		Time complexity :
		O(log(n))

		
		Space complexity :
		O(n)   

	*/

	if((root->left_link == root) && (root->right_link == root))
	{
	for(int i=0;i<values.size();i++)
	{
		int node_data;
		node_data = values[i];
		this->insert(node_data);
	}
	}
	else
	{
		cout<<"\nTree is Already created.\n";
	}
}

void Threaded_Binary_Tree :: insert(int data)
{


	/*
		This algorithm works in :
		Time complexity :
		O(log(n))

		
		Space complexity :
		O(n)   

		

	*/


	/*
		
		While insertion the approach is just similar to a binary search tree .

	*/

	if((root->left_link == root) && (root->right_link == root)) 		//no node in tree
	{
		node *p = new node(data);
		p->left_link = root->left_link;
		p->left_bit = root->left_bit; //0
		p->right_bit = 0;
		p->right_link = root->right_link;
		root->left_link = p;
		root->left_bit = 1;
		return;
	}
	node* current = new node;
	current = root->left_link;
	while(1)
	{

		if(current->data < data)   			//insert right
		{
			node* p = new node(data);
			if(current->right_bit == 0)
			{
				p->right_link = current->right_link;
				p->right_bit = current->right_bit;
				p->left_bit = 0;
				p->left_link = current;
				current->right_bit = 1;
				current->right_link = p;
				return;
			}
			else
				current = current->right_link;
		}
		if(current->data > data) 				//insert left
		{
			node* p = new node(data);
			if(current->left_bit == 0)
			{
				p->left_link = current->left_link;
				p->left_bit = current->left_bit;
				p->right_bit = 0;
				p->right_link = current; 		//successor
				current->left_bit = 1;
				current->left_link = p;
				return;
			}
			else
				current = current->left_link;
		}
	}

}

#endif // THREADED_BINARY_TREE_HPP
