/*
    Printing all the permutations of a string/array
    --------------------
    A permutation, also called an “arrangement number” or “order,” is a rearrangement 
    of the elements of an ordered list S into a one-to-one correspondence with S itself.
    A string of length n has n! permutation. Generate all the permutations of the string.
    
    Time complexity
    ---------------
    O(N*N!), where N is the length of the string.
    
    Space complexity
    ----------------
    O(N!), where N is the length of the string.
    
    Author
    ------
    Brijesh Kumar (@brijeshsos66)
*/

#ifndef ALL_PERMUTATIONS_HPP
#define ALL_PERMUTATIONS_HPP

#include <algorithm>

/*
Below is the program for printing the permutations of a string. Inorder to perform the same on a array/vector
then convert the array elements into string(using to_string() function) and perform the same.
Here start is the starting point of a string intially equals to 0 and end is initially equals to length of the 
string minus 1 (N - 1) as indices are starting from 0.
*/
void permutations(string str, int start, int end){ 
    //BASE case
    if(start == end)
        cout<<str<<endl;
    else{
        for(int i=start;i<=end;i++){
            //SWAP
            swap(a[start],a[i]);
            
            //RECURSION
            permutations(str,start+1,end);
            
            //BACKTRACKING
            swap(a[start],a[i]);
        }
    }
}


#endif // ALL_PERMUTATIONS_HPP
