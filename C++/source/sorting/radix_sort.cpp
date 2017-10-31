/*
    Radix sort
    ----------
    Least significant digit radix sort is an efficient, non-comparative, integer
    sorting algorithm that sorts data with integer keys by grouping keys by the
    individual digits which share the same significant position and value.
    NOTE: This implementation of radix sort can be used to sort positive integers
    only.
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#include "sorting/utils.hpp"

using namespace std;

/*
    count_sort
    ----------
    Performs count sort on the elements passed by radix_sort.

    Time complexity
    ---------------
    O(N), where N is the number of keys.

    Space complexity
    ----------------
    O(N), where N is the number of keys.
*/
void count_sort(vector<int>& values, const int extractor, const int mult_factor,
        const int add_factor, const bool to_show_state = false) {
    array<int, 10> counter{0};
    vector<int> output(values.size());

    auto get_digit = [&] (const int value) {
        return add_factor + (mult_factor * ((value / extractor) % 10));
    };

    for (int value: values)
        counter[get_digit(value)]++;
    for (int i = 1; i < 10; i++)
        counter[i] += counter[i - 1];
    for (int i = values.size() - 1; i >= 0; i--) {
        output[counter[get_digit(values[i])] - 1] = values[i];
        counter[get_digit(values[i])]--;
    }

    values = output;

    if (to_show_state)
        display_state(values);
}

/*
    max_in_vector
    -------------
    Returns the maximum value in a vector.
*/
int max_in_vect(const vector<int>& values) {
    return *max_element(values.begin(), values.end());
}

/*
    radix_sort
    ----------
    Performs least significant digit radix sort, making use of count_sort.

    Time complexity
    ---------------
    O(N), where N is the number of keys.

    Space complexity
    ----------------
    O(N), where N is the number of keys.
*/
void radix_sort(vector<int>& values, const int mult_factor, const int add_factor,
        const bool to_show_state = false) {
    int max_value = max_in_vect(values);

    // on each iteration of the following loop, extractor helps in getting the
    // next significant digit, which is (value / extractor) mod 10
    for (int extractor = 1; max_value / extractor > 0; extractor *= 10)
        count_sort(values, extractor, to_show_state, mult_factor, add_factor);
}

int main() {
    // number of elements to be sorted
    size_t size;
    get_input_size(size);

    vector<int> values(size);
    get_input_values(values, size);

    // order is set to `1` for 'ascending' and `-1` for 'descending'
    int order;
    string order_text;
    get_order(order, order_text);

    // to_show_state will be set to `true` if intermediate states are to be displayed
    bool to_show_state;
    get_whether_to_show_state(to_show_state);

    // the following factors depend on the sorting order
    int mult_factor = 1;
    int add_factor = 0;
    if (order == -1) {
        mult_factor = -1;
        add_factor = 9;
    }

    radix_sort(values, mult_factor, add_factor, to_show_state);

    cout << "\nThe values in " << order_text << " order are:" << endl;
    display_state(values);

    return 0;
}
