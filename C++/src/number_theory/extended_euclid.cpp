/*
    Extended Euclidean algorithm
    ----------------------------
    Given two non-negative numbers A and B as inputs, find M[0], M[1] such that:
    gcd(A, B) = M[0]*B + M[1]*B

    Time complexity
    ---------------
    O(log(K)), where K = min(A, B) is the smaller of the input integers A and B

    Space complexity
    ----------------
    O(1).
*/

#include <iostream>
#include <array>

using namespace std;

/*
    extended_euclidean
    ------------------
    Uses the recurrence relation,
        GCD(a, b) = GCD(b, a%b),
    to find coefficients M[0] and M[1] such that
        GCD(a, b) = M[0]*a + M[1]*b

    Return value
    ------------
    array<int,2> M of length 2 which satisfies the equation above

    Time complexity
    ---------------
    O(log(K)), where K = min(A, B) is the smaller of the input integers A and B

    Space complexity
    ----------------
    O(1).

*/

array<int, 2> extended_euclidean(int a, int b) {
    //loop invariant: gcd(a,b) is the same at the end of each iteration
    //a = aM[0]*(original value of a) + aM[1]*(original value of b)
    //the above statement holds for b and bM as well
    array<int, 2> aM = {{1, 0}};
    array<int, 2> bM = {{0, 1}};
    while (b != 0) {
        aM[0] -= (a/b) * bM[0];
        aM[1] -= (a/b) * bM[1];

        aM.swap(bM);

        int newA = b;
        b = a % b;
        a = newA;

    }
    return aM;
}


/*
    get_positive_int
    ----------------
    Gets a positive integer as input from the user for a variable, giving it a
    name as specified.
*/

void get_positive_int(int& var, const string& var_name) {
    do {
        cout << "Enter the value for " << var_name << " : ";
        cin >> var;

        if (var < 0)
            cout << "Invalid value! " << var_name << " should be greater than 0.\n";
    } while (var < 0);
}

int main() {
    int a, b;
    get_positive_int(a, "a");
    get_positive_int(b, "b");

    array<int, 2> M = extended_euclidean(a, b);
    int gcd = M[0] * a + M[1] * b;
    cout << "gcd(" << a << "," << b << ") = " << M[0] << "*" << a << " + " << M[1] << "*" << b;
    cout << " = " << gcd <<"\n";

    return 0;
}
