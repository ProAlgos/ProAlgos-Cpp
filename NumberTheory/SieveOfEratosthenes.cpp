/*
    Prime numbers:
    Given a number N, find all prime numbers upto N ( N included )
    (Prime Number is a number that is divisible only by itself and 1 (e.g. 2, 3, 5..))
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieveOfEratosthenes(int A) {
    
    vector<bool> primes(A+1);
    vector<int> result;
    
    for(int i = 0;i<=A;i++)
        primes[i] = 1;
    
    primes[0] = 0;
    primes[1] = 0;
    
    for(int i = 2;i<=sqrt(A);i++)
    {
        if(primes[i])
        {
            for(int j = 2;i*j<=A;j++)
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

void printPrimes(vector<int> &primes)
{
	int length = primes.size();
	for(int i = 0;i<length;i++)
		cout << primes[i] << "\n";
}

void getInput(int &N)
{
    cout << "Enter N to print all prime number upto N ";
    cin >> N;
    if (N <= 1) {
        cout << "Invalid value! (N should be >= 2). \n";
        getInput(N);
    }
}

int main()
{
	int N;
	getInput(N);
	
	vector<int> primes = sieveOfEratosthenes(N);
	printPrimes(primes);

	return 0;
}