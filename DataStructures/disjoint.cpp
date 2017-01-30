#include "disjoint.h"

disjoint_set_t::disjoint_set_t(size_t nodes) : parent_(nodes), rank_(nodes, 0)
{
    /* initially all elements are singletons i.e. they are parents of themselves */
    for(size_t i = 0; i < nodes; ++i) {
        parent_[i] = i;
    }
}

int disjoint_set_t::find_set(int x)
{
    /* if x is set representative, we are done */
    if(parent_[x] == x) {
        return x;
    }
    /* travel recursively to the representative node
       also path compression is done: representative becomes parent of all nodes on the path
    */
    return parent_[x] = find_set(parent_[x]);
}

void disjoint_set_t::union_sets(int x, int y)
{
    /* find representatives of inputs (tree roots) */
    x = find_set(x);
    y = find_set(y);

    /* decide to connect one root to another based on representatives rank */
    if(rank_[x] < rank_[y]) {
        parent_[x] = y;
    } else {
        parent_[y] = x;

        /* inscrease final rank if ranks are identical */
        if (rank_[x] == rank_[y]) {
            ++rank_[x];
        }
    }
}
