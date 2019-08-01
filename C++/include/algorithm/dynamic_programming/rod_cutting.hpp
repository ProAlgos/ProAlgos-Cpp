/*
    Rod cutting problem
    --------------------
    Given a rod of length N units and an array of prices 
    that contains prices of all pieces of size smaller than N. 
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

#include <vector>

#ifndef ROD_CUTTING_HPP
#define ROT_CUTTING_HPP

/**
 * Recursive helper function
 */
int __rod_cutting( const std::vector<int>& costs, std::vector<int>& visited, int length) {
    // whole unit, can't delete
    if( length == 1 ) {
        return visited[0];
    }

    // try to sell it as is, not cutting
    int cost = costs[ length - 1 ];
    int next_cost;

    /** 
     * loop to check only half,
     * because other half is symmetric
     * try cutting 1, 2, 3 ...
     * and find optimal
     */
    for( std::size_t i = 1; i <= length / 2; i++ ) {
        // if we've already found - use it
        if( visited[ length - i - 1 ] != -1 ) {
            next_cost = visited[ length - i - 1 ];
        }
        // if no - go find it
        else {
            next_cost = __rod_cutting( costs, visited, length - i );
        }

        // plus cost of the piece we are cutting
        next_cost += costs[ i - 1 ];

        // assign maximal value
        if( cost < next_cost ) {
            cost = next_cost;
        }
    }

    // don't forget to set this
    // as visited
    visited[length - 1] = cost;
    return cost;
}

/**
 * Solution function
 */
int rod_cutting( std::vector<int> costs ) {
    // vector of already found optimal costs 
    std::vector<int> visited ( costs.size(), -1 );
    // rod of length 1 is optimally sold at cost of itself
    visited[0] = costs[0];

    return __rod_cutting( costs, visited, costs.size() );
}

#endif  // CUT_THE_ROD_HPP
