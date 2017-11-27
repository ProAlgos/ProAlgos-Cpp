/*
	Ternary Search
	--------------
	A searching algorithm that finds the position of a maximum(minimum) value within an unimodal array (in 0-indexation).

	Time complexity
	---------------
	O(log(N)), where N is the number of elements in the array.

	Space complexity
	----------------
	O(1).
*/

#include <iostream>
#include <vector>

using namespace std;

int ternarySearch(const vector<int>& Vect, const bool pattern) {
/*
	The function needs to be given an array and a bool 'pattern', where:
	pattern = false, if values in array are ascending, then descending, while their indices are ascending. If pattern equals "false", the function finds the position of a maximum value.
	pattern = true, if values in array are descending, then ascending, while their indices are ascending. If pattern equals "true", the function finds the position of a minimum value.
*/
	int left = 0;
	int right = (int)Vect.size() - 1;
	//left and right are the edges of the interval of search.
	bool changed = true;
	while (right - left > 1 && changed) { //if the interval is not shrinking, its size already equals O(1).
		changed = false;
		int mid1 = left + (right - left) / 3;
		int mid2 = right - (right - left) / 3;
		if ((pattern && Vect[mid1] < Vect[mid2]) || (!pattern && Vect[mid1] > Vect[mid2])) {
			changed |= (right != mid2);
			right = mid2;
		} else {
			changed |= (left != mid1);
			left = mid1;
		}
	}
	int min_value = Vect[left];
	int min_index = left;
	int max_value = Vect[left];
	int max_index = left;
	for (int index = left + 1; index <= right; index++) {
		if (min_value > Vect[index]) {
			min_value = Vect[index];
			min_index = index;
		}
		if (max_value < Vect[index]) {
			max_value = Vect[index];
			max_index = index;
		}
	}
	if (pattern) return min_index; else return max_index;
}

#ifndef TERNARY_SEARCH_TEST
int main()
{
	int sz;
	cout << "Enter the input size:\n";
	cin >> sz;
	vector <int> inputVect(sz); //supposely unimodal array
	cout << "Enter array values:\n";
	for (int& val : inputVect)
		cin >> val;
	bool pattern;
	cout << "Enter 0 if the values in input are ascending then descending, 1 in other case: \n";
	cin >> pattern;
	int index = ternarySearch(inputVect, pattern);
	if (pattern) cout << "Minimum value has position " << index << "\n"; else cout << "Maximum value has position " << index << "\n";
	return 0;
}
#endif
