#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include <ctime> 
 

using namespace std;


int gcd(int a,int b)
{
	if(a==0)
	return b;

	else
	return gcd(b%a,a);
}


int main()
{
	int a,b;
	cin>>a>>b;
	cout<<"GCD of "<<a<<" and "<<b<<" = "<<gcd(a,b);
}
