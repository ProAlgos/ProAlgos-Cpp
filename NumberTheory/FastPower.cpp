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


int main()
{
    //Testing the function
    int base,exponent;
    cout<<"Enter the number and its exponent:"<<endl;

    cin>>base>>exponent;

    cout<<endl<<fast_power(base,exponent)<<endl;
    
    //Sample Tests
    TEST_CASE("Base cases", "[fast_power]") {
        REQUIRE(fast_power(2,2) == 4);
        REQUIRE(fast_power(2,4) == 16);
}

    TEST_CASE("Normal cases", "[fast_power]") {
        REQUIRE(fast_power(3,4) == 81);
        REQUIRE(fast_power(7,9) == 40353607);
        REQUIRE(fast_power(15,10) == 576650390625);
}

    TEST_CASE("Overflow cases", "[fast_power]") {
        REQUIRE(fast_power(2,100) == 0);
        REQUIRE(fast_power(10,99) == 0);
}
    return 0;
}
