/*
AVL (Adelson-Velskii and Landis) tree
---------------------------
AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights
of left and right subtrees cannot be more than one for all nodes. Most of the BST operations
(e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the
BST. The cost of these operations may become O(n) for a skewed Binary tree. If we make sure
that height of the tree remains O(Logn) after every insertion and deletion, then we can
guarantee an upper bound of O(Logn) for all these operations. The height of an AVL tree is
always O(Logn) where n is the number of nodes in the tree

Time complexity
---------------
O(logN), where N is the number of nodes.

Space complexity
----------------
O(N), where N is the number of nodes.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>

using namespace std;

class AVLTreeNode {
private:
public:
	int weight;			//weight of node
	int id;				//Unique ID of node
	int distance;		//Distance from root
	bool is_right;		//Is this object distance from right of its parent

	AVLTreeNode() {
		weight = 0;
		id = 0;
		distance = 0;
	}

	int id_char_num() {				//ReturnID Characters number
		char source_str[256];
		_itoa_s(id, source_str, 10);
		string target_str = source_str;
		return target_str.size();
	}
	void show_node() {				//Show the node with this syntax in four rectangle: [_ID_]
		switch (id_char_num()) {
		case 1:
			cout << "[_" << id << "__]";
			break;
		case 2:
			cout << "[_" << id << "_]";
			break;
		case 3:
			cout << "[" << id << "_]";
			break;
		default:
			cout << "[" << id << "]";
			break;
		}
	}
protected:
};

class AVLTree {
private:
	vector<AVLTreeNode> tree_nodes;		//Nodes Array
	stack<int> used_nodes;				//Way of going to insert a new node
	stack<bool> is_used_node_right;		//Help for Way of going to insert a new node in right or left
	int num_of_nodes;

	void weight_update(int i);		//Update new node weight
	void select_subtree(int index, vector<AVLTreeNode> *subtree, vector<int> *is_right, int status);
	void subtree_set(int set_node_index, int index, int is_right_index, vector<AVLTreeNode> *subtree, vector<int> *is_right, int status);
public:
	AVLTree() {
		num_of_nodes = 0;
	}

	bool insert(int entered_id);
	bool search(int entered_id);

	void right_right_rotation(int first_node, int second_node, int third_node);
	void display(bool vertical);
	void basic_display();
protected:
};

bool AVLTree::insert(int entered_id) {
	int root_distance = 0;
	AVLTreeNode new_node;
	new_node.weight = 0;
	new_node.id = entered_id;
	AVLTreeNode empty_node;
	empty_node.weight = 0;
	empty_node.id = -1;
	if (tree_nodes.size() == 0) {
		tree_nodes.push_back(new_node);
		tree_nodes.push_back(empty_node);
		tree_nodes.push_back(empty_node);

		num_of_nodes++;
		return true;
	}
	else {
		bool is_right, first = true;
		vector<AVLTreeNode>::iterator p = tree_nodes.begin();
		int check_id = (*p).id, local_id = -1;
		for (int i = 0; i != tree_nodes.size(); check_id = tree_nodes[i].id) {
			if (entered_id > check_id) {
				//Calculating weight and distance
				tree_nodes[i].weight = tree_nodes[i].weight + 1;	//Right++
				used_nodes.push(i);									//Save way in tree
				is_used_node_right.push(true);						//Save go right/left in tree
				root_distance++;									//Increase distance
				if (first) {
					is_right = true;
					first = false;
				}
				//

				local_id = tree_nodes[(i * 2) + 2].id;
				if (local_id == -1) {
					tree_nodes[(i * 2) + 2] = new_node;
					tree_nodes[(i * 2) + 2].distance = root_distance;
					tree_nodes[(i * 2) + 2].is_right = is_right;
					weight_update((i * 2) + 2);

					tree_nodes.push_back(empty_node);
					tree_nodes.push_back(empty_node);
					num_of_nodes++;
					return true;
				}
				else {
					int k = i;
					i = (i * 2) + 2;		//2i+1

					for (int j = 0; j < i - k; j++) {
						tree_nodes.push_back(empty_node);
					}
				}
			}
			else if (entered_id <= check_id) {
				//Calculating weight and distance
				tree_nodes[i].weight = tree_nodes[i].weight - 1;	//Right++
				used_nodes.push(i);						//Save way in tree
				is_used_node_right.push(false);			//Save go right/left in tree
				root_distance--;							//decrease distance
				if (first) {
					is_right = false;
					first = false;
				}
				//

				local_id = tree_nodes[(i * 2) + 1].id;
				if (local_id == -1) {
					tree_nodes[(i * 2) + 1] = new_node;
					tree_nodes[(i * 2) + 1].distance = root_distance;
					tree_nodes[(i * 2) + 1].is_right = is_right;
					weight_update((i * 2) + 1);

					tree_nodes.push_back(empty_node);
					tree_nodes.push_back(empty_node);
					num_of_nodes++;
					return true;
				}
				else {
					int k = i;
					i = (i * 2) + 1;		//2i

					for (int j = 0; j < i - k; j++) {
						tree_nodes.push_back(empty_node);
					}
				}
			}
		}
	}
	return false;
}

void AVLTree::weight_update(int index) {
	bool work = false;
	//Check "Is the newNode have a (next/previous) neighbor leaf?"
	//When "yes", we must redo the changes in the node's weight . . .
	if (index % 2 == 0) {
		if (tree_nodes[index - 1].id != -1) {
			work = true;
		}
	}
	else {
		if (tree_nodes[index + 1].id != -1) {
			work = true;
		}
	}
	if (work) {
		int step_index;
		bool right;

		used_nodes.pop();
		is_used_node_right.pop();
		while (!used_nodes.empty()) {
			step_index = used_nodes.top();
			right = is_used_node_right.top();

			if (right) {
				tree_nodes[step_index].weight = tree_nodes[step_index].weight - 1;
			}
			else {
				tree_nodes[step_index].weight = tree_nodes[step_index].weight + 1;
			}

			used_nodes.pop();
			is_used_node_right.pop();
		}
	}
	while (!used_nodes.empty()) {
		used_nodes.pop();
		is_used_node_right.pop();
	}
}

void AVLTree::select_subtree(int index, vector<AVLTreeNode> *subtree, vector<int> *is_right, int status) {
	//status=1 : Just get right subtree, status=2 : Just get left subtree, status=3 : both right and left subtree
	//index : is the node we need to get subtree from that
	if (tree_nodes[index].id != -1) {
		switch (status) {
		case 1:
			subtree->push_back(tree_nodes[index * 2 + 2]);	//Node one right subtree
			is_right->push_back(+1);

			//selectSubtree(index*2+2, subtree, 1);
			is_right->push_back(+2);
			select_subtree(index * 2 + 2, subtree, is_right, 3);
			tree_nodes[index * 2 + 2].id = -1;
			break;
		case 2:
			subtree->push_back(tree_nodes[index * 2 + 1]);	//Node one left subtree
			is_right->push_back(-1);

			//selectSubtree(index*2+1, subtree, 2);
			is_right->push_back(-2);
			select_subtree(index * 2 + 1, subtree, is_right, 3);
			tree_nodes[index * 2 + 1].id = -1;
			break;
		case 3:
			subtree->push_back(tree_nodes[index * 2 + 1]);	//Node one left subtree
			is_right->push_back(-1);
			subtree->push_back(tree_nodes[index * 2 + 2]);	//Node one right subtree
			is_right->push_back(+1);

			is_right->push_back(-2);
			select_subtree(index * 2 + 1, subtree, is_right, 3);
			is_right->push_back(+2);
			select_subtree(index * 2 + 2, subtree, is_right, 3);
			tree_nodes[index * 2 + 1].id = -1;
			tree_nodes[index * 2 + 2].id = -1;
			break;
		}
	}
}

void AVLTree::subtree_set(int set_node_index, int index, int is_right_index, vector<AVLTreeNode> *subtree, vector<int> *is_right, int status) {
	//status=1 : Just get right subtree, status=2 : Just get left subtree, status=3 : both right and left subtree
	if (tree_nodes[index].id != -1) {
		switch (status) {
		case 1:
			tree_nodes.insert(tree_nodes.begin() + (set_node_index * 2 + 2), subtree->at(index));
			tree_nodes.erase(tree_nodes.begin() + (set_node_index * 2 + 2) + 1);
			subtree_set(set_node_index * 2 + 2, index + 1, index + 1, subtree, is_right, 3);
			break;
		case 2:
			tree_nodes.insert(tree_nodes.begin() + (set_node_index * 2 + 1), subtree->at(index));
			tree_nodes.erase(tree_nodes.begin() + (set_node_index * 2 + 1) + 1);
			subtree_set(set_node_index * 2 + 1, index + 1, index + 1, subtree, is_right, 3);
			break;
		case 3:
			switch (is_right->at(is_right_index)) {
			case -1:
				tree_nodes.insert(tree_nodes.begin() + (set_node_index * 2 + 1), subtree->at(index));
				tree_nodes.erase(tree_nodes.begin() + (set_node_index * 2 + 1) + 1);
				break;
			case +1:
				tree_nodes.insert(tree_nodes.begin() + (set_node_index * 2 + 2), subtree->at(index));
				tree_nodes.erase(tree_nodes.begin() + (set_node_index * 2 + 2) + 1);
				break;
			case -2:
				subtree_set(set_node_index * 2 + 1, index, is_right_index + 1, subtree, is_right, 3);
				break;
			case +2:
				subtree_set(set_node_index * 2 + 2, index, is_right_index + 1, subtree, is_right, 3);
				break;
			}
			subtree_set(set_node_index, index + 1, index + 1, subtree, is_right, 3);
			break;
		}
	}
}

void AVLTree::right_right_rotation(int first_node, int second_node, int third_node) {
	vector<AVLTreeNode> *first_left, *second_left, *third_left;
	vector<int> *first_right, *second_right, *third_right;
	first_left = new vector<AVLTreeNode>;
	second_left = new vector<AVLTreeNode>;
	third_left = new vector<AVLTreeNode>;
	first_right = new vector<int>;
	second_right = new vector<int>;
	third_right = new vector<int>;
	int first_temp = first_node, second_temp = second_node, third_temp = third_node;

	select_subtree(first_node, first_left, first_right, 2);
	select_subtree(second_node, second_left, second_right, 2);
	select_subtree(third_node, third_left, third_right, 3);

	tree_nodes[first_temp * 2 + 1] = tree_nodes[first_temp];
	tree_nodes[first_temp] = tree_nodes[second_temp];
	tree_nodes[second_temp] = tree_nodes[third_temp];
	tree_nodes[third_temp].id = -1;

	subtree_set(second_temp, 0, 0, third_left, third_right, 3);
	subtree_set(first_temp * 2 + 1, 0, 0, first_left, first_right, 2);
	subtree_set(first_temp * 2 + 1, 0, 0, second_left, second_right, 1);
}

bool AVLTree::search(int entered_id) {
	for (int i = 0; i != tree_nodes.size(); i++) {
		if (tree_nodes[i].id == entered_id) {
			return true;
		}
	}
	return false;
}

void AVLTree::display(bool vertical) {
	if (vertical) {
		///////////Show Vertically///////////
		/////////////////////////////////////
	}
	else {
		int console_width = 80, tolerance = num_of_nodes, level = 0, num_levels = 0;
		while (tolerance > 2) {
			tolerance = (tolerance - 1) / 2;
			level++;
		}
		num_levels = (level * 2) + (level - 1) + (level * 4);

		for (int i = 0; i < (console_width / 2) - (2) - (tree_nodes[0].id_char_num() / 2); i++)
			cout << " ";
		tree_nodes[0].show_node();
		cout << endl;

		int max_num_in_right = 0, min_num_in_right = 0, max_num_in_left = 0, min_num_in_left = 0;
		for (unsigned i = 0; i < tree_nodes.size(); i++) {
			if (tree_nodes[i].is_right == true) {
				if (tree_nodes[i].distance > max_num_in_right)
					max_num_in_right = tree_nodes[i].distance;
				if (tree_nodes[i].distance < min_num_in_right)
					min_num_in_right = tree_nodes[i].distance;
			}
			if (tree_nodes[i].is_right == false) {
				if (tree_nodes[i].distance < max_num_in_left)
					max_num_in_left = tree_nodes[i].distance;
				if (tree_nodes[i].distance > min_num_in_left)
					min_num_in_left = tree_nodes[i].distance;
			}
		}
		int rightWidth, leftWidth;
		rightWidth = max_num_in_right - min_num_in_right;
		leftWidth = min_num_in_left - max_num_in_left;

		int  height = 1, num = 2, ftemp_num = 0, stemp_num = 0;
		bool first = true;
		for (int i = 1; i != tree_nodes.size(); i++) {
			int max_j = 0;

			if (first) {
				max_j = (int)(console_width / (2 * pow(2, height - 1))) / 2 - (2) - (tree_nodes[i].id_char_num() / 2);
				first = false;
			}
			else {
				max_j = (int)((console_width / (2 * pow(2, height - 1))) / 2 - (2) - (tree_nodes[i].id_char_num() / 2)) * 2;
			}

			if (tree_nodes[i].id != -1) {
				for (int i = 0; i < max_j; i++)
					cout << " ";
				tree_nodes[i].show_node();
				if (i == num) {
					cout << endl;
					stemp_num = num;
					num = num + ((num - ftemp_num) * 2);
					ftemp_num = stemp_num;

					first = true;
					height++;	//current height
				}
			}
			else {
				for (int i = 0; i < max_j; i++)
					cout << " ";
				cout << "      ";
			}
		}
		cout << endl;
		cout << endl << "MinR: " << min_num_in_right << " | MaxR: " << max_num_in_right << " | MinL: " << min_num_in_left << " | MaxL: " << max_num_in_left;
	}
}

void AVLTree::basic_display() {
	//Show the "Nodes Array", "Nodes Weight" and "Nodes Lable"
	cout << "Lable:   ";
	for (unsigned j = 0; j < tree_nodes.size(); ++j)
		cout << setw(4) << j;
	cout << "\n\n";

	cout << "Nodes:   ";
	for (unsigned i = 0; i < tree_nodes.size(); ++i)
		cout << setw(4) << tree_nodes[i].id;
	cout << '\n';

	cout << "Weight:  ";
	for (unsigned j = 0; j < tree_nodes.size(); ++j)
		cout << setw(4) << tree_nodes[j].weight;
	cout << '\n';

	cout << "Distance:";
	for (unsigned j = 0; j < tree_nodes.size(); ++j)
		cout << setw(4) << tree_nodes[j].distance;
	cout << '\n';
}

int main() {
	AVLTree tree;
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.insert(5);
	tree.insert(5);
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(3);

	tree.right_right_rotation(0, 2, 6);

	tree.basic_display();
	cout << "\nSearch result: " << tree.search(5) << "\n";
	tree.display(false);
	cin.get();
	return 0;
}