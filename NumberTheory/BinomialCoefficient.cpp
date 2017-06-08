/*
    Binomial Coefficient:
    For a set containing N unique elements, find the number of subsets containing K elements (aka N choose K)
    This approach uses the recurrence BinomialCoefficient(N,K) = BinomialCoefficient(N-1,K) + BinomialCoefficient(N-1,K-1),
    and a dynamic programming approach to memoize (save) BinomialCoefficient values computed between calls

    Time complexity:
    O(N*K) - cache[i][j] will be computed exactly once for each i<=N and j<=K

    Space complexity:
    O(N*K) due to memoization (due to the 'cache' variable), and O(N) stack space (due to recursion)
*/

#include <iostream>
#include <vector>
using namespace std;

const int FLAG = -1;

int BinomialCoefficientHelper(int N, int K, vector<vector<int> > cache)//uses recurrence relation and fills cache to find binomial coefficient of N & K
{
    //recursive invariant: cache[N][K] either contains binomial coefficient of N & K or FLAG (-1) (it is impossible for a binomial coefficient to be negative)
    if(cache[N][K]!= FLAG)
        return cache[N][K];

    int out;//will contain the value to be returned

    if((K == N) or (K == 0)) {
        out = 1;
    }

    else {
        out = BinomialCoefficientHelper(N - 1, K, cache) + BinomialCoefficientHelper(N-1,K-1,cache);
    }
    //out now contains the binomial coefficient of N & K

    cache[N][K] = out;//out is stored in the cache so it doesn't need to be recomputed if needed again
    return out;
}

int BinomialCoefficient(int N, int K)
{
    vector< vector<int> > cache;//2d cache vector will be used to memoize BinomialCoefficient values between calls
    cache.resize(N + 1);

    for(int i = 0; i < (N + 1); i++)//cache[i][j] is initialized to FLAG value (-1) at start
        cache[i].resize(K + 1, FLAG);

    return BinomialCoefficientHelper(N, K, cache);
}

void getInput(int &n, int &k) {
    cout << "Enter the value for N: ";
    cin >> n;

    while (n < 0) {
        cout << "Invalid value! N should be greater than 0.\n";
        cout << "Enter the value for N: ";
        cin >> n;

    }

    cout << "Enter the value for K: ";
    cin >> k;

    while (k < 0) {
        cout << "Invalid value! K should be greater than 0.\n";
        cout << "Enter the value for K: ";
        cin >> k;
    }
}

#ifndef TEST
int main() {
    int n;
    int k;
    getInput(n,k);

    cout << "\nBinomialCoefficient(" << n << ", "<< k << ") = " << BinomialCoefficient(n,k) << "\n";

    return 0;
}
#endif
