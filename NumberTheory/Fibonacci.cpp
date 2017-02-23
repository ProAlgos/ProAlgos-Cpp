/*
    Fibonacci number:
    Find the N-th Fibonacci number, given the value of N.
    (The Fibonacci sequence is characterized by the fact that every number
    after the first two is the sum of the two preceding ones.)

    Time complexity:
    O(N), where N is the term of the Fibonacci sequence to calculate

    Space complexity:
    O(1)
*/

#include <iostream>

using namespace std;

typedef unsigned long long int ULL;

const int MAX_N = 93;   // fibonacci(94) goes beyond the range of ULL
ULL fibonacci(const ULL n,ULL &previous)
{
	//previous is F(n-1) and previousToPrevious is F(n-2)
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
    cout << "Enter the value for N (max. " << MAX_N << ") : ";
    cin >> N;

    if (N < 0 or N > MAX_N) {
        cout << "Invalid value! N should be between 0 and " << MAX_N << ".\n";
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
