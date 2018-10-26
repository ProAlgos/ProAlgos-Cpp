#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include <ctime> 
 

using namespace std;



long long int sqmul(long long int c, long long int e,long long int p)
{
	int ar[100]={0},i=0,j=0;
	long long int p2=e;
	long long int res=1,res2=0;
	while(p2>0)
	{
		ar[i++]=p2%2;
		p2/=2;
		
	}

	j=0;
	
	res2=c%p;
	

	while(j<i)
	{
		if(ar[j])		
		{
			res*=res2;
		}
			
		res%=p;
		
		res2=(res2*res2)%p;
		
		j++;	
	}

	return res;
} 
 


int main()
{
	long long int c1,e1,p1;
	cin>>c1>>e1>>p1;
	cout<<c1<<" to the power "<<e1<<" mod "<<p1<<": "<<sqmul(c1,e1,p1);
}
