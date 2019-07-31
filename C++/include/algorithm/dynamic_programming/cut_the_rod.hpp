/*
    Cutting the rod problem
    --------------------
	Given a rod of length n inches and an array of prices 
	that contains prices of all pieces of size smaller than n. 
	Determine the maximum value obtainable by cutting up 
	the rod and selling the pieces

    Time complexity
    ---------------
    O(N^2)

    Space complexity
    ----------------
    O(N)

    Author
    ------
    Fedurko Nikolaus (@B1Z0N)
*/

#include <vector>	// vector

#ifndef CUT_THE_ROD_HPP
#define CUT_THE_ROD_HPP

/**
 * Recursive helper function
 */
int __cut_the_rod( const std::vector<int>& costs, std::vector<int>& visited, int len)
{
	if( len == 1 )
		// whole unit, can't delete
		return visited[0];

	int cost = costs[ len - 1 ];
	// try to sell it as is, not cutting
	int next_cost;

	for( int i = 1; i <= len / 2; i++ )
	// loop to check only half
	// because other half is symmetric
	{
		// try cutting 1, 2, 3 ...
		// and find optimal
		if( visited[ len - i - 1 ] != -1 )
			// if we already found - use it
			next_cost = visited[ len - i - 1 ];
		else
			// if no - go find it
			next_cost = __cut_the_rod( costs, visited, len - i );

		// plus cost of the pieace we are cutting
		next_cost += costs[ i - 1 ];

		if( cost < next_cost )
			// assign maximal value
			cost = next_cost;
	}

	// don't forget to set this
	// as visited
	visited[len - 1] = cost;
	return cost;
}

/**
 * Solution function
 */
int cut_the_rod( std::vector<int> costs )
{
	std::vector<int> visited ( costs.size() );
	// vector of already found optimal costs 
	for( auto& x : visited ) x = -1;
	visited[0] = costs[0];
	// rod of length 1 is optimally selled at cost of itself

	return __cut_the_rod( costs, visited, costs.size() );
}

#endif	// CUT_THE_ROD_HPP