/*
    Primorial
    ---------
    Calculate the primorial Pn# for the prime number definition of primorial 
    and n# for the natural number definition of primorial.
    Pn# is defined as the product of the first n primes.
    n# is defined as the product of all primes less than or equal to n.

    Time complexity
    ---------------
    O(N^2) where N is n for the natural definition and Pn for the prime 
    definition.

    Space complexity
    ----------------
    O(N) where N is n for the natural definition and Pn for the prime 
    definition.
*/

#ifndef PRIMORIAL_HPP
#define PRIMORIAL_HPP

#include <climits>
#include <vector>

typedef unsigned long long int ULL;

// primorial_natural(n) goes beyond the range of ULL where n > 52
const unsigned int MAX_N_NATURAL = 52;

// primorial(n) goes beyond the range of ULL where n > 15
const unsigned int MAX_N = 15;

// Computes the primorial defined by natural numbers: https://oeis.org/A034386
// Returns 0 if n# is too big to fit in an ULL
// Otherwise returns the primorial n#, where n# = the product of all primes ≤ n
ULL primorial_natural(unsigned int n) {
    // Check for unsigned integer wraparound
    if (n > MAX_N_NATURAL) {
        return 0;
    }

    std::vector<unsigned int> primes;
    
    ULL product = 1;

    for (unsigned int i = 2; i <= n; i++) {
        bool is_prime = true;
        for (auto it = primes.begin(); is_prime && it != primes.end(); it++) {
            if (i % *it == 0) {
                is_prime = false;
            }
        }
        if (is_prime) {
            product *= i;
            primes.push_back(i);
        }
    }

    return product;
}

// Computes the primorial defined by prime numbers: https://oeis.org/A002110
// Returns 0 if Pn# is too big to fit in an ULL
// Otherwise returns the primorial Pn#, where Pn# = the product of the first n primes
ULL primorial(unsigned int n) {
    // Check for unsigned integer wraparound
    if (n > MAX_N) {
        return 0;
    }

    std::vector<unsigned int> primes;

    ULL product = 1;

    for (unsigned int i = 2; primes.size() < n; i++) {
        bool is_prime = true;
        for (auto it = primes.begin(); is_prime && it != primes.end(); it++) {
            if (i % *it == 0) {
                is_prime = false;
            }
        }
        if (is_prime) {
            product *= i;
            primes.push_back(i);
        }
    }

    return product;
}

#endif // PRIMORIAL_HPP
