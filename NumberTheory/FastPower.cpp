/*
    Fast Power
    ----------------
    Fast Power is an optimized algorithm to compute exponentiation in a short time.
    It calculates the power by squaring, meaning we divide the power by 2 on each step and multiply
    the base by itself. We keep doing this until the power is 0 where we return 1.


    Time Complexity
    -----------------
    O(log(N)) where N is the exponent.

    Space Complexity
    -----------------
    O(log(N)) where N is the exponent.

*/
#include <iostream>

using namespace std;
typedef unsigned long long ull;

//Function that returns base raised to the exponent
ull fast_power (ull base,ull exponent)
{
    if (exponent==0) return 1;

    if (exponent%2==1)  //If the power is odd
    {
        return fast_power(base,exponent-1) * base;
    }
    else    //If the power is even
    {
        base = fast_power(base,exponent/2);
        return (base*base);
    }
}

#ifndef FAST_POWER_TEST

int main()
{
    //Testing the function
    int base,exponent;
    cout<<"Enter the number and its exponent:"<<endl;

    cin>>base>>exponent;

    cout<<endl<<fast_power(base,exponent)<<endl;
   
    return 0;
}

#endif
