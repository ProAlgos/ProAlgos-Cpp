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

// primorial_natural(n) where n > 52 goes beyond the range of ULL
const unsigned int MAX_N_NATURAL = 52;

// primorial(n) where n > 15 goes beyond the range of ULL
const unsigned int MAX_N = 15;

// computes the primorial defined by natural numbers: https://oeis.org/A034386
// returns 0 if n# is too big to fit in an ULL.
// returns the primorial n# otherwise
ULL primorial_natural(unsigned int n) {
    // check for unsigned integer wraparound
    if (n > MAX_N_NATURAL) {
        return 0;
    }

    std::vector<unsigned int> primes;
    
    ULL product = 1;

    for (unsigned int i = 2; i <= n; i++) {
        bool is_prime = true;
        for (std::vector<unsigned int>::iterator it = primes.begin(); is_prime
            && it != primes.end(); it++) {
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

// computes the primorial defined by prime numbers: https://oeis.org/A002110
// returns 0 if Pn# is too big to fit in an ULL. 
// returns the primorial Pn# otherwise
ULL primorial(unsigned int n) {
    // check for unsigned integer wraparound
    if (n > MAX_N) {
        return 0;
    }

    std::vector<unsigned int> primes;

    ULL product = 1;

    for (unsigned int i = 2; primes.size() < n; i++) {
        bool is_prime = true;
        for (std::vector<unsigned int>::iterator it = primes.begin(); is_prime
            && it != primes.end(); it++) {
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
