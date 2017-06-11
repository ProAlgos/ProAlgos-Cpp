/*
    Extended Euclidean Algorithm:
    Given two non-negative numbers a & b as inputs, find M[0], M[1] such that

    gcd(a, b) = M[0]*a + M[1]*b

    This algorithm has a variety of uses - in particular, it can be used to
    quickly compute multiplicative inverses in finite fields, as is often
    needed for cryptographic algorithms

    Time Complexity:
    O(log10(K)), where K = min(A, B) is the smaller of the input integers A and B

    Space Complexity:
    O(1)   
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> extendedEuclid(int a, int b)
{
    //loop invariant: gcd(a,b) is the same at the end of each iteration
    //a = aM[0]*(original value of a) + aM[1]*(original value of b)
    //the above statement holds for b and bM as well

    vector<int> aM = {1,0};
    vector<int> bM = {0,1};
    while(b!=0)
    {
        aM[0] -= (a/b)*bM[0];
        aM[1] -= (a/b)*bM[1];

        aM.swap(bM);

        int newA = b;
        b = a%b;
        a = newA;

    }
    return aM;
}
void getInputs(int &a, int &b)
{
    a = -1;
    b = -1;
    while(a < 0)
    {
        cout << "Enter a non-negative value for 'a'\n";
        cin >> a;
    }

    while(b < 0)
    {
        cout << "Enter a non-negative value for 'b'\n";
        cin >> b;
    }
}

#ifndef TEST
int main()
{

    int a;
    int b;
    getInputs(a,b);

    vector<int> M = extendedEuclid(a,b);
    int gcd = M[0] * a + M[1] * b;
    cout << "gcd(" << a << "," << b << ") = " << M[0] << "*" << a << " + " << M[1] << "*" << b;
    cout << " = " << gcd <<"\n";

    return 0;
}
#endif
