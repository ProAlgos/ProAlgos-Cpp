/*
    Ternary search
    --------------
    A searching algorithm that finds the position of a maximum(minimum) value
    within an unimodal array.

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

enum Pattern {
    ASCEND_THEN_DESCEND,
    DESCEND_THEN_ASCEND
};

/*
    ternary_search
    -------------
    If the values first ascend and then descend, this function finds the position
    of the maximum value. Otherwise, if they first descend and then ascend, it
    finds the position of the minimum value.
*/
template <typename T>
size_t ternary_search(const vector<T>& values, const Pattern& pattern) {
    // left and right are the edges of the interval of search
    size_t left = 0;
    size_t right = values.size() - 1;

    bool changed = true;
    size_t mid1, mid2;
    while (right - left > 1 and changed) {  // if the interval is not shrinking,
                                            // its size already equals O(1)
        changed = false;
        mid1 = left + (right - left) / 3;
        mid2 = right - (right - left) / 3;
        if ((pattern and values[mid1] < values[mid2])
            or (!pattern and values[mid1] > values[mid2])) {
            changed |= (right != mid2);
            right = mid2;
        }
        else {
            changed |= (left != mid1);
            left = mid1;
        }
    }

    T min_value = values[left];
    T max_value = values[left];
    size_t min_index = left;
    size_t max_index = left;
    for (size_t index = left + 1; index <= right; index++) {
        if (min_value > values[index]) {
            min_value = values[index];
            min_index = index;
        }
        if (max_value < values[index]) {
            max_value = values[index];
            max_index = index;
        }
    }

    return pattern == ASCEND_THEN_DESCEND ? max_index : min_index;
}

#ifndef TERNARY_SEARCH_TEST
int main() {
    int size;
    cout << "Enter the input size : ";
    cin >> size;

    vector <int> input_values(size);    //supposedly unimodal array
    cout << "Enter " << size << " values:\n";
    for (int& value: input_values)
        cin >> value;

    string answer;
    cout << "\nDo the values first ascend then descend?"
         << "If otherwise, enter \"no\".\n"
         << "[Y]es / [n]o : ";
    getline(cin, answer);

    Pattern pattern = ASCEND_THEN_DESCEND;  // answer is "yes" by default
    if (answer[0] == 'n' or answer[0] == 'N')   // user answers "no"
        pattern = Pattern::DESCEND_THEN_ASCEND;

    int index = ternary_search(input_values, pattern);
    if (pattern == ASCEND_THEN_DESCEND)
        cout << "Maximum value has position " << index << "\n";
    else
        cout << "Minimum value has position " << index << "\n";

    return 0;
}
#endif
