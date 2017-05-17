/*
     Sorting an Array in a Wave Form
    -----------
    This is also known as Wiggle sort.It is a simplistic algorithm which which sorts
    a given unsorted array arr[] in the following manner:
    arr[0] < arr[1] > arr[2] < arr[3] > arr[4] <…..
    

    Time complexity
    ---------------
    O(N), where N is the number of elements

    Space complexity
    ----------------
    O(1).
*/

#include <iostream>
#include <vector>

using namespace std;

void wiggle_sort(vector<int>& values, int size) {
    //size_t i,j;
    int num_values;
    int median_value;
    int first_position=0;
    int mid_position=0;
    int last_position;

    //Check if the vector has values
    if (values.empty()) {
        return;            
    }
    num_values=values.size();
    //Find the median at the ith position 
    vector<int>::iterator ith = next(values.begin(),num_values/ 2);
    nth_element(values.begin(), ith,values.end());
    median_value = *ith;
    /*3- way partition
    Rearrangement is based on  the ordering of element indices.We rearrange the
    elements  by filling the odd positions(indices) of the final vector at first,
    followed by even positions of the final vector.Hence array_value is used.  	 
    */ 
    auto array_value = [num_values](int index) { return (2 * index + 1) % (num_values | 1); };          
    last_position =num_values- 1;
    while (mid_position <= last_position) {
        if (values[array_value(mid_position)] > median_value) {
            swap(values[array_value(first_position)],values[array_value(mid_position)]);
            ++first_position;
            ++mid_position;
        }
        else if (values[array_value(mid_position)] < median_value) {
            swap(values[array_value(mid_position)],values[array_value(last_position)]);
            --last_position;
        }               
        else {
            ++mid_position;
        }
    }

    for (int& val: values)
        cout<< val;
}

int main() {
    int size;

    cout<<"Enter the size of the input";
    cin>>size;

    vector<int> inputVect(size);   
    cout<<"Enter the array elements";
    for (int& val: inputVect)
        cin >> val;
    
    wiggle_sort(inputVect,size);

    return 0;
}
