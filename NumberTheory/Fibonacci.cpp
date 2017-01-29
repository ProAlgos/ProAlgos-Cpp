/*
    Fibonacci number:
    Find the N-th Fibonacci number, given the value of N.
    (The Fibonacci sequence is characterized by the fact that every number
    after the first two is the sum of the two preceding ones.)
*/

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int ULL;

const int MAX_N = 93;   // fibonacci(94) goes beyond the range of ULL

ULL fibonacci(const int &N, vector<ULL> &fiboMemo) {
    if (N == 0 or N == 1)
        fiboMemo[N] = N;
    else if (!fiboMemo[N]) {
        fiboMemo[N] = fibonacci(N - 1, fiboMemo) + fibonacci(N - 2, fiboMemo);
    }

    return fiboMemo[N];
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
    getN(N);

    vector<ULL> fiboMemo(N + 1, 0);

    cout << "\nFibonacci(" << N << ") = " << fibonacci(N, fiboMemo) << "\n";

    return 0;
}
