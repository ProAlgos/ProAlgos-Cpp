/*
    Perfect number check
    --------------------
    Checks whether the given number is perfect or not.
    A perfect number is one whose sum of divisors is equal to the number itself.

    Time complexity
    ---------------
    O(sqrt(N)), where N is the number being checked.

    Space complexity
    ----------------
    O(1).
*/

#include <cmath>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;

bool is_perfect(ULL num) {
    ULL sum = 1;
    for (ULL divisor = 2; divisor <= sqrt(num); divisor++) {
        if (num % divisor == 0)
            sum += divisor + num/divisor;
    }

    if (sum == num)
        return true;
    return false;
}

int main() {
    ULL num;
    cout << "Enter a positive integer less than 2^64 : ";
    cin >> num;

    if (is_perfect(num))
        cout << num << " is a perfect number\n";
    else
        cout << num << " is not a perfect number\n";

    return 0;
}
