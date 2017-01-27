// PROBLEM :: find the sum of the largest sum continuous array using KADANE'S ALGORITHM


#include <iostream>
#include <vector>
using namespace std;


void maxSumSubArray(vector<int>values)
{
	int max_so_far=values[0];
	int curr_max=values[0];

	int s=0,e=0;

	int n=values.size();

	for(int i=1;i<n;i++)
	{
		curr_max=max(values[i],curr_max+values[i]);

		if(curr_max==values[i])
		{
			s=i;
		}

		if(curr_max>max_so_far)
		{
			max_so_far=curr_max;
			e=i;
		}
	}

	cout<<"the max contiguous sum is :: " << max_so_far<<"\n";
	cout<<"the sequence starts from "<<s<<" and ends at "<<e<<"\n";
	cout<<"and the values are :: ";
	for(int i=s;i<=e;i++)
		cout<<values[i]<<" ";
}
int main()
{
	int n;
	vector<int>values;
	cout<<"how many values you want to enter in the array \n";
	cin>>n;
	cout<<"enter the values in the array\n";
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		values.push_back(x);
	}

	maxSumSubArray(values);
}

