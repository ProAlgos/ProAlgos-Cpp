/*
    Permutation Generator
    ---------------------
    An algorithm that generates all the permutations of a set of size n.

    Time complexity
    ---------------
    O(N!), where N is the size of the set.

    Space complexity
    ----------------
    O(N), where N is the size of the set.
*/

#ifndef PERMUTATION_GENERATOR_HPP
#define PERMUTATION_GENERATOR_HPP

#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::vector;

void printSet(vector<char> set)
{
    cout << "{";
    for(int i = 0; i < set.size(); i++)
        cout << set[i] << ", ";
    cout << "}" <<endl;
}

// Function prints all permutations of given set and returns number of permutations
int permutation(vector<char> set, int start_index, int size, int num_perms = 0)
{
    if(start_index == size)
    {
        printSet(set);  // Print one permutation and increment the total sum
        num_perms++;
    }
    else
    {
        for(int i = start_index; i < size; i++)
        {
            int temp = set[start_index];    // Swap out elements to create new permutation
            set[start_index] = set[i];
            set[i] = temp;

            // Recursive call to continue swapping unti; start_index becomes equal to size
            num_perms = permutation(set, start_index + 1, size, num_perms);

            temp = set[start_index];
            set[start_index] = set[i];
            set[i] = temp;
        }
    }
    return num_perms;
}

#endif