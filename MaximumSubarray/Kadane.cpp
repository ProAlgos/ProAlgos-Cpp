/*
    Kadane's algorithm:
    ------------------
    Used for finding the contiguous subarray within a one-dimensional array
    of integers which has the largest sum.
    
    Time complexity
    ---------------
    O(N), where N is the number of elements in the original array.
    
    Space complexity
    ----------------
    O(1).
*/

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

tuple<int, size_t, size_t> maximumSubarray(const vector<int> &values)
{
    int maxSum, currentSum;
    size_t nextStart, start, end;

    maxSum = currentSum = values[0];
    nextStart = start = end = 0;
    for (size_t i = 1; i < values.size(); i++) {
        currentSum += values[i];

        if (currentSum < values[i]) {
            currentSum = values[i];
            nextStart = i;
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = nextStart;
            end = i;
        }
    }

    return make_tuple(maxSum, start, end);
}

int main()
{
    size_t size;
    cout << "Enter the input size : ";
    cin >> size;

    vector<int> values(size);
    cout << "Enter " << size << " integers :\n";
    for (int &val : values)
        cin >> val;

    int maxSum;
    size_t start, end;
    tie(maxSum, start, end) = maximumSubarray(values);

    cout << "\nThe contiguous subarray with the largest sum is:\n";
    for (size_t i = start; i <= end; i++)
        cout << values[i] << " ";
    cout << "\n(from position " << start + 1 << " to " << end + 1 << ")\n\n";
    cout << "Sum of its elements is " << maxSum << '\n';

    return 0;
}
