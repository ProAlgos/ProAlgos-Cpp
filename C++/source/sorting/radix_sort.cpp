/*
    Radix sort
    ----------
    An efficient, key-index-based, comparision based sorting algorithm.
    It sorts based on the keys obtained on each index of the numbers to be sorteed.
*/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include "sorting/utils.hpp"

using namespace std;

/*
    count_sort
    ----------
    Performs Count Sort on the elements passed by the radix_sort function

    Time complexity
    ---------------
    O(N), where N is the number of keys.

    Space complexity
    ----------------
    O(N), where N is the number of keys.
*/
void count_sort(vector<int>& values, const int& extractor, const bool& to_show_state, const int& mult_factor, const int& add_factor) {
    array<int, 10> counter{0};
    vector<int> output(values.size());

    auto counter_accessor = [&] (const int value) {
        return add_factor + (mult_factor * ((value/extractor) % 10));
    };

    for(int value : values)
        counter[counter_accessor(value)]++;
    for(int i = 1; i < 10; i++)
        counter[i] += counter[i - 1];
    for(int i = values.size() - 1; i >= 0; i--) {
        output[counter[counter_accessor(values[i])] - 1] = values[i];
        counter[counter_accessor(values[i])]--;
    }

    values = output;

    if(to_show_state) {
        display_state(values);
    }
}

//This function returns the maximum value in the vector
int getMaxVal(const vector<int>& values) {
    return *max_element(values.begin(), values.end());
}

/*
    radix_sort
    ----------
    Performs the radix sort by calling the count_sort function

    Time complexity
    ---------------
    O(N), where N is the number of keys.

    Space complexity
    ----------------
    O(N), where N is the number of keys.
*/
void radix_sort(vector<int>& values, const bool& to_show_state, const int& mult_factor, const int& add_factor) {
    int max_value = getMaxVal(values);

    //Extractor variable divides the number by multiples of 10 unless the number becomes 0 as it is used to extract individual digits
    //in a particular position of the number by using mod 10 on the divided number as Radix sort sorts position-wise using Count Sort
    for (int extractor = 1; max_value/extractor > 0; extractor *= 10) {
        count_sort(values, extractor, to_show_state, mult_factor, add_factor);
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

    radix_sort(values, to_show_state, mult_factor, add_factor);

    cout << "\nThe values in " << order_text << " order are:" << endl;
    display_state(values);

    return 0;
}
