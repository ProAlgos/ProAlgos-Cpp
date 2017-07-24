#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP

#include <cstddef>
#include <vector>

struct Element {
    int parent;
    int rank;
};

class DisjointSet {
    std::vector<Element> set;

    public:
        DisjointSet(size_t);

        int find(int);
        void join(int, int);

        size_t size() const;
};

#endif
