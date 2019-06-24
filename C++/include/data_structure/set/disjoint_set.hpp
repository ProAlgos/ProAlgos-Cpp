/*
    Disjoint-set
    ------------
    A disjoint-set data structure (also called a union–find data structure or
    merge–find set) keeps track of a set of elements partitioned into a number
    of disjoint (non-overlapping) subsets.
*/

#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP

#include <cstddef>
#include <vector>

struct Element {
    int parent;
    int rank;
};


/*
    DisjointSet
    -----------
    Class implementing the disjoint-set data structure.
*/

class DisjointSet {
    std::vector<Element> set;

    public:
        DisjointSet(size_t);

        int find(int);
        void join(int, int);

        size_t size() const;
};


/*
    Constructor
    -----------
*/

DisjointSet::DisjointSet(size_t num_nodes) {
    set.resize(num_nodes);

    // initially all elements are parents of themselves, with rank 0
    for (size_t element = 0; element < set.size(); element++) {
        set[element].parent = element;
        set[element].rank = 0;
    }
}


/*
    find
    ----
    Returns the representative (root) element of the given element, while also
    performing path compression - making the representative the parent of all
    elements in the "path".

    Time complexity
    ---------------
    log*(N), where N is the number of elements in the disjoint-set.

    Space complexity
    ----------------
    O(1).
*/

int DisjointSet::find(int x) {
    // recursively travel to the representative element while also performing
    // path compression
    if (set[x].parent != x)
        set[x].parent = find(set[x].parent);

    return set[x].parent;
}


/*
    join
    ----
    Joins the subsets to which the given elements belong to, depending on the
    rank of their representative elements.

    Time complexity
    ---------------
    log*(N), where N is the number of elements in the disjoint-set.

    Space complexity
    ----------------
    O(1).
*/

void DisjointSet::join(int x, int y) {
    // find the representatives (roots) of the given elements
    int x_root = find(x);
    int y_root = find(y);

    if (x_root == y_root)   // if x and y are already in the same set
        return;     // nothing to do

    // otherwise, join them depending on their representative's rank
    if (set[x_root].rank < set[y_root].rank)    // if x's rank is less than y's
        set[x_root].parent = y_root;    // join x's root to y's
    else {  // if y's rank is less than (or equal to) x's
        set[y_root].parent = x_root;    // join y's root to x's

        if (set[x_root].rank == set[y_root].rank)   // if the ranks are equal
            ++set[x_root].rank;     // increase the rank of x's representative
    }
}


/*
    size
    ----
    Returns the number of elements in the set.
*/

size_t DisjointSet::size() const {
    return set.size();
}

#endif  // DISJOINT_SET_HPP
