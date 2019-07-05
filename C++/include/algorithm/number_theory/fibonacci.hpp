/*
    Fibonacci number
    -----------------
    Find the N-th Fibonacci number, given the value of N. The Fibonacci
    sequence is characterized by the fact that every number after the
    first two is the sum of the two preceding ones.

    Time complexity
    ---------------
    O(N), where N is the term of the Fibonacci sequence to calculate.

    Space complexity
    ----------------
    O(1).
*/

#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

typedef unsigned long long int ULL;

const int MAX_N = 93;   // fibonacci(94) goes beyond the range of ULL


ULL fibonacci(const int n) {
    if (n > MAX_N)
        return -1;
    if (n == 0 or n == 1)
        return n;   // since F(0) = 0, and F(1) = 1

    ULL previous_to_previous = 0;     // first term, or F(n-2) in general
    ULL previous = 1;   // second term, or F(n-1) in general
    ULL fn;     // F(n)
    for (int term = 2; term <= n; term++) {
        fn = previous + previous_to_previous;   // F(n) = F(n-1) + F(n-2)
        previous_to_previous = previous;  // F(n-1) becomes F(n-2) in the next step
        previous = fn;    // F(n) becomes F(n-1) in the next step
    }

    return fn;
}

#endif // FIBONACCI_HPP
