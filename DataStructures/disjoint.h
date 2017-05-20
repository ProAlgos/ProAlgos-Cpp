#ifndef DISJOINT_H
#define DISJOINT_H

#include <cstdlib>
#include <vector>

class disjoint_set_t
{
public:
    disjoint_set_t(size_t nodes);

    int find_set(int x);
    void union_sets(int x, int y);

private:
    std::vector<int> parent_;
    std::vector<int> rank_;
};

#endif
