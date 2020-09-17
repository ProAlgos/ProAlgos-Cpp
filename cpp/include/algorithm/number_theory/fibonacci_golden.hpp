/*
    Fibonacci using golden ratio
    ----------------
    Find the N-th Fibonacci number, given the value of N. The Fibonacci
    sequence is characterized by the fact that every number after the
    first two is the sum of the two preceding ones.

    It uses the fact that the round off value of the next fibonacci number
    is f_(n+1) = f_(n)*(phi) where phi is golden ratio.


    Time complexity
    ---------------
    O(log N), where N is the term of the Fibonacci sequence to calculate.

    Space complexity
    ----------------
    O(1).

*/

#ifndef FIBONACCI_GOLDEN_HPP
#define FIBONACCI_GOLDEN_HPP

#include <cmath>
typedef long long int ULL;

const int MAX_N = 64; // fibonacci(64) cannot be calculated due to limitation of precision of computers for irrational number phi (GOLDEN RATIO)
const long double phi = 1.618033988749894;
// the underscores in the function name is to prevent accidental clash of function names with the code that includes this file/code.
/**
 * 
 * Modular exponentiation function uses divide and conquer technique to evaluate a^b % c expression
 * in O(log(b)) time instead of naive complexity of O(b).
 * 
 * */
long double ___modularExponentiation_____(const int ex)
{
    int n = ex, exp = ex;
    long double ans = 1, a = phi;
    while (exp)
    {
        if (exp & 1)
        {
            ans *= a;
        }
        a *= a;
        exp >>= 1;
    }
    if (n % 2 == 0)
    {
        return sqrt(0.2) * (ans - 1 / (ans));
    }
    else
    {
        return sqrt(0.2) * (ans + 1 / ans);
    }
}

ULL fibonacci(const int n)
{
    if (n > MAX_N)
        return -1;
    else if (n == 0 || n == 1)
    {
        return n;
    }
    else if (n == 2 || n == 3)
    {
        return n - 1;
    }
    else
    {
        return round(___modularExponentiation_____(n));
    }
}

#endif // FIBONACCI_GOLDEN_HPP
