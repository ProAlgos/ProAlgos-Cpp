/*
    Bucket sort
    ----------------------
    Bucket sort, or bin sort, is an integer sorting algorithm that works by
    distributing the elements of an array into a number of buckets. Each 
    is then sorted individually using a different sorting algorithm. 
    Insertion sort is used in this implementation, but other sorting 
    algorithms can be used, too.

    This is a linear sorting algorithm for evenly distributed items.

    Time complexity
    ---------------
    O(N ^ 2) worst case
    O(N + N^2 / k + k) average case when k is the number of buckets, 
    which is O(n) if K ~ N

    Space complexity
    ----------------
    O(N)
*/

#ifndef BUCKET_SORT_HPP
#define BUCKET_SORT_HPP

#include <vector>
#include <list>
#include "utils.hpp"
#include "insertion_sort.hpp"

using std::vector;
using std::list;

void bucket_sort(vector<int>& values, const int order = 1, const bool to_show_state = false) {

    if (values.empty()) {
        return;
    }

    auto max_value = values[0], min_value = values[0];
    int negative_count = 0, positive_count = 0;

    for (int i : values) {
        max_value = std::max(max_value, i);
        min_value = std::min(min_value, i);
        negative_count += i < 0;
        positive_count += i >= 0;
    }

    // The number of negative buckets will be the number of negative elements
    vector<list<int>> negative_buckets(negative_count);

    // The number of positive buckets will be the number of positive elements
    vector<list<int>> positive_buckets(positive_count);

    // Insert the items into their appropriate bucket
    for (float i : values) {
        if (i > 0) {
            // As the bucket index grows, elements get larger
            float bucket_index = (positive_buckets.size() * i / max_value) - 1; 
            positive_buckets[static_cast<int>(bucket_index)].push_back(i);

        } else if (i < 0) {
            // As the bucket index grows, elements get smaller
            float bucket_index = (negative_buckets.size() * i / min_value) - 1; 
            negative_buckets[static_cast<int>(bucket_index)].push_back(i);

        } else {
            // Special case for 0
            positive_buckets[0].push_back(i);
        }
    };

    values.clear();
    
    auto sort_buckets_and_unify = [&](auto it_start, auto it_end) {
        for_each(it_start, it_end,[&](auto bucket) {
            
            // Sort each bucket individually using internal file insertion_sort.hpp
            // Note that other sorting algorithms can also be used
            vector<int> sorted(bucket.size());
            sorted.assign(begin(bucket), end(bucket));
            insertion_sort(sorted, order, false);

            // Insert the sorted bucket result into the original values vector
            values.insert(end(values), begin(sorted), end(sorted));

            if (to_show_state) {
                display_state(values);
            }
        });
    };

    if (order == 1) {
        // 1 means ascending, so we should start from the smallest negative
        // element and end with the largest positive element
        sort_buckets_and_unify(rbegin(negative_buckets), rend(negative_buckets));
        sort_buckets_and_unify(begin(positive_buckets), end(positive_buckets));
    } else {
        // -1 means descending, so we should start from the largest positive
        // element and end with the smallest negative element
        sort_buckets_and_unify(rbegin(positive_buckets), rend(positive_buckets));
        sort_buckets_and_unify(begin(negative_buckets), end(negative_buckets));
    }
}

#endif // BUCKET_SORT_HPP
