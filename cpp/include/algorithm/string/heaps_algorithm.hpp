/*
    Heap's Algorithm
    ----------------

    This algorithm generates all possible permutations of a collection of n elements.    
    The algorithm minimizes movement: it generates each permutation from the previous 
    one by interchanging a single pair of elements, while the other n-2 remain undisturbed.
    
    Time Complexity
    ---------------
    O(N!), where N is the number of elements in the collection

    Space Complexity
    ----------------
    O(N), where N is the number of elements in the collection

*/

#ifndef HEAPS_ALGORITHM_HPP
#define HEAPS_ALGORITHM_HPP

#include <vector>

using std::string;
using std::vector;
using std::swap;

vector<string> heaps_algorithm(unsigned int number_of_elements, string& collection, vector<string>& permutations) {   
    
    if (number_of_elements == 1 || collection.empty()) {
        permutations.push_back(collection);
    }
    
    else {

        /* Generate permutations with i-th element unaltered 
         * Initially number_of_elements == length of input string */
        heaps_algorithm(number_of_elements - 1, collection, permutations);

        /* Generate permutations where the i-th element is swapped
         * with each i-1 initial elements */
        for (unsigned int i = 0; i < number_of_elements - 1; i++) {
            
            /* The swap choice depends on the parity of 
             * number_of_elements within each recursive call */
            if (number_of_elements % 2 == 0) {        
                swap(collection[i], collection[number_of_elements - 1]); // zero-indexed, the i-th is at i-1
            
            } else {
                swap(collection[0], collection[number_of_elements - 1]);
            }

            /* This second recursive call exists to avoid additional swaps at each level 
             * The algorithm would work without it, but wouldn't be the way B.R. Heap designed it */
            heaps_algorithm(number_of_elements - 1, collection, permutations);
        }
    }
    return permutations;
}

#endif //HEAPS_ALGORITHM_HPP
