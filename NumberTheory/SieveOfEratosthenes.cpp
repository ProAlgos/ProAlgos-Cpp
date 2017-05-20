/*
    Prime numbers:
    Given a number N, find all prime numbers upto N ( N included )
    (Prime Number is a number that is divisible only by itself and 1 (e.g. 2, 3, 5..))

    Time complexity = O(nloglogn)
    Space complexity = O(n)

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieveOfEratosthenes(const int &prime_limit) {
    
    vector<bool> primes(prime_limit+1);
    vector<int> result;
    
    for(int i = 0;i<=prime_limit;i++)
        primes[i] = 1;
    
    primes[0] = 0;
    primes[1] = 0;
    
    for(int i = 2;i<=sqrt(prime_limit);i++)
    {
        if(primes[i])
        {
            for(int j = 2;i*j<=prime_limit;j++)
                primes[i*j] = 0;
        }
    }
    
    for(int i = 2;i<primes.size();i++)
    {
        if(primes[i])
            result.push_back(i);
    }
    
    return result;
}

void printPrimes(const vector<int> &primes)
{
    int length = primes.size();
    for(int i = 0;i<length;i++)
        cout << primes[i] << "\n";
}

void getInput(int &prime_limit)
{
    cout << "Enter N to print all prime number upto N ";
    cin >> prime_limit;
    if (prime_limit <= 1) {
        cout << "Invalid value! (prime_limit should be >= 2). \n";
        getInput(prime_limit);
    }
}

int main()
{
    int prime_limit;
    getInput(prime_limit);
    
    vector<int> primes = sieveOfEratosthenes(prime_limit);
    printPrimes(primes);

    return 0;
}