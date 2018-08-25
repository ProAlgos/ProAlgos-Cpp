/*
	Polynomial multiplication using linked list
	--------------
	Given two polynomials represented by two linked list, write a function
	that multiplies given two polynomials. 
	
	Time complexity
	---------------
	O(mn), where m and n is size of first and second polynomial respectively
	
	Space complexity
	----------------
	O(n + m)
*/

#include <iostream>

using namespace std;

class node;
class linkedList;

class node {
	friend class linkedList;
private:
	node *next;
public:
	int coefficient, exponent;
};

class linkedList {
private:
	node *first, *last;
public:
	linkedList() {
		first = NULL;
	}
	linkedList multSentence(linkedList b);
	bool deleteNode(node *selectedNode, int num);
	bool addNode(int status, node *selectedNode, node *position, int num);
	void display();
	void setLast(node *d) {
		last = d;
	}
	void setFirst(node *d) {
		first = d;
	}
};

void linkedList::display() {
	node *ptr = first;
	bool firstNum = true;
	while (ptr != last) {
		if (firstNum == false) {
			if (ptr->coefficient >= 0)
				cout << "+";
		}
		else {
			firstNum = false;
		}
		if (ptr->coefficient == 1)
			if (ptr->exponent == 0)
				cout << "1";
			else
				cout << "x^" << ptr->exponent;
		else if (ptr->coefficient == 0)
			cout << "0";
		else if (ptr->exponent == 1)
			if (ptr->coefficient == 1)
				cout << "x";
			else
				cout << ptr->coefficient << "x";
		else if (ptr->exponent == 0)
			cout << ptr->coefficient;
		else
			cout << ptr->coefficient << "x^" << ptr->exponent;
		ptr = ptr->next;
	}
}

bool linkedList::deleteNode(node *selectedNode, int num) {
	//It can work in two case:
	//1:with the number of sentence in the list AND 2:with the node
	if (num == -1) {
		node *p = selectedNode;
		selectedNode = selectedNode->next;
		delete p;
		return true;
	}
	else {
		node *ptr = first, *ptemp;
		int i = 1;
		while (ptr != last) {
			if (i == num) {
				//if your node is first and last
				if (num == 1) {
					first = ptr->next;
					delete ptr;
					return true;
					break;
				}
				else if (last == ptr) {
					last = ptemp->next;
				}
				//
				ptemp->next = ptr->next;
				delete ptr;
				return true;
				break;
			}
			i++;
			ptemp = ptr;
			ptr = ptr->next;
		}
		return false;
	}
}

bool linkedList::addNode(int status, node *selectedNode, node *nextPosition, int num) {
	if (status == 1) {
		//when this item is first one
		selectedNode->next = NULL;
		first = selectedNode;
		first->next = last;
		return true;
	}
	else if (status == 2) {
		//search your nextPosition node and set your new node after it
		//work with with the number of sentence in the list
		node *ptr = first, *ptemp;
		int i = 1;
		while (ptr != last) {
			if (i == num) {
				selectedNode->next = ptr->next;
				ptr->next = selectedNode;
				//if your node is last
				if (last == ptr) {
					last = ptemp->next;
				}
				return true;
				break;
			}
			i++;
			ptemp = ptr;
			ptr = ptr->next;
		}
		return false;
	}
	else if (status == 3) {
		//for making sentence after last pointer
		//Informations saved in "node *selectedNode"
		node *temp;
		temp = new node;
		temp->exponent = selectedNode->exponent;
		temp->coefficient = selectedNode->coefficient;
		temp->next = NULL;
		last->next = temp;
		last = temp;
		return true;
	}
	else {
		//in your position after nextPosition node
		selectedNode->next = nextPosition->next;
		nextPosition->next = selectedNode;
		return true;
	}
	return false;
}

linkedList linkedList::multSentence(linkedList b) {
	linkedList RLisnkedList;
	node *result, *rTemp, *BLast;
	int Z1 = 0, Z2 = 0, T1 = 0, T2 = 0;
	bool checkFirst = false, checkLast = false, checkout = false;
	for (node *i = first; i != last; i = i->next) {
		Z1 = i->coefficient;
		T1 = i->exponent;
		for (node *j = b.first; j != b.last; j = j->next) {
			Z2 = j->coefficient;
			T2 = j->exponent;
			//Mult function
			result = new node;
			if (checkFirst == false) {
				result->exponent = T1 + T2;
				result->coefficient = Z1*Z2;
				RLisnkedList.setFirst(result);
				checkFirst = true;
			}
			else {
				result->exponent = T1 + T2;
				result->coefficient = Z1*Z2;
				checkLast = true;
			}
			//Search in RLisnkedList for mach sentences
			bool checkFind = false;
			if (checkLast != false) {
				for (node *k = RLisnkedList.first; k != RLisnkedList.last; k = k->next) {
					if (k->exponent == result->exponent) {
						k->coefficient += result->coefficient;
						checkFind = true;
					}
				}
			}
			//If you can't find it
			if (checkFind == false || checkout == true) {
				if (checkLast != false) {
					RLisnkedList.setLast(result);
					RLisnkedList.addNode(4, result, rTemp, 0);
					rTemp = result;
					checkout = false;
				}
				else {
					//First step running:
					RLisnkedList.setLast(result);
					RLisnkedList.addNode(1, result, result, 0);
					rTemp = result;
					checkout = true;
				}
			}
		}
	}
	result = new node;
	result->exponent = 0;
	result->coefficient = 0;
	RLisnkedList.setLast(result);
	RLisnkedList.addNode(4, result, rTemp, 0);
	return RLisnkedList;
}

int main() {
	linkedList list1, list2;

	int sumOfPolys = 0;
	node *newNode, *temp;

	cin >> sumOfPolys;
	temp = new node;
	cin >> temp->coefficient >> temp->exponent;
	list1.addNode(4, temp, temp, 0);		//The secend "temp" in this function is not important
	list1.setFirst(temp);
	for (int i = 1; i<sumOfPolys + 1; i++) {
		newNode = new node;
		cin >> newNode->coefficient >> newNode->exponent;
		list1.addNode(4, newNode, temp, 0);
		temp = newNode;
	}
	list1.setLast(temp);
	sumOfPolys = 0;

	cin >> sumOfPolys;
	cin >> temp->coefficient >> temp->exponent;
	list2.addNode(4, temp, temp, 0);		//The secend NewNode in this function is not important
	list2.setFirst(temp);
	for (int i = 1; i<sumOfPolys + 1; i++) {
		newNode = new node;
		cin >> newNode->coefficient >> newNode->exponent;
		list2.addNode(4, newNode, temp, 0);
		temp = newNode;
	}
	list2.setLast(temp);

	list1.display();
	cout << "\n*\n";
	list2.display();
	cout << "\n=\n";

	list1.multSentence(list2).display();
	return 0;
}