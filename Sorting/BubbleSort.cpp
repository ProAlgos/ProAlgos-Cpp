/*
    Bubble sort (also known as sinking sort):
	A simple sorting algorithm that repeatedly compares pairs of adjacent elements
	and swaps their positions if they are in the wrong order
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void displayState(const vector<int>& valuesVect) {
	for (const int& value: valuesVect)
		cout << value << ' ';
	cout << '\n';
}

void bubbleSort(vector<int>& values, int order, bool askedToViewState) {
    bool swapped;
	size_t i, j;

	for (i = 0; i < values.size() - 1; i++) {
		swapped = false;

		for (j = 0; i + j < values.size() - 1; j++)
            if (order * values[j] > order * values[j+1]) {	// 'order' is -1 for descending, so the inequality is reversed
                swap(values[j], values[j+1]);
				swapped = true;

				if (askedToViewState)
					displayState(values);
			}

		if (!swapped)
			break;
	}
}

int main() {
    int size;
    cout << "Enter the input size : ";
    cin >> size;

    vector<int> inputVect(size);
    cout << "Enter " << size << " integers :\n";
    for (int& val: inputVect)
        cin >> val;
	cin.ignore();

    string orderInput;
    cout << "In which order should the values be sorted?\n[A]scending / [d]escending : ";
	getline(cin, orderInput);
    int order;
    if (orderInput[0] == 'd' or orderInput[0] == 'D') {
        order = -1;
        orderInput = "descending";
    }
    else {    // ascending order by default
        order = 1;
        orderInput = "ascending";
    }

	string answer;
    cout << "Would you like to view the state of the values after each swap?\n[y]es / [N]o : ";
	getline(cin, answer);
    bool askedToViewState = false;		// by default, don't show state
    if (answer[0] == 'y' or answer[0] == 'Y')	// unless user asks for it
        askedToViewState = true;

	cout << '\n';
    bubbleSort(inputVect, order, askedToViewState);

    cout << "\nThe values in " << orderInput << " order are :\n";
    for (const int& val: inputVect)
        cout << val << " ";
    cout << "\n";

    return 0;
}
