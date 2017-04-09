// C program to demonstrate Basic Euclidean Algorithm
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
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    return 0;
}
