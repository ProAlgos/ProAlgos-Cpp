/*
    Quaternary Search
    -------------------
     A four search locates an item in a sorted array by repeatedly
     dividing the search interval into four equal parts.

    Time complexity
    ---------------
    O(log(N)), where N is number of elements in array and base of logarithm is 4

    Space complexity
    ----------------
    O(1)
*/

#ifndef QUATERNARY_SEARCH_HPP
#define QUATERNARY_SEARCH_HPP

#include <vector>

template <typename T>
int quaternary_search(const T& element, const std::vector<T>& values) 
{
    size_t h = values.size()-1; 
    size_t l = 0;
    while(h>=l) 
    { 
        size_t j = ((3*l)+h)/4;
        size_t m = (h+l)/2;
        size_t k = ((3*l)+h)/4;
        if(values[j]==element)
        {
            return j;
            l=h+1;
        }
        else if(values[m]==element)
        {
            return m;
            l=h+1; 
        }
        else if(values[k]==element) 
        {
            return k;
            l=h+1; 
        }
        else if(element<values[j]) 
        {
            h=j-1; 
        }
        else if(element<values[m])
        {
            l=j+1;
            h=m-1; 
        }
        else if(element<values[k]) 
        {
            l=m+1;
            h=k-1; 
        }
        else 
        {
        l=k+1; 
        }
    }
    return -1;
}
#endif
 
