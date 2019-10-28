/*

Euler's Totient Function
-------------------------------------------------------------

For a given number N, Euler's Totient Function is equal to 
the number of numbers which are relatively prime to N,
i.e. gcd(m,n)=1 for 1<=m<=n

Implementation : Simple for-loop from 2 to n-1 
while calculating the GCD using the Euclidean Algorithm

Time Complexity : O( log(N-1)! ) where ! denotes factorial

Space Complexity : O(1)
--------------------------------------------------------------
*/

#ifndef EULER_TOTIENT_HPP
#define EULER_TOTIENT_HPP

#include<iostream>
using namespace std;
typedef unsigned long long int ll;

//Recursive GCD function implementing Euclidean Algorithm
ll gcd(ll a,ll b)
{
	if(b==0)
	return a;
	else
	gcd(b,a%b);
}

ll eulertot(ll n)
{
	ll c=1;
	for(ll i=2;i<n;i++)
		if(gcd(n,i)==1)
			c+=1;
	return c;
}

#endif 
