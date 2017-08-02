/*
    Median in a stream of integers(running integers)
    ------------------------------------------------
    An algorithm to find the median of elements read so far from
    a data stream in a efficient way.

    Assumptions: There are no duplicates.

    Time Complexity
    ---------------
    O(NlogN), where N is the number of elements.

    Space Complexity
    ----------------
    O(N^2)

    Auxilliary Space
    ----------------
    O(N)

*/
//Explanation link :https://www.youtube.com/watch?v=VmogG01IjYc
#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<iterator>
#include<queue>

using namespace std;

typedef long long ll;
priority_queue <ll> great;
priority_queue<ll,vector <ll>,greater<ll> > shorter;

void add(ll num)
{
	if(!great.empty() and num < great.top())
	{
		great.push(num);
		if (great.size() - shorter.size() == 1)
		{
			shorter.push(great.top());
			great.pop();
		}
	}
	else
	{
		shorter.push(num);
		if (shorter.size() - great.size() == 2)
		{
			great.push(shorter.top());
			shorter.pop();
		}
	}
}
ll median()
{
	if (shorter.size() == great.size())
		return (shorter.top() + great.top()) / 2.0;
	return shorter.top();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll x;
		cin>>x;
		add(x);
		cout<<median()<<endl;
	}
	return 0;
}
