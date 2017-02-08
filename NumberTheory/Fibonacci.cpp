/*
    Fibonacci number:
    Find the N-th Fibonacci number, given the value of N.
    (The Fibonacci sequence is characterized by the fact that every number
    after the first two is the sum of the two preceding ones.)
*/

#include <iostream>
#include <assert.h>

using namespace std;

typedef unsigned long long int ULL;

/* fibonacci recursive
 * time complexity O(n) space complexity O(1)
 * tested for input size < 10^5
 */
ULL fibonacci(const ULL n,ULL &previous)
{
	//previous is F(n-1) and previousToPrevious is F(n-2)
	assert(n>=0);
    if(n==0)
    {
        previous=1;
        return 0;
    }
    else if(n==1)
    {
        previous=0;
        return 1;
    }
    else
    {
        ULL previousToPrevious;
        previous = fibonacci(n-1, previousToPrevious);
        return previous + previousToPrevious;
    }
}

void getN(int &N) {
    cout << "Enter the value for N : ";
    cin >> N;

    if (N < 0) {
        cout << "Invalid value! N should not be less than 0.\n";
        getN(N);
    }
}

int main()
{
    int N;
    ULL previous;
    getN(N);

    cout << "\nFibonacci(" << N << ") = " << fibonacci(N, previous) << "\n";

    return 0;
}
