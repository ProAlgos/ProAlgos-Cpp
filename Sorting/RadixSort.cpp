/*
    Radix sort
    ----------
    An efficient, key-index-based, comparision based sorting algorithm.
    It sorts based on the keys obtained on each index of the numbers to be sorteed.
*/

#include <iostream>
#include <vector>
#include <array>
#include "SortingUtils.hpp"

using namespace std;

// The setFactors function sets the factors which depend on whether the sorting is needed to be done in ascending or descending order

/*
    count_sort
    ----------
    Performs Count Sort on the elements passed by the radix_sort function

    Time complexity
    ---------------
    O(N + B), where N is the number of keys and B is the base for representing the numbers(10 in case of decimal system)

    Space complexity
    ----------------
    O(N + B), where N is the number of keys and B is the base for representing the numbers(10 in case of decimal system)
    This space is used for count sorting each key and temporarily creating a sorted array.
*/
void count_sort(vector<int>& values, const int extractor, const int order, const bool to_show_state, const int mult_factor, const int add_factor) {
    array<int, 10> counter{0};
    vector<int> output(values.size());
    for(int value : values)
        counter[add_factor + (mult_factor * ((value/extractor) % 10))]++;
    for(int i = 1; i < 10; i++)
        counter[i] += counter[i - 1];
    for(int value : values) {
        output[counter[add_factor + (mult_factor * ((value/extractor) % 10))] - 1] = value;
        counter[add_factor + (mult_factor * ((value/extractor) % 10))]--;
    }

    values = output;

    if(to_show_state) {
    	display_state(values);
    }
}

//This function returns the maximum value in the vector
int getMaxVal(const vector<int> values) {
    int max_val = values[0];
    for (int i = 1; i < values.size(); i++) {
    if (values[i] > max_val)
            max_val = values[i];
    }
    return max_val;
}

/*
    radix_sort
    ----------
    Performs the radix sort by calling the count_sort function

    Time complexity
    ---------------
    O(D * N), where N is the number of keys, D is the number of digits in input integers.

    Space complexity
    ----------------
    O(N + B), where N is the number of elements and B is the base for representing the numbers(10 in case of decimal system)
    This space is used for count sorting each key and temporarily creating a sorted array.
*/
void radix_sort(vector<int>& values, const int order, const bool to_show_state, const int mult_factor, const int add_factor) {
    int m = getMaxVal(values);
    for (int extractor = 1; m/extractor > 0; extractor *= 10) {
        count_sort(values, extractor, order, to_show_state, mult_factor, add_factor);
    }
}

int main() {

    //No. of elements to be sorted
    size_t size;
    get_input_size(size);

    vector<int> values(size);
    get_input_values(values, size);

    //order is set to 1 if the sorting is done in ascending order, -1 if the sorting is done in descending order
    int order;
    string order_text;
    get_order(order, order_text);

    //to_show_state will be set to true if the states are needed to be printed
    bool to_show_state;
    get_whether_to_show_state(to_show_state);

    //These factors depend on whether the sorting is needed to be done in ascending or descending order
    int mult_factor = 1;
    int add_factor = 0;
    if(order == -1) {
        mult_factor = -1;
      	add_factor = 9;
    }

    radix_sort(values, order, to_show_state, mult_factor, add_factor);

    cout << "\nThe values in " << order_text << " order are:" << endl;
    display_state(values);

    return 0;
}
