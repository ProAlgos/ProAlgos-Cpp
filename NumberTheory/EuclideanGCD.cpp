#include <iostream>

using namespace std;
/*
    Greatest Common Divisor:
    Given 2 numbers ,say a and b, find GCD(a,b)
    GCD(a,b) is the maximum factor that is common to 'a' and 'b'
    Time complexity = O(log(min(a,b)))
    Space complexity = O(1)
*/

int euclidGCD(int &a,int &b)
{
    while(a != 0)
    {
        int remainder = b % a;
        b = a;
        a = remainder;
    }
    return b;   
}

void getInput(int &a,int &b)
{
    cout << "GCD of two numbers 'a' and 'b'\n";
    cout << "Enter a ";
    cin >> a;
    cout << "Enter b ";
    cin >> b;
    if (a < 0) {
        cout << "Invalid value! (a should be >= 0). \n";
        getInput(a,b);
    }
    if(b < 0){
        cout << "Invalid value! (b should be >= 0). \n";
        getInput(a,b);
    }
}

void printGCD(const int &gcd,const int &a,const int &b)
{
    cout << "GCD of " << a << " and " << b << " is " << gcd << ".\n";
}

int main()
{
    int a,b;
    getInput(a,b);
    
    int gcd = euclidGCD(a,b);
    printGCD(gcd,a,b);
    return 0;
}
