/*
    Binomial coefficient
    --------------------
    For a set containing N unique elements, find the number of subsets containing
    K elements (a.k.a. "N choose K"). Alternatively, it is the coefficient of X^K
    in the binomial expansion of (1 + X)^N.

    This implementation uses a recurrence relation along with a dynamic programming
    approach to calculate the binomial coefficient C(N, K).

    Time complexity
    ---------------
    O(N * K), where N and K are as mentioned above.

    Space complexity
    ----------------
    O(N * K), where N and K are as mentioned above.
*/

#ifndef BINOMIAL_COEFFICIENT_HPP
#define BINOMIAL_COEFFICIENT_HPP

#include <vector>

using std::vector;

typedef unsigned long long ULL;

const ULL EMPTY = 0;

/*
    calc_binomial_coefficient
    ---------------------------
    Uses the recurrence relation,
        C(n, k) = C(n - 1, k) + C(n - 1, k - 1),
    and a dynamic programming approach to find the binomial coefficient C(n, k).

    Return value
    ------------
    C(n, k) modulo 2^64. (Due to limited range of ULL).

    Time complexity
    ---------------
    O(n * k).

    Space complexity
    ----------------
    O(1).
*/

ULL calc_binomial_coefficient(int n, int k, vector<vector<ULL>>& cache) {
    // check if value has already been calculated
    if (cache[n][k] != EMPTY) {
        return cache[n][k];
    }

    ULL result;
    if (n == k or k == 0) {
        result = 1;
    } else {
        result = calc_binomial_coefficient(n - 1, k, cache) + calc_binomial_coefficient(n - 1, k - 1, cache);
    }

    // result is stored in cache so that it isn't re-calculated when needed again
    cache[n][k] = result;
    return result;
}


/*
    binomial_coefficient
    --------------------
    Creates a cache that is used by calc_binomial_coefficient to memoize the calculated
    coefficients, and returns the value of C(n, k).

    Return value
    ------------
    C(n, k) modulo 2^64. (Due to limited range of ULL).

    Time complexity
    ---------------
    O(n * k).

    Space complexity
    ----------------
    O(n * k).
*/

ULL binomial_coefficient(int n, int k) {
    if (n < k) {
        return 0;   // no subsets of size k are possible
    }

    vector<vector<ULL>> cache;
    cache.resize(n + 1);

    // initialise all values in cache as EMPTY
    for (int i = 0; i <= n; i++) {
        cache[i].resize(k + 1, EMPTY);
    }

    return calc_binomial_coefficient(n, k, cache);
}

# endif // BINOMIAL_COEFFICIENT_HPP
