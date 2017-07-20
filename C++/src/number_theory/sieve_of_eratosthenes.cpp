/*
    Sieve of Eratosthenes
    ---------------------
    Given a number N, find all prime numbers upto N (inclusive) using the simple
    Sieve of Eratosthenes method, which efficiently finds primes in the order of
    10^7. (The efficiency limit is due to poor cache utilisation.)

    Time complexity
    ---------------
    O(N * log(log(N))), where N is the number upto which primes have to be found

    Space complexity
    ----------------
    O(N), where N is the number upto which primes have to be found
*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> simpleSieve(const unsigned int &primeLimit) {
    vector<bool> isPrime(primeLimit + 1, true);   // "sieve" to mark numbers as prime

    isPrime[0] = isPrime[1] = false;

    unsigned int multiple;
    for (unsigned int num = 2; num <= sqrt(primeLimit); num++)
        if (isPrime[num])   // if the number is prime
            for (multiple = num * num; multiple <= primeLimit; multiple += num)
                isPrime[multiple] = false;  // mark its multiples as not prime

    return isPrime;
}

void printPrimes(const vector<bool> &markedPrimes) {
    for (unsigned int num = 2; num < markedPrimes.size(); num++)
        if (markedPrimes[num])  // if number is marked as prime
            cout << num << "\n";
}

void getPrimeLimit(unsigned int &primeLimit)
{
    cout << "Enter the number upto which primes are to be found : ";
    cin >> primeLimit;

    if ((int) primeLimit < 0) {
        cout << "Prime limit should be a positive integer! Try again.\n";
        getPrimeLimit(primeLimit);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);   // don't sync C++ streams with C streams

    unsigned int primeLimit;
    getPrimeLimit(primeLimit);

    const vector<bool> markedPrimes = simpleSieve(primeLimit);

    cout << "\nAll prime numbers upto " << primeLimit << " (inclusive) are:\n";
    printPrimes(markedPrimes);

    return 0;
}
