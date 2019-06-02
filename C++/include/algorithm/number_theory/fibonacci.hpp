/*
    Fibonacci number
    -----------------
    Find the N-th Fibonacci number, given the value of N. The Fibonacci
    sequence is characterized by the fact that every number after the
    first two is the sum of the two preceding ones.

    Time complexity
    ---------------
    O(N), where N is the term of the Fibonacci sequence to calculate

    Space complexity
    ----------------
    O(1).
*/

typedef unsigned long long int ULL;

const int MAX_N = 93;   // fibonacci(94) goes beyond the range of ULL

ULL fibonacci(const int n) {

	if (n > MAX_N)
	{
		return -1;
	}

	ULL previousToPrevious = 0;     // first term, or F(n-2) in general
	ULL previous = 1;   // second term, or F(n-1) in general
	ULL fibo;   // F(n)

	if (n == 0 or n == 1)
		return n;   // since F(0) = 0, and F(1) = 1

	for (int term = 2; term <= n; term++) {
		fibo = previous + previousToPrevious;   // F(n) = F(n-1) + F(n-2)

		previousToPrevious = previous;  // F(n-1) becomes F(n-2) in the next step
		previous = fibo;    // F(n) becomes F(n-1) in the next step
	}

	return fibo;
}
