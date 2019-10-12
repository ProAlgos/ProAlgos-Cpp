/*
CIRCULAR LINKED LIST
---------------------
A linked list where all the nodes are arranged in a circular way.
*/

//program for insertion and traversal of a circular linked list

#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node* next;
};

node* head=NULL;

void push(int val){
	node* temp = new node();
	temp->data = val;
	node* ptr = head;
	//if linked list is null	
	if(head==NULL){
		temp->next=temp;
	}
	else{
		while(ptr->next!=head){
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->next=head;
	}
	head=temp;
}

void traverse(){
	cout<<head->data<<" ";
	node* temp = head->next;
	if(temp!=NULL){
		while(temp!=head){
			cout<<temp->data<<" ";
			temp=temp->next;
		}	
	}
}

int main(){
	push(23);
	push(12);
	push(19);	
	push(4);
	cout<<"The circular linked list is : "<<endl;
	traverse();
	
	return 0;
}
