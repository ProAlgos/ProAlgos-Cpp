/*
    Extended Euclidean algorithm
    ----------------------------
    Given two non-negative numbers A and B as inputs, find M[0], M[1] such that:
    greatest_common_divisor(A, B) = M[0]*B + M[1]*B

    Time complexity
    ---------------
    O(log(k)), where k = min(a, b) is the smaller of the input integers a and b

    Space complexity
    ----------------
    O(1).
*/

#ifndef EXTENDED_EUCLIDEAN_HPP
#define EXTENDED_EUCLIDEAN_HPP

#include <array>

using std::array;

/*
    extended_euclidean
    ------------------
    Uses the recurrence relation:
        greatest_common_divisor(a, b) = greatest_common_divisor(b, a % b)
    to find coefficients M[0] and M[1] such that:
        greatest_common_divisor(a, b) = (M[0] * a) + (M[1] * b)

    Loop invariant: greatest_common_divisor(a, b) is the same at the end of each
    iteration a = aM[0] * (original value of a) + aM[1] * (original value of b)
    The above statement holds for b and bM as well.

    Return value
    ------------
    array<int, 2> M of length 2 which satisfies the equation above
*/

array<int, 2> extended_euclidean(int a, int b) {
    array<int, 2> aM = {{1, 0}};
    array<int, 2> bM = {{0, 1}};
    while (b != 0) {
        aM[0] -= (a/b) * bM[0];
        aM[1] -= (a/b) * bM[1];

        aM.swap(bM);

        int newA = b;
        b = a % b;
        a = newA;

    }
    return aM;
}

# endif // EXTENDED_EUCLIDEAN_HPP
