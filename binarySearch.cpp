#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int value, const vector<int>& sortedArray, int low, int high) {
	int mid = (low + high) / 2;
	
	if (value == sortedArray[mid])
		return mid;
	else if (low <= high) {
		if (value < sortedArray[mid])
			return binarySearch(value, sortedArray, low, mid-1);
		else if (value > sortedArray[mid])
			return binarySearch(value, sortedArray, mid+1, high);
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
	
	vector<int> arr(size);	// supposedly sorted values
	cout << "Enter " << size << " sorted values : ";
	for (int& val: arr)
		cin >> val;
	
	int index = binarySearch(value, arr, 0, size-1);
	if (index != -1)
		cout << "Found " << value << " at position " << (index + 1) << "\n";
	else {
		// TODO: sort and check once more
		cout << value << " is not present among the input values\n";
	}
	
	return 0;
}
