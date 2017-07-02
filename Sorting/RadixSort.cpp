/*
    Radix sort
    ----------
    An efficient, key-index-based, comparision based sorting algorithm.
    It sorts based on the keys obtained on each index of the numbers to be sorteed.
*/

#include <iostream>
#include <vector>
#include "SortingUtils.hpp"

using namespace std;

// The setFactors function sets the factors which depend on whether the sorting is needed to be done in ascending or descending order
void setFactors(const int order, int& mult_factor, int& add_factor) {
    if(order == -1) {
        mult_factor = -1;
        add_factor = 9;
    }
}

/*
    count_sort
    ----------
    Performs Count Sort on the elements passed by the radix_sort function

    Time complexity
    ---------------
    O(N + B), where N is the number of keys and B is the base for representing the numbers(10 in case of decimal system)
    This space is used for count sorting each key and temporarily creating a sorted array.

    Space complexity
    ----------------
    O(N + B), where N is the number of keys and B is the base for representing the numbers(10 in case of decimal system)
    This space is used for count sorting each key and temporarily creating a sorted array.
*/
void count_sort(vector<int>& values, const size_t size, const int I, const int order, const bool to_show_state, const int mult_factor, const int add_factor) {
    int counter[10] = {0};
    int* output = (int*)malloc(size*sizeof(int));
    for(int i = 0; i < size; i++)
        counter[add_factor + (mult_factor * ((values[i]/I) % 10))]++;
    for(int i = 1; i < 10; i++)
        counter[i] += counter[i - 1];
    for(int i = size - 1; i >= 0; i--) {
        output[counter[add_factor + (mult_factor * ((values[i]/I) % 10))] - 1] = values[i];
        counter[add_factor + (mult_factor * ((values[i]/I) % 10))]--;
    }

    for(int i = 0; i < size; i++)
        values[i] = output[i];

    if(to_show_state) {
        cout << "Printing the current state..." << endl;
        for (int i = 0; i < size; i++) {
            cout << values[i] << "\t";
        }
        cout << endl;
    }
}

//This function returns the maximum value in the vector
int getMaxVal(const vector<int> values, const size_t size) {
    int max_val = values[0];
    for (int i = 1; i < size; i++) {
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
void radix_sort(vector<int>& values, const size_t size, const int order, const bool to_show_state, const int mult_factor, const int add_factor) {
    int m = getMaxVal(values, size);
    for (int i = 1; m/i > 0; i *= 10) {
        count_sort(values, size, i, order, to_show_state, mult_factor, add_factor);
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
    setFactors(order, mult_factor, add_factor);

    radix_sort(values, size, order, to_show_state, mult_factor, add_factor);

    cout << "\nThe values in " << order_text << " order are:" << endl;
    display_state(values);

    return 0;
}
