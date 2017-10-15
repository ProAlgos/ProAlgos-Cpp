/*
	Fibonacci Search
	_________________

	Find the position of an element X, given an sorted array "arr".
	The inputs are :
		- N : size of the array.
		- N elements of the array.
		- X : element we want to find.

	Time complexity
	_______________
	
	O(log(N))

	Space complexity
	________________

	O(N)
*/

#include <iostream>
#include <math.h>

using namespace std;

typedef int type;

int fibonacci_search(type* arr,int n ,int x)
{
    int fib2=0;
    int fib1=1;
    int fib=fib2+fib1;
 
    while(fib<n)
    {
        fib2=fib1;
        fib1=fib;
        fib=fib2+fib1;
    }
 
    int offset=-1;
 
    while(fib>1)
    {
        int i=min(offset+2,n-1);
 
        if(arr[i]<x)
        {
            fib=fib1;
            fib1=fib2;
            fib2=fib-fib1;
            offset=i;
        }
 		else if (arr[i]>x)
        {
            fib=fib2;
            fib1=fib1-fib2;
            fib2=fib-fib1;
        }
		else
 			return i;
    }
 
    if(fib1 && arr[offset+1]==x)
		return offset+1;
 
    return -1;
}

int main(void)
{
    int n;
	cin>>n;

	type* arr=new type[n];
	for(int i=0;i<n;++i)
		cin>>arr[i];

	type x;
	cin>>x;
	
	int result=fibonacci_search(arr,n,x);
	
	if(result!=-1)
		cout<<"Position of the element "<<x<<" : "<<result<<endl;
	else
		cout<<"There is no element "<<x<<endl;
	
    return 0;
}
