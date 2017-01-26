// PROBLEM :: find the sum of the largest sum continuous array.

#include <bits/stdc++.h>
using namespace std;

// METHOD 1 : USING KADANE'S ALGORITHM
// DOESN'T WORK IF ALL THE ELEMENTS ARE NEGATIVE

void kadaneAlgo(int arr[],int n)
{
	int max_so_far=0;
	int curr_max=0;

	int s=0,e=0;

	for(int i=0;i<n;i++)
	{
		curr_max+=arr[i];
		if(curr_max<0)
		{
			curr_max=0;
			s=i+1;
		}
		else if(curr_max>max_so_far)
		{
			max_so_far=curr_max;
			e=i;
		}
	}

	cout<<max_so_far<<"\n";

	for(int i=s;i<=e;i++)
	{
		cout<<arr[i]<<" ";
	}
}

// METHOD 2 :: IMPROVED VERSION
// works well for all negative elements

void maxSumSubArray(int a[],int n)
{
	int max_so_far=a[0];
	int curr_max=a[0];

	int s=0,e=0;

	for(int i=1;i<n;i++)
	{
		curr_max=max(a[i],curr_max+a[i]);

		if(curr_max==a[i])
		{
			s=i;
		}

		if(curr_max>max_so_far)
		{
			max_so_far=curr_max;
			e=i;
		}
	}

	cout<<max_so_far<<"\n";
	for(int i=s;i<=e;i++)
		cout<<a[i]<<" ";
}
int main()
{

	int arr[]={-2,-3,4,1,-2,-1,5,-3};

	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<"METHOD 1 :: \n";
	kadaneAlgo(arr,n);

	cout<<"\n\n";

	cout<<"METHOD 2 :: \n";
	maxSumSubArray(arr,n);

}

