#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int value, const vector<int>& sortedVect, int low, int high) {
	int mid = (low + high) / 2;

	if (value == sortedVect[mid])
		return mid;
	else if (low <= high) {
		if (value < sortedVect[mid])
			return binarySearch(value, sortedVect, low, mid-1);
		else if (value > sortedVect[mid])
			return binarySearch(value, sortedVect, mid+1, high);
	}

	return -1;
}

int main() {
	int value;
	cout << "Enter the value to search for : ";
	cin >> value;

	int size;
	cout << "Enter the input size : ";
	cin >> size;

	vector<int> inputVect(size);	// supposedly sorted values
	cout << "Enter " << size << " sorted values (in ascending order) :\n";
	for (int& val: inputVect)
		cin >> val;

	int index = binarySearch(value, inputVect, 0, size-1);
	cout << "\n";
	if (index != -1)
		cout << "Found " << value << " at position " << (index + 1) << "\n";
	else
		cout << "Either " << value << " is not present among the input values, or the values aren\'t sorted\n";

	return 0;
}
