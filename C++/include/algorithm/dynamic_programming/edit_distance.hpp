/*
    Edit distance problem
    --------------------
	Given two strings str1 and str2 and below operations that can performed on str1. 
	Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

	1. Insert
	2. Remove
	3. Replace
	
	All of the above operations are of equal cost.
    
    Time complexity
    ---------------
    O(M*N), 
    where M, N are lengths of the first and the second string, in order.

    Space complexity
    ----------------
    O(M*N)

    Author
    ------
    Fedurko Nikolaus (@B1Z0N)
*/

#ifndef EDIT_DISTANCE_HPP
#define EDIT_DISTANCE_HPP

#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

struct EditIntervals
// structure to denote substrings
// to find edit_distance of 
// a[0..end1] and b[0..end2]
{
	int end1;
	int end2;

	friend bool operator==( const EditIntervals& a, const EditIntervals& b)
	{
		return a.end1 == b.end1 && a.end2 == b.end2;
	}
};

class EditIntervalsHash
// hash functor for unordered_map
{
public:
	size_t operator()( const EditIntervals& ivls ) const
	{
		return std::hash<int>{}( ivls.end1 ) ^ std::hash<int>{}( ivls.end2 );
	}
};

int min( int a, int b, int c )
{
	return std::min( std::min( a, b ), c ); 
} 

// Recursive helper function
int __edit_distance( const std::string& a, const std::string& b, 
	std::unordered_map<EditIntervals, int, EditIntervalsHash>& visited, 
	int enda, int endb )
{
	if( visited.find( { enda, endb } ) != std::end( visited ) )
		// if already calculated - return it
		return visited[ { enda, endb } ];

	if ( enda == 0 ) return endb;
	if ( endb == 0 ) return enda;

	if( a[ enda - 1 ] == b[ endb - 1 ] ) 
	{
		visited[ { enda, endb } ] = __edit_distance( a, b, visited, enda - 1, endb - 1 );

		return visited[ { enda, endb } ];
	}

	visited[ { enda, endb } ] = min( 
			__edit_distance( a, b, visited, enda 	, endb - 1 ), // insert
			__edit_distance( a, b, visited, enda - 1, endb     ), // remove
			__edit_distance( a, b, visited, enda - 1, endb - 1 )  // replace
		) + 1;

	return visited[ { enda, endb } ];
}

// Solution function
int edit_distance( std::string a, std::string b )
{
	std::unordered_map<EditIntervals, int, EditIntervalsHash> visited;

	return __edit_distance( a, b, visited, a.size(), b.size() );
}

#endif	// EDIT_DISTANCE_HPP