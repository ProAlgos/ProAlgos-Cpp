/*
    Boundary Traversal of a Binary Tree
    --------------
    Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root.

    Time complexity
    ---------------
    O(n) where n is the number of nodes in binary tree.

    Space complexity
    ----------------
    O(1).
*/

#include <stdio.h>
#include <stdlib.h>

struct node {

	int data;
	struct node *left, *right;
};

struct node* newNode(int data) {
	struct node* temp = (struct node *) malloc( sizeof(struct node) );
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;

}

void printLeftBoundary(struct node* root) {

	if (root) {

		if (root->left) {
			printf("%d ", root->data);
			printLeftBoundary(root->left);
		}
		else if (root->right) {
			printf("%d ", root->data);
			printLeftBoundary(root->right);
		}
	}
}

void printRightBoundary(struct node* root) {

	if (root) {

		if (root->right) {
			printRightBoundary(root->right);
			printf("%d ", root->data);
		}
		else if (root->left) {
			printRightBoundary(root->left);
			printf("%d ", root->data);       
		}
	}
}

void printLeaves(struct node* root) {

	if ( root )
	{
		printLeaves(root->left);

		if ( !(root->left)  &&  !(root->right) )
			printf("%d ", root->data);

		printLeaves(root->right);
	}
}

void printBoundary(struct node* root) {

	if ( root ) {

		printf("%d ", root->data);
		printLeftBoundary(root->left);

		printLeaves(root->left);
		printLeaves(root->right);

		printRightBoundary(root->right);
	}

}

int main() {

	struct node * root        = newNode(20);
	root->left                = newNode(8);
	root->left->left          = newNode(4);
	root->left->right         = newNode(12);
	root->left->right->left   = newNode(10);
	root->left->right->right  = newNode(14);
	root->right               = newNode(22);
	root->right->right        = newNode(25);
	printBoundary(root);
}