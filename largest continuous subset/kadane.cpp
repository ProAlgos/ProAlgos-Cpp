// PROBLEM :: find the sum of the largest sum continuous array using KADANE'S ALGORITHM


#include <iostream>
#include <vector>
using namespace std;


void maxSumSubArray(const vector<int>& values)
{
	int max_so_far=values[0];
	int curr_max=values[0];

	int start=0,end=0;

	for(int i=1;i<values.size();;i++)
	{
		curr_max=max(values[i],curr_max+values[i]);

		if(curr_max==values[i])
		{
			start=i;
		}

		if(curr_max>max_so_far)
		{
			max_so_far=curr_max;
			end=i;
		}
	}

	cout<<"the max contiguous sum is :: " << max_so_far<<"\n";
	cout<<"the sequence starts from "<<start<<" and ends at "<<end<<"\n";
	cout<<"and the values are :: ";
	for(int i=start;i<=end;i++)
		cout<<values[i]<<" ";
}
int main()
{
	size_t size;
	cout<<"how many values you want to enter in the array \n";
	cin>>size;

	vector<int>values(size);
	cout<<"enter the values in the array\n";
	
	for(int& val:values)
		cin>>val;
	
	maxSumSubArray(values);
}

