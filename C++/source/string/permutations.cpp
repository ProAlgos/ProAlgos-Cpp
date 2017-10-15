/*
	Permutations of a string
	_________________________
	
	Print all the permutations of a string (including duplicates if
	the input string contains repeating characters)

	Time complexity
	_______________
	
	O(N*N!)
	Use of backtracking

	Space complexity
	________________
	
	O(N*N!)
*/

#include<iostream>
#include<string.h>

using namespace std;

void permutations(string& a, int first, int last)
{
   	if(first==last)
		cout<<a<<endl;
   	else
   	{
   		for (int i=first;i<=last;i++)
       	{
        	swap(a[first],a[i]);
          	permutations(a,first+1,last);
          	swap(a[first],a[i]);
       	}
   	}
}

int main()
{
	string input;
	cin>>input;
	permutations(input,0,(int)input.size()-1);
}
