/*
    Sieve of Eratosthenes
    ---------------------
    Given a number N, find all prime numbers up to N (inclusive) using the simple
    Sieve of Eratosthenes method, which efficiently finds primes in the order of
    10^7. (The efficiency limit is due to poor cache utilisation.)

    Time complexity
    ---------------
    O(N * log(log(N))), where N is the number up to which primes have to be found

    Space complexity
    ----------------
    O(N), where N is the number up to which primes have to be found
*/

#ifndef SIEVE_OF_ERATOSTHENES_HPP
#define SIEVE_OF_ERATOSTHENES_HPP

#include <cmath>
#include <vector>

using std::vector;

// Determines primes up to primeLimit and returns list of primes in a vector
vector<int> getPrimes(const unsigned int &primeLimit) {
    //  Check if larger than limit
    if (primeLimit > 10000000) {
        return vector<int>({});
    }

    vector<bool> boolPrimes(primeLimit + 1, true);   // "sieve" to mark numbers as prime

    boolPrimes[0] = boolPrimes[1] = false;

    // Determine primes
    unsigned int multiple;
    for (unsigned int num = 2; num <= sqrt(primeLimit); num++) {
        // check if the number is prime
        if (boolPrimes[num]) {
            for (multiple = num * num; multiple <= primeLimit; multiple += num)
            {
                boolPrimes[multiple] = false;    // mark its multiples as not prime
            }
        }
    }

    // Create output vector
    vector<int> primes;
    for (unsigned int num = 2; num < boolPrimes.size(); num++) {
        if (boolPrimes[num]) {
            primes.push_back(num);
        }
    }

    return primes;
}

#endif // SIEVE_OF_ERATOSTHENES_HPP
