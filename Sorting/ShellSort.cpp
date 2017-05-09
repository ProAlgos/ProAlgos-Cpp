/*
    Shell sort
    -----------
    An in-place comparison sort which starts by sorting pairs of elements far apart from each other,
    then progressively reducing the gap between elements to be compared. The time complexity depends on
    the gap sequence, which is floor(N/2^K) in this implementation

    Time complexity
    ----------------
    O(N^2), where N is the nubmer of elements.

    Space complexity
    -----------------
    O(1).
*/

#include <iostream>
#include <vector>
#include "SortingUtils.hpp"

using namespace std;

void shell_sort (vector<int> &values, const bool &show_state) {
    int n = values.size();

    // We calculate the gap sequence in order of |n/2|, |n/4|,....
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {

            int temp = values[i];
            int j;
            for (j = i; j >= gap && values[j - gap] > temp; j -= gap)
                values[j] = values[j - gap];

            values[j] = temp;

            if (show_state)
                display_state(values);
        }
    }
}

int main () {
    size_t size;
    get_input_size(size);

    vector<int> values(size);
    get_input_values(values, size);
    
    bool show_state;
    get_whether_to_show_state(show_state);

    shell_sort(values, show_state);
    display_state(values);
}