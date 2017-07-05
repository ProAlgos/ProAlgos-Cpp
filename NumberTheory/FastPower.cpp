/*
<Fast Power>
--------------
Fast Power is an optimized algorithm to compute exponentiation in a short time.


Time Complexity
-----------------
O(log(N)) where N is the power the number is raised to.

Space Complexity
------------------
O(log(N)) where N is the power the number is raised to.

*/
#include <iostream>

using namespace std;
typedef long long ll;

//Function that returns x raised to the power of y
ll fastPower (ll x,ll y)
{
    if (y==0) return 1;

    if (y%2==1)
    {
        return fastPower(x,y-1) * x;
    }
    else
    {
        x = fastPower(x,y/2);
        return (x*x);
    }
}

//Testing the function
int main()
{
    int base,power;
    cout<<"Enter the number and the power it's raised to:"<<endl;

    cin>>base>>power;

    cout<<fastPower(base,power);
    return 0;
}
