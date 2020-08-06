/*
    Fibonacci number
    -----------------
    Find the N-th Fibonacci number, given the value of N. The Fibonacci
    sequence is characterized by the fact that every number after the
    first two is the sum of the two preceding ones.

    It uses the fact that the round off value of the next fibonacci number
    is f_(n+1) = f_(n)*(phi) where phi is golden ratio


    Time complexity
    ---------------
    O(log N), where N is the term of the Fibonacci sequence to calculate.

    Space complexity
    ----------------
    O(1).
*/

#ifndef FIBONACCI_FAST_HPP
#define FIBONACCI_FAST_HPP

#include <cmath>
typedef unsigned long long int ULL;

const int MAX_N = 64; // fibonacci(64) cannot be calculated due to limitation of precision of computers for irrational number phi (GOLDEN RATIO)
const long double phi = 1.618033988749894;


long double ___modExp_____(const int ex) // Name is unconventional to prevent accidental clash with a function name in implementing class
{
    int n=ex, exp=ex;
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
    if (n%2==0) {
        return sqrt(0.2)*(ans-1/(ans));
    }
    else
    {
        return sqrt(0.2)*(ans+1/ans);
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
        return round(___modExp_____(n - 2));
    }

}

#endif // FIBONACCI_FAST_HPP

