/*
	Linear Search
	_____________

	Find the position of an element X, in an array "arr".
	The inputs are : 
		- N : size of the array.
		- N elements of the array.
		- X : element we want to find.

	Time complexity
	_______________

	O(N)

	Space complexity
	________________

	O(N)
*/

#include<iostream>

using namespace std;

typedef int type;

int linear_search(type* arr, int n, type x)
{
	int i;
	for(i=0;i<n;++i)
		if(arr[i]==x)
			return i;
	if(i==n)
		return -1;
}

int main()
{
	int n;
	cin>>n;

	type* arr=new type[n];
	for(int i=0;i<n;++i)
		cin>>arr[i];
	
	type x;
	cin>>x;

	int result=linear_search(arr,n,x);

	if(result!=-1)
		cout<<"Position of element "<<x<<" : "<<result<<endl;
	else
		cout<<"There is no element "<<x<<endl;	
}
