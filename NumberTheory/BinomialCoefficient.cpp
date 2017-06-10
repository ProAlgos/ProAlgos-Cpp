/*
    Binomial Coefficient:
    For a set containing N unique elements, find the number of subsets
    containing K elements (aka N choose K)

    This approach uses the following recurrence:
    B(n, k) = B(n-1, k) + B(n-1, k-1)
    and a dynamic programming approach to memoize values computed between calls

    Time complexity:
    O(N*K)

    Space complexity:
    O(N*K)
*/

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ULL;

const ULL FLAG = 0;

//uses recurrence relation and fills cache to find binomial coefficient of N & K
ULL BinomialCoefficientHelper(int N, int K, vector<vector<ULL>> &cache)
{
    //recursive invariant: cache[N][K] either contains the correct value or FLAG
    if(cache[N][K]!= FLAG)
        return cache[N][K];

    ULL result;//will contain the value to be returned

    if((K == N) or (K == 0)) {
        result = 1;
    }

    else {
        result = BinomialCoefficientHelper(N - 1, K, cache) + BinomialCoefficientHelper(N - 1,K - 1,cache);
    }

    //result now contains the binomial coefficient of N & K
    //It is stored in the cache so it doesn't need to be recomputed if needed again
    cache[N][K] = result;
    return result;
}

ULL BinomialCoefficient(int N, int K)
{
    if(N < K)//if N<K, there exist no subsets with size K
        return 0;

    vector<vector<ULL>> cache;//2d cache vector will be used to memoize values between calls
    cache.resize(N + 1);

    for(int i = 0; i <= N; i++)//cache[i][j] is initialized to FLAG value (0) at start
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
