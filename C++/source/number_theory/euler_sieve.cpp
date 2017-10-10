/*
    Euler's Sieve
    ---------------------
    Given a number N, find all prime numbers upto N (inclusive) using the simple
    Sieve of Euler's Sieve , which efficiently finds primes in the order of
    10^7. (The efficiency limit is due to poor cache utilisation.)

    Time complexity
    ---------------
    O(N), where N is the number upto which primes have to be found

    Space complexity
    ----------------
    O(N), where N is the number upto which primes have to be found
*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> eulerSieve(const unsigned int &primeLimit, vector<int> & primeSheet)
{
  vector<bool> isPrime(primeLimit + 1, true);
  primeSheet.clear();
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= primeLimit; i++)
  {
    if (isPrime[i])
    {
      primeSheet.push_back(i);
    }
    for (int j = 0; j < primeSheet.size() && primeSheet[j] * i <= primeLimit; j++)
    {
      isPrime[i * primeSheet[j]] = false;
      if (i % primeSheet[j] == 0) break;
    }
  }
  return isPrime;
}

//more simple version if you don't need the list of primes
vector<bool> eulerSieve(const unsigned int &primeLimit)
{
  vector<bool> isPrime(primeLimit + 1, true);
  vector<int> primeSheet;
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= primeLimit; i++)
  {
    if (isPrime[i])
    {
      primeSheet.push_back(i);
    }
    for (int j = 0; j < primeSheet.size() && primeSheet[j] * i <= primeLimit; j++)
    {
      isPrime[i * primeSheet[j]] = false;
      if (i % primeSheet[j] == 0) break;
    }
  }
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

    const vector<bool> markedPrimes = eulerSieve(primeLimit);

    cout << "\nAll prime numbers upto " << primeLimit << " (inclusive) are:\n";
    printPrimes(markedPrimes);

    return 0;
}
