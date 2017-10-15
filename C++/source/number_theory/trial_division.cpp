/*
	Trial Division
	_______________
	Check if a number is prime or not, given the value of N.
	
	Checks if a prime in the range of 2 to sqrt(N) divides N.
	If it does, then N is not a Prime, otherwise, N is a Prime.

	Time Complexity
	________________
	O(sqrt(N) log log sqrt(sqrt(N))), where sqrt(N) is the square
	root of N.

	Space Complexity
	________________
	O(sqrt(N)), where sqrt(N) is the square root of N.
*/

#include <iostream>
#include <vector>

using namespace std;

typedef int type;

vector<int> sieve(type n) 
{
	vector<bool> primes_check(n,1);
	vector<int> primes;
	for(int i=2;i*i<n+1;++i)
	{
		if(primes_check[i])
			primes.push_back(i);
		for(int j=i*i;j<n;j+=i)
			primes_check[j]=0;
	}
	return primes;
}

bool trial_division(type n)
{
	if(n<3)
		return 1;
	vector<int> primes=sieve(n);
	int i;
	for(i=0;i<primes.size();++i)
	{
		if(!(n%primes[i]))
			return 0;
	}
	if(i==primes.size())
		return 1;
}

int main()
{
	type n;
	cin>>n;
	if(trial_division(n))
		cout<<"It is a Prime!"<<endl;
	else
		cout<<"It is not a Prime!"<<endl;
}
