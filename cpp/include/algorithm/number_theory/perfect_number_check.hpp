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

#ifndef PERFECT_NUMBER_CHECK_HPP
#define PERFECT_NUMBER_CHECK_HPP

#include <cmath>

typedef unsigned long long ULL;

bool is_perfect(ULL num) {
    ULL sum = 1;
    for (ULL divisor = 2; divisor <= sqrt(num); divisor++) {
        if (num % divisor == 0)
            sum += divisor + num/divisor;
    }

    if (sum == num) {
        return true;
    }
    return false;
}

#endif // PERFECT_NUMBER_CHECK_HPP
