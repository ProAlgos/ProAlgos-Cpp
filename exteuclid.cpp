#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include <ctime> 
 

using namespace std;


long long int gcd(long long int a,long long int b)
{
	if(a==0)
	return b;

	else
	return gcd(b%a,a);
}


void euclid(long long int p, long long int q, long long int *x,long long int *y) 
{ 
    
	if (p == 0) 
	{	 
		*x=0; 
		*y=1; 
		return ; 
	} 
  
	long long int x1, y1;
	euclid(q%p, p, &x1, &y1); 
   
	*x=y1-(q/p)*x1; 
	*y=x1; 
  
	return; 
}

int main()
{
	long long int a,b,x1=1,y1=1;
	cin>>a>>b;
	
	if(gcd(a,b)==1)
	
		euclid(a,b,&x1,&y1);

	while(x1<0)
		{
			x1+=b;
		}

	cout<<"modular inverse of "<<a<<" wrt to "<<b<<" = "<<x1;
}
