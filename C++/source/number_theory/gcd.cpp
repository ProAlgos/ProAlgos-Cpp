/*
    Euclid's GCD algorithm
    ----------------------
    Basic Euclidean Algorithm is used to find GCD of two numbers say a and b. 
    The Euclidean algorithm is based on the principle that the greatest common divisor
    of two numbers does not change if the larger number is replaced by its difference with
    the smaller number.
    Below is a recursive C++ function to evaluate gcd using Euclid’s algorithm.
    
    Time complexity
    ---------------
    O(log10(M)), where M = min(A, B) is the smaller of the input integers A and B
    
    Space complexity
    ----------------
    O(1)
*/

#include <iostream>
using namespace std;

// Function to return gcd of a and b
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

// Driver program to test above function
int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    return 0;
}
