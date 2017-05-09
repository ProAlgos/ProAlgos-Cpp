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

using namespace std;

void shell_sort (vector<int> &arr) {
    int n = arr.size();

    // We calculate the gap sequence in order of |n/2|, |n/4|,....
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {

            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

// Print the array elements.
void print(const vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main () {
    vector<int> arr;
    int n;
    cout << "Enter number of elements int the array: ";
    cin >> n;

    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    shell_sort(arr);
    print(arr);
}