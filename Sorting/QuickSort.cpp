/*
	Quicksort:
	An efficient, comparison-based, in-place, divide and conquer sorting algorithm
*/

#include <iostream>
#include <vector>

using namespace std;

void displayState(const vector<int>& valuesVect) {
	for (const int& value: valuesVect)
		cout << value << ' ';
	cout << '\n';
}

int partition(vector<int>& values, const size_t start, const size_t end, const int order) {
	int i = start + 1;
	int piv = values[start] ;			//make the first element as pivot element.

    int random = start + rand( )%(end-start +1 ) ;

     swap ( values[random] , values[start]) ;		//swap pivot with 1st element.

    for (int j = start + 1; j <= end; j++ )  {
    /*rearrange the array by putting elements which are less than pivot
       on one side and which are greater that on other. */
        if ( values[ j ] < piv) {
            swap (values[ i ],values [ j ]);
            i += 1;
        }
    }

    swap ( values[ start ] ,values[ i-1 ] ) ;  //put the pivot element in its proper place.

    return i-1;					  // return the index of the pivot element
}

void quickSort(vector<int>& values, const size_t start, const size_t end, const int order, const bool askedToViewState) {
	if (start < end) {
		int pivotIndex = partition (values, start, end, order);    // index of the pivot element

		quickSort (values, start, pivotIndex-1, order, askedToViewState);   // sort values to the left of pivot
		quickSort (values, pivotIndex+1, end, order, askedToViewState);     // sort values to the right of pivot

		if (askedToViewState)
			displayState(values);
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
	else {	// ascending order by default
		order = 1;
		orderInput = "ascending";
	}

	string answer;
	cout << "Would you like to view the state of the values after each iteration?\n[y]es / [N]o : ";
	getline(cin, answer);
	bool askedToViewState = false;		// by default, don't show state
	if (answer[0] == 'y' or answer[0] == 'Y')	// unless user asks for it
		askedToViewState = true;

	cout << '\n';
	quickSort(inputVect, 0, size-1, order, askedToViewState);

	cout << "\nThe values in " << orderInput << " order are :\n";
	for (const int& val: inputVect)
		cout << val << " ";
	cout << "\n";

	return 0;
}
