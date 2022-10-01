#include "third_party/catch.hpp"
#include "algorithm/dynamic_programming/0_1_knapsack.hpp"
using std::vector;

TEST_CASE("Base Cases", "[knapsack]") {
    REQUIRE(knapsack(10, 3, vector<LL>({11, 21, 31}), vector<LL>({1, 2, 3})) == 0);
}
TEST_CASE("Simple Cases", "[knapsack]") {
    REQUIRE(knapsack(50, 3, vector<LL>({10, 20, 30}), vector<LL>({60, 200, 220})) == 420);
    REQUIRE(knapsack(4, 5, vector<LL>({1, 2, 3, 2, 2}), vector<LL>({8, 4, 0, 5, 3})) == 13);
    REQUIRE(knapsack(4, 5, vector<LL>({1, 2, 3, 2, 2}), vector<LL>({11, 22, 11, 23, 24})) == 47);
}


//unbounded knapsack..
//this means that one element can be used multiple times..
//here we will take one element and give another chance or not take at all.. 
//this should also be included in your repo

/*
/* A Naive recursive implementation of
unbounded Knapsack problem */
#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int unboundedKnapsack(int W, int wt[], int val[], int idx)
{

	// Base Case
	// if we are at idx 0.
	if (idx == 0) {
		return (W / wt[0]) * val[0];
	}
	// There are two cases either take element or not take.
	// If not take then
	int notTake
		= 0 + unboundedKnapsack(W, wt, val, idx - 1);
	// if take then weight = W-wt[idx] and index will remain
	// same.
	int take = INT_MIN;
	if (wt[idx] <= W) {
		take = val[idx]
			+ unboundedKnapsack(W - wt[idx], wt, val,
								idx);
	}
	return max(take, notTake);
}

// Driver code
int main()
{
	int W = 100;
	int val[] = { 10, 30, 20 };
	int wt[] = { 5, 10, 15 };
	int n = sizeof(val) / sizeof(val[0]);

	cout << unboundedKnapsack(W, wt, val, n - 1);
	return 0;
}



//iterative optimization
// C++ program to find maximum achievable value
// with a knapsack of weight W and multiple
// instances allowed.
#include<bits/stdc++.h>
using namespace std;

// Returns the maximum value with knapsack of
// W capacity
int unboundedKnapsack(int W, int n,
					int val[], int wt[])
{
	// dp[i] is going to store maximum value
	// with knapsack capacity i.
	int dp[W+1];
	memset(dp, 0, sizeof dp);

	// Fill dp[] using above recursive formula
	for (int i=0; i<=W; i++)
	for (int j=0; j<n; j++)
		if (wt[j] <= i)
			dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);

	return dp[W];
}

// Driver program
int main()
{
	int W = 100;
	int val[] = {10, 30, 20};
	int wt[] = {5, 10, 15};
	int n = sizeof(val)/sizeof(val[0]);

	cout << unboundedKnapsack(W, n, val, wt);

	return 0;
}
*/
    
