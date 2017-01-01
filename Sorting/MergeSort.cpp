/*
    Merge sort:
    An efficient, comparison-based, divide and conquer sorting algorithm
*/

#include <iostream>
#include <vector>

using namespace std;

void displayState(const vector<int>& valuesVect) {
    for (const int& value: valuesVect)
        cout << value << ' ';
    cout << '\n';
}

void merge(vector<int>& values, int low, int high) {
    vector<int> tempVect(high - low + 1);
    size_t index1 = low;
    size_t index2 = ()(low + high) / 2) + 1;   // mid + 1
    size_t indexT = 0;

    for (int i = start; i <= end ; i++) {
        if(p > mid)      //checks if first part comes to an end or not .
           Arr[ k++ ] = A[ q++] ;

       else if ( q > end)   //checks if second part comes to an end or not
           Arr[ k++ ] = A[ p++ ];

       else if( A[ p ] < A[ q ])     //checks which part has smaller element.
          Arr[ k++ ] = A[ p++ ];

       else
          Arr[ k++ ] = A[ q++];
    }

    for (int p = 0 ; p < k ; p++)
       A[ start++ ] = Arr[ p ] ;
}

void mergeSort(vector<int>& values, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(values, low, mid);
        mergeSort(values, mid+1, high);

        merge(values, low, high);
    }
}

int main() {
    int size;
    cout << "Enter the input size : ";
    cin >> size;

    vector<int> inputVect(size);
    cout << "Enter " << size << " integers :\n";
    for (int& val: inputVect)
        cin >> val;
    cin.ignore();

    string orderInput;
    cout << "In which order should the values be sorted?\n[A]scending / [d]escending : ";
    getline(cin, orderInput);
    int order;
    if (orderInput[0] == 'd' or orderInput[0] == 'D') {
        order = -1;
        orderInput = "descending";
    }
    else {    // ascending order by default
        order = 1;
        orderInput = "ascending";
    }

    string answer;
    cout << "Would you like to view the state of the values after each iteration?\n[y]es / [N]o : ";
    getline(cin, answer);
    bool askedToViewState = false;        // by default, don't show state
    if (answer[0] == 'y' or answer[0] == 'Y')    // unless user asks for it
        askedToViewState = true;

    cout << '\n';
    mergeSort(inputVect, order, askedToViewState);

    cout << "\nThe values in " << orderInput << " order are :\n";
    for (const int& val: inputVect)
        cout << val << " ";
    cout << "\n";

    return 0;
}
