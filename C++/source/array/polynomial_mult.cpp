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
class linkedlist;
class node {
	friend class linkedlist;
private:
	node *next;
public:
	int coefficient, exponent;
};
class linkedlist {
private:
	node *first, *last;
public:
	linkedlist() {
		first = NULL;
	}
	linkedlist mult_sentence(linkedlist input);
	bool delete_node(node *selected_node, int num);
	bool add_node(int status, node *selected_node, node *next_position, int num);
	void display();
	void set_last(node *input_node) {
		last = input_node;
	}
	void set_first(node *input_node) {
		first = input_node;
	}
};
void linkedlist::display() {
	node *ptr = first;
	bool first_num = true;
	while (ptr != last) {
		if (first_num == false) {
			if (ptr->coefficient >= 0)
				cout << "+";
		} else {
			first_num = false;
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
bool linkedlist::delete_node(node *selected_node, int num) {
	//It can work in two case:
	//1:with the number of sentence in the list AND 2:with the node
	if (num == -1) {
		node *p = selected_node;
		selected_node = selected_node->next;
		delete p;
		return true;
	} else {
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
				} else if (last == ptr) {
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
bool linkedlist::add_node(int status, node *selected_node, node *next_position, int num) {
	if (status == 1) {
		//when this item is first one
		selected_node->next = NULL;
		first = selected_node;
		first->next = last;
		return true;
	} else if (status == 2) {
		//search your nextPosition node and set your new node after it
		//work with with the number of sentence in the list
		node *ptr = first, *ptemp;
		int i = 1;
		while (ptr != last) {
			if (i == num) {
				selected_node->next = ptr->next;
				ptr->next = selected_node;
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
	} else if (status == 3) {
		//for making sentence after last pointer
		//Informations saved in "node *selectedNode"
		node *temp;
		temp = new node;
		temp->exponent = selected_node->exponent;
		temp->coefficient = selected_node->coefficient;
		temp->next = NULL;
		last->next = temp;
		last = temp;
		return true;
	}
	else {
		//in your position after nextPosition node
		selected_node->next = next_position->next;
		next_position->next = selected_node;
		return true;
	}
	return false;
}
linkedlist linkedlist::mult_sentence(linkedlist input) {
	linkedlist right_linkedlist;
	node *result, *right_temp;
	int fz_handler = 0, sz_handler = 0, ft_handler = 0, st_handler = 0;
	bool check_first = false, check_last = false, checkout = false;
	for (node *i = first; i != last; i = i->next) {
		fz_handler = i->coefficient;
		ft_handler = i->exponent;
		for (node *j = input.first; j != input.last; j = j->next) {
			sz_handler = j->coefficient;
			st_handler = j->exponent;
			//Mult function
			result = new node;
			if (check_first == false) {
				result->exponent = ft_handler + st_handler;
				result->coefficient = fz_handler*sz_handler;
				right_linkedlist.set_first(result);
				check_first = true;
			}
			else {
				result->exponent = ft_handler + st_handler;
				result->coefficient = fz_handler*sz_handler;
				check_last = true;
			}
			//Search in RLisnkedList for mach sentences
			bool checkFind = false;
			if (check_last != false) {
				for (node *k = right_linkedlist.first; k != right_linkedlist.last; k = k->next) {
					if (k->exponent == result->exponent) {
						k->coefficient += result->coefficient;
						checkFind = true;
					}
				}
			}
			//If you can't find it
			if (checkFind == false || checkout == true) {
				if (check_last != false) {
					right_linkedlist.set_last(result);
					right_linkedlist.add_node(4, result, right_temp, 0);
					right_temp = result;
					checkout = false;
				}
				else {
					//First step running:
					right_linkedlist.set_last(result);
					right_linkedlist.add_node(1, result, result, 0);
					right_temp = result;
					checkout = true;
				}
			}
		}
	}
	result = new node;
	result->exponent = 0;
	result->coefficient = 0;
	right_linkedlist.set_last(result);
	right_linkedlist.add_node(4, result, right_temp, 0);
	return right_linkedlist;
}
int main() {
	linkedlist first_list, second_list;
	int sum_of_polys = 0;
	node *new_node, *temp;
	cin >> sum_of_polys;
	temp = new node;
	cin >> temp->coefficient >> temp->exponent;
	first_list.add_node(4, temp, temp, 0);		//The secend "temp" in this function is not important
	first_list.set_first(temp);
	for (int i = 1; i<sum_of_polys + 1; i++) {
		new_node = new node;
		cin >> new_node->coefficient >> new_node->exponent;
		first_list.add_node(4, new_node, temp, 0);
		temp = new_node;
	}
	first_list.set_last(temp);
	sum_of_polys = 0;
	cin >> sum_of_polys;
	cin >> temp->coefficient >> temp->exponent;
	second_list.add_node(4, temp, temp, 0);		//The secend NewNode in this function is not important
	second_list.set_first(temp);
	for (int i = 1; i<sum_of_polys + 1; i++) {
		new_node = new node;
		cin >> new_node->coefficient >> new_node->exponent;
		second_list.add_node(4, new_node, temp, 0);
		temp = new_node;
	}
	second_list.set_last(temp);
	first_list.display();
	cout << "\n*\n";
	second_list.display();
	cout << "\n=\n";
	first_list.mult_sentence(second_list).display();
	return 0;
}