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
	O(N), where N is the number of nodex.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>

using namespace std;

class AVLTreeNode {
private:
public:
	int w;			//weight of node
	int ID;			//Unique ID of node
	int dis;		//Distance from root
	bool isRight;	//Is this object distance from right of its parent

	AVLTreeNode() {
		w = 0;
		ID = 0;
		dis = 0;
	}

	int IDCharNum() {				//ReturnID Characters number
		char str1[256];
		_itoa_s(ID, str1, 10);
		string str2 = str1;
		return str2.size();
	}
	void showNode() {				//Show the node with this syntax in four rectangle: [_ID_]
		switch (IDCharNum()) {
		case 1:
			cout << "[_" << ID << "__]";
			break;
		case 2:
			cout << "[_" << ID << "_]";
			break;
		case 3:
			cout << "[" << ID << "_]";
			break;
		default:
			cout << "[" << ID << "]";
			break;
		}
	}
protected:
};

class AVLTree {
private:
	vector<AVLTreeNode> treeNodes;		//Nodes Array
	stack<int> usedNodes;			//Way of going to insert a new node
	stack<bool> isUsedNodeRight;	//Help for Way of going to insert a new node in right or left
	int numberOfNodes;

	void weightUpdate(int i);		//Update new node weight
	void selectSubtree(int index, vector<AVLTreeNode> *subtree, vector<int> *isRight, int status);
	void subtreeSet(int setNodeIndex, int index, int isRIndex, vector<AVLTreeNode> *subtree, vector<int> *isRight, int status);
public:
	AVLTree() {
		numberOfNodes = 0;
	}

	bool insert(int enteredID);
	bool search(int enteredID);

	void rightRightRotation(int node1i, int node2i, int node3i);
	void display(bool vertical);
	void basicDisplay();
protected:
};

bool AVLTree::insert(int enteredID) {
	int rootDistance = 0;
	AVLTreeNode newNode;
	newNode.w = 0;
	newNode.ID = enteredID;
	AVLTreeNode emptyNode;
	emptyNode.w = 0;
	emptyNode.ID = -1;
	if (treeNodes.size() == 0) {
		treeNodes.push_back(newNode);
		treeNodes.push_back(emptyNode);
		treeNodes.push_back(emptyNode);

		numberOfNodes++;
		return true;
	} else {
		bool isRight, first = true;
		vector<AVLTreeNode>::iterator p = treeNodes.begin();
		int checkID = (*p).ID, localID = -1;
		for (int i = 0; i != treeNodes.size(); checkID = treeNodes[i].ID) {
			if (enteredID > checkID) {
				//Calculating weight and distance
				treeNodes[i].w = treeNodes[i].w + 1;	//Right++
				usedNodes.push(i);						//Save way in tree
				isUsedNodeRight.push(true);				//Save go right/left in tree
				rootDistance++;							//Increase distance
				if (first) {
					isRight = true;
					first = false;
				}
				//

				localID = treeNodes[(i * 2) + 2].ID;
				if (localID == -1) {
					treeNodes[(i * 2) + 2] = newNode;
					treeNodes[(i * 2) + 2].dis = rootDistance;
					treeNodes[(i * 2) + 2].isRight = isRight;
					weightUpdate((i * 2) + 2);

					treeNodes.push_back(emptyNode);
					treeNodes.push_back(emptyNode);
					numberOfNodes++;
					return true;
				} else {
					int k = i;
					i = (i * 2) + 2;		//2i+1

					for (int j = 0; j < i - k; j++) {
						treeNodes.push_back(emptyNode);
					}
				}
			} else if (enteredID <= checkID) {
				//Calculating weight and distance
				treeNodes[i].w = treeNodes[i].w - 1;	//Right++
				usedNodes.push(i);						//Save way in tree
				isUsedNodeRight.push(false);			//Save go right/left in tree
				rootDistance--;							//decrease distance
				if (first) {
					isRight = false;
					first = false;
				}
				//

				localID = treeNodes[(i * 2) + 1].ID;
				if (localID == -1) {
					treeNodes[(i * 2) + 1] = newNode;
					treeNodes[(i * 2) + 1].dis = rootDistance;
					treeNodes[(i * 2) + 1].isRight = isRight;
					weightUpdate((i * 2) + 1);

					treeNodes.push_back(emptyNode);
					treeNodes.push_back(emptyNode);
					numberOfNodes++;
					return true;
				} else {
					int k = i;
					i = (i * 2) + 1;		//2i

					for (int j = 0; j < i - k; j++) {
						treeNodes.push_back(emptyNode);
					}
				}
			}
		}
	}
	return false;
}

void AVLTree::weightUpdate(int index) {
	bool work = false;
	//Check "Is the newNode have a (next/previous) neighbor leaf?"
	//When "yes", we must redo the changes in the node's weight . . .
	if (index % 2 == 0) {
		if (treeNodes[index - 1].ID != -1) {
			work = true;
		}
	}
	else {
		if (treeNodes[index + 1].ID != -1) {
			work = true;
		}
	}
	if (work) {
		int stepIndex;
		bool right;

		usedNodes.pop();
		isUsedNodeRight.pop();
		while (!usedNodes.empty()) {
			stepIndex = usedNodes.top();
			right = isUsedNodeRight.top();

			if (right) {
				treeNodes[stepIndex].w = treeNodes[stepIndex].w - 1;
			}
			else {
				treeNodes[stepIndex].w = treeNodes[stepIndex].w + 1;
			}

			usedNodes.pop();
			isUsedNodeRight.pop();
		}
	}
	while (!usedNodes.empty()) {
		usedNodes.pop();
		isUsedNodeRight.pop();
	}
}

void AVLTree::selectSubtree(int index, vector<AVLTreeNode> *subtree, vector<int> *isRight, int status) {
	//status=1 : Just get right subtree, status=2 : Just get left subtree, status=3 : both right and left subtree
	//index : is the node we need to get subtree from that
	if (treeNodes[index].ID != -1) {
		switch (status) {
		case 1:
			subtree->push_back(treeNodes[index * 2 + 2]);	//Node one right subtree
			isRight->push_back(+1);

			//selectSubtree(index*2+2, subtree, 1);
			isRight->push_back(+2);
			selectSubtree(index * 2 + 2, subtree, isRight, 3);
			treeNodes[index * 2 + 2].ID = -1;
			break;
		case 2:
			subtree->push_back(treeNodes[index * 2 + 1]);	//Node one left subtree
			isRight->push_back(-1);

			//selectSubtree(index*2+1, subtree, 2);
			isRight->push_back(-2);
			selectSubtree(index * 2 + 1, subtree, isRight, 3);
			treeNodes[index * 2 + 1].ID = -1;
			break;
		case 3:
			subtree->push_back(treeNodes[index * 2 + 1]);	//Node one left subtree
			isRight->push_back(-1);
			subtree->push_back(treeNodes[index * 2 + 2]);	//Node one right subtree
			isRight->push_back(+1);

			isRight->push_back(-2);
			selectSubtree(index * 2 + 1, subtree, isRight, 3);
			isRight->push_back(+2);
			selectSubtree(index * 2 + 2, subtree, isRight, 3);
			treeNodes[index * 2 + 1].ID = -1;
			treeNodes[index * 2 + 2].ID = -1;
			break;
		}
	}
}

void AVLTree::subtreeSet(int setNodeIndex, int index, int isRIndex, vector<AVLTreeNode> *subtree, vector<int> *isRight, int status) {
	//status=1 : Just get right subtree, status=2 : Just get left subtree, status=3 : both right and left subtree
	if (treeNodes[index].ID != -1) {
		switch (status) {
		case 1:
			treeNodes.insert(treeNodes.begin() + (setNodeIndex * 2 + 2), subtree->at(index));
			treeNodes.erase(treeNodes.begin() + (setNodeIndex * 2 + 2) + 1);
			subtreeSet(setNodeIndex * 2 + 2, index + 1, index + 1, subtree, isRight, 3);
			break;
		case 2:
			treeNodes.insert(treeNodes.begin() + (setNodeIndex * 2 + 1), subtree->at(index));
			treeNodes.erase(treeNodes.begin() + (setNodeIndex * 2 + 1) + 1);
			subtreeSet(setNodeIndex * 2 + 1, index + 1, index + 1, subtree, isRight, 3);
			break;
		case 3:
			switch (isRight->at(isRIndex)) {
			case -1:
				treeNodes.insert(treeNodes.begin() + (setNodeIndex * 2 + 1), subtree->at(index));
				treeNodes.erase(treeNodes.begin() + (setNodeIndex * 2 + 1) + 1);
				break;
			case +1:
				treeNodes.insert(treeNodes.begin() + (setNodeIndex * 2 + 2), subtree->at(index));
				treeNodes.erase(treeNodes.begin() + (setNodeIndex * 2 + 2) + 1);
				break;
			case -2:
				subtreeSet(setNodeIndex * 2 + 1, index, isRIndex + 1, subtree, isRight, 3);
				break;
			case +2:
				subtreeSet(setNodeIndex * 2 + 2, index, isRIndex + 1, subtree, isRight, 3);
				break;
			}
			subtreeSet(setNodeIndex, index + 1, index + 1, subtree, isRight, 3);
			break;
		}
	}
}

void AVLTree::rightRightRotation(int node1i, int node2i, int node3i) {
	vector<AVLTreeNode> *node1left, *node2left, *node3leftRight;
	vector<int> *node1isRight, *node2isRight, *node3isRight;
	node1left = new vector<AVLTreeNode>;
	node2left = new vector<AVLTreeNode>;
	node3leftRight = new vector<AVLTreeNode>;
	node1isRight = new vector<int>;
	node2isRight = new vector<int>;
	node3isRight = new vector<int>;
	int tn1i = node1i, tn2i = node2i, tn3i = node3i;

	selectSubtree(node1i, node1left, node1isRight, 2);
	selectSubtree(node2i, node2left, node2isRight, 2);
	selectSubtree(node3i, node3leftRight, node3isRight, 3);

	treeNodes[tn1i * 2 + 1] = treeNodes[tn1i];
	treeNodes[tn1i] = treeNodes[tn2i];
	treeNodes[tn2i] = treeNodes[tn3i];
	treeNodes[tn3i].ID = -1;

	subtreeSet(tn2i, 0, 0, node3leftRight, node3isRight, 3);
	subtreeSet(tn1i * 2 + 1, 0, 0, node1left, node1isRight, 2);
	subtreeSet(tn1i * 2 + 1, 0, 0, node2left, node2isRight, 1);
}

bool AVLTree::search(int enteredID) {
	for (int i = 0; i != treeNodes.size(); i++) {
		if (treeNodes[i].ID == enteredID) {
			return true;
		}
	}
	return false;
}

void AVLTree::display(bool vertical) {
	if (vertical) {
		///////////Show Vertically///////////
		/////////////////////////////////////
	} else {
		int consoleWidth = 80, tolerance = numberOfNodes, level = 0, numOfCC = 0;
		while (tolerance > 2) {
			tolerance = (tolerance - 1) / 2;
			level++;
		}
		numOfCC = (level * 2) + (level - 1) + (level * 4);

		for (int i = 0; i < (consoleWidth / 2) - (2) - (treeNodes[0].IDCharNum() / 2); i++)
			cout << " ";
		treeNodes[0].showNode();
		cout << endl;

		int maxNumInRight = 0, minNumInRight = 0, maxNumInLeft = 0, minNumInLeft = 0;
		for (unsigned i = 0; i < treeNodes.size(); i++) {
			if (treeNodes[i].isRight == true) {
				if (treeNodes[i].dis > maxNumInRight)
					maxNumInRight = treeNodes[i].dis;
				if (treeNodes[i].dis < minNumInRight)
					minNumInRight = treeNodes[i].dis;
			}
			if (treeNodes[i].isRight == false) {
				if (treeNodes[i].dis < maxNumInLeft)
					maxNumInLeft = treeNodes[i].dis;
				if (treeNodes[i].dis > minNumInLeft)
					minNumInLeft = treeNodes[i].dis;
			}
		}
		int rightWidth, leftWidth;
		rightWidth = maxNumInRight - minNumInRight;
		leftWidth = minNumInLeft - maxNumInLeft;

		int  h = 1, N = 2, tN = 0, ttN = 0;
		bool first = true;
		for (int i = 1; i != treeNodes.size(); i++) {
			int maxJ = 0;

			if (first) {
				maxJ = (int)(consoleWidth / (2 * pow(2, h - 1))) / 2 - (2) - (treeNodes[i].IDCharNum() / 2);
				first = false;
			}
			else {
				maxJ = (int)((consoleWidth / (2 * pow(2, h - 1))) / 2 - (2) - (treeNodes[i].IDCharNum() / 2)) * 2;
			}

			if (treeNodes[i].ID != -1) {
				for (int i = 0; i < maxJ; i++)
					cout << " ";
				treeNodes[i].showNode();
				if (i == N) {
					cout << endl;
					ttN = N;
					N = N + ((N - tN) * 2);
					tN = ttN;

					first = true;
					h++;	//current height
				}
			}
			else {
				for (int i = 0; i < maxJ; i++)
					cout << " ";
				cout << "      ";
			}
		}
		cout << endl;
		cout << endl << "MinR: " << minNumInRight << " | MaxR: " << maxNumInRight << " | MinL: " << minNumInLeft << " | MaxL: " << maxNumInLeft;
	}
}

void AVLTree::basicDisplay() {
	//Show the "Nodes Array", "Nodes Weight" and "Nodes Lable"
	cout << "Lable:   ";
	for (unsigned j = 0; j < treeNodes.size(); ++j)
		cout << setw(4) << j;
	cout << "\n\n";

	cout << "Nodes:   ";
	for (unsigned i = 0; i < treeNodes.size(); ++i)
		cout << setw(4) << treeNodes[i].ID;
	cout << '\n';

	cout << "Weight:  ";
	for (unsigned j = 0; j < treeNodes.size(); ++j)
		cout << setw(4) << treeNodes[j].w;
	cout << '\n';

	cout << "Distance:";
	for (unsigned j = 0; j < treeNodes.size(); ++j)
		cout << setw(4) << treeNodes[j].dis;
	cout << '\n';
}

int main() {
	AVLTree AVL;
	AVL.insert(4);
	AVL.insert(5);
	AVL.insert(6);
	AVL.insert(7);
	AVL.insert(5);
	AVL.insert(5);
	AVL.insert(1);
	AVL.insert(2);
	AVL.insert(3);
	AVL.insert(3);

	AVL.rightRightRotation(0, 2, 6);

	AVL.basicDisplay();
	cout << "\nSearch result: " << AVL.search(5) << "\n";
	AVL.display(false);
	cin.get();
	return 0;
}