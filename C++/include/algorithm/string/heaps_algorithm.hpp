/*
    Heap's Algorithm
    ----------------

    This algorithm generates all possible
permutations of a collection of n elements.    
The algorithm minimizes movement: it generates each permutation from the previous one by interchanging a single pair of elements, while the other n-2 remain undisturbed.
    
    Time Complexity
    ---------------
    O(n!), where n is the number of elements in the collection

    Space Complexity
    ----------------
    O(n), where n is the number of elements in the collection

*/


#ifndef HEAPS_ALGORITHM_HPP
#define HEAPS_ALGORITHM_HPP

#include <vector>

using namespace std;

vector<string> heaps_algorithm(unsigned int number_of_elements, string& collection, vector<string>& permutations) {   

    if (number_of_elements == 1 || collection == "") {
        permutations.push_back(collection);
    }
    
    else {
        heaps_algorithm(number_of_elements-1, collection, permutations);

        for (int i = 0; i < number_of_elements-1; i++) { 
            if (number_of_elements % 2 == 0) {
                swap(collection[i], collection[number_of_elements-1]);
            }
            else {
                swap(collection[0], collection[number_of_elements-1]);
            }
            heaps_algorithm(number_of_elements-1, collection, permutations);
        }
    }
    return permutations;
}

#endif //HEAPS_ALGORITHM_HPP
