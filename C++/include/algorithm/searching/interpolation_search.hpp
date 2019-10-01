/*
    Interpolation search
    -------------
    A searching algorithm that finds the index of a target value within a
    sorted array using interpolation method.

    Time complexity
    ---------------
    O(loglog(N)), where N is the number of elements in the array.

    Space complexity
    ----------------
    O(1).
*/
#ifndef INTERPOLATION_SEARCH_HPP
#define INTERPOLATION_SEARCH_HPP
/*
    interpolation_search
    -------------
     Interpolation Search is an improvement over Binary Search for scenarios where the values
      in a sorted array are uniformly distributed. Binary Search goes to the middle element to check.
*/
#include<vector>
using namespace std;

template<typename T,typename T1,typename T2>
int interpolation(T1 key,T arr[],T2 size){
int low=0,high=size-1;
while(low<=high && key>=arr[low] && key <=arr[high]){
    if(low==high){
        if(arr[low]==key) return low;
        return -1;
    }

    int pos=low+(key-arr[low])*(high-low)/(arr[high]-arr[low]);
    if(arr[pos]==key)
        return pos;
    if(arr[pos]>key)
        high=pos-1;
    if(arr[pos]<key)
        low=pos+1;



}
return -1;
}
template<typename p,typename p1  >
int interpolation(p1 key,vector<p> arr){
int low=0,high=arr.size()-1;
while(low<=high && key>=arr[low] && key <=arr[high]){
    if(low==high){
        if(arr[low]==key) return low;
        return -1;
    }

    int pos=low+(key-arr[low])*(high-low)/(arr[high]-arr[low]);
    if(arr[pos]==key)
        return pos;
    if(arr[pos]>key)
        high=pos-1;
    if(arr[pos]<key)
        low=pos+1;



}
return -1;
}

#endif // !INTERPOLATION_HPP
