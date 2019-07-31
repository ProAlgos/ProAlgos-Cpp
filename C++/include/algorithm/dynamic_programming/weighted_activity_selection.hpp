/*
    Weighted activity selection problem
    --------------------
	Given N activities where every activity is represented by 
	following three elements of it.

	1. Start Time
	2. Finish Time
	3. Weight or Value Associated

	Find the maximum weight subset of activities such that no two of them in the subset overlap.


    Time complexity
    ---------------
    O(N*lg(N))

    Space complexity
    ----------------
    O(N)

    Author
    ------
    Fedurko Nikolaus (@B1Z0N)
*/

#include <ios>
#include <vector>
#include <algorithm>

#ifndef WEIGHTED_ACTIVITY_SELECTION_HPP
#define WEIGHTED_ACTIVITY_SELECTION_HPP

/**
 * Struct for single activity data
 */
struct Activity
{
	std::size_t start;
	std::size_t end;
	std::size_t weight;
};

/**
 * Find the index of right-most 
 * non-overlaping activity
 * that is left to the query[ index ]
 * using binary search in O( lg(index) )
 */
int left_activity_bsearch( const std::vector<Activity> quer, std::size_t index )
{
	std::size_t lo = 0, hi = index - 1;
	while( lo <= hi )
	{
		std::size_t mid = ( lo + hi ) / 2;
		if( quer[ mid ].end <= quer[ index ].start )
		// if it is non-overlaping
		{
			if( quer[ mid + 1 ].end <= quer[ index ].start )
			// if there are other non-overlaping activity
			// a bit to the right, then continue searching
				lo = mid + 1;
			else
			// if it is right-most non-overlaping
				return mid;
		}
		else
		// if there are overlaps, in the middle
		// look to the left half
			hi = mid - 1;
	}

	return -1;
	// if quer[ index ] has no non-overlaping activites
	// to the left of it
}

/**
 * Algorithm of solution
 */
std::size_t weighted_activity(std::vector<std::size_t> start, 
							  std::vector<std::size_t> end, 
							  std::vector<std::size_t> weight)
{
	std::vector<Activity> quer;
	for( int i = 0; i < start.size(); i++ )
		quer.push_back( { start[ i ], end[ i ], weight[ i ] } );
	// sort by end in ascending order
	std::sort( std::begin( quer ), std::end( quer ), 
		[] (const Activity& fst, const Activity& snd)
		{
			return fst.end < snd.end;
		}
	);

	std::vector<std::size_t> sol ( quer.size() );
	// sol[ i ] stores solution to first i + 1 activities

	sol[0] = quer[0].weight;
	// first solution is just it's single weight
	for( std::size_t i = 1; i < quer.size(); i++ )
	// find all solutions
	{
		std::size_t weight_with_current = quer[i].weight;
		int j = left_activity_bsearch( quer, i );
		// j - index of the problem needed to solve if
		// we want to include our i index in solution

		if( j != -1 ) weight_with_current += sol[j];
		// if there are consistent j on the left, 
		// add max_weight of it's solution

		sol[ i ] = std::max( 
		// decide whether to include this i index into solution
		// depending on it's weights
			sol[ i - 1 ], 	 // weight without current
			weight_with_current 
		);
	}

	return sol.back();	
	// last index contains solution to whole problem
}

#endif	// WEIGHTED_ACTIVITY_SELECTION_HPP
