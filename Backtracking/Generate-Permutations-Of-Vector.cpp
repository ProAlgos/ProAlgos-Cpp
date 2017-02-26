#include <iostream>
#include <vector>

using namespace std;

void initializeData(int &number_of_elements,
                    vector<int> &vector_to_permute){
    int number_of_elements_to_enter;
    int current_element;

    cout << "Enter the number of elements" << endl;
    cin >> number_of_elements;

    number_of_elements_to_enter = number_of_elements;
    vector_to_permute.reserve(number_of_elements * sizeof(int));

    cout << "Enter " << number_of_elements << " elements" << endl;

    while(number_of_elements_to_enter > 0){
        cin >> current_element;
        vector_to_permute.push_back(current_element);
        number_of_elements_to_enter--;
    }
}


void initializeSolutionVector(vector<int> &current_solution,
                              int number_of_elements) {
    for(int i = 0; i < number_of_elements; i++ )
        current_solution.push_back(-1);
}

/**
 * Check if an element was used before
 * If it was used the current solution is not valid
 */
bool isValid(int to_check,
             vector<int> &current_solution){
    for(int i = 0; i < to_check; i++)
        if( current_solution[i] == current_solution[to_check])
            return false;
    return true;
}

/**
 * Check if we used every element from vector
 */
bool isSolution(int current_step,
                int number_of_elements){
    return (current_step == (number_of_elements - 1));
}

void print(int number_of_elements,
           vector<int> vector_to_permute,
            vector<int> current_solution){
    for(int i = 0; i < number_of_elements; i++){
        cout << vector_to_permute[current_solution[i]] << " ";
    }
    cout << endl;
}

void generatePermutations(int current_step,
                          int number_of_elements,
                          vector<int> &vector_to_permute,
                          vector<int> &current_solution) {

    for (int i = 0; i < number_of_elements; i++) {
        current_solution[current_step] = i;

        if (isValid(current_step, current_solution) &&
                isSolution(current_step, number_of_elements)) {

            if (isSolution(current_step, number_of_elements)) {
                print(number_of_elements,vector_to_permute,current_solution);
            }
        }

        if (isValid(current_step, current_solution)) {
            generatePermutations(current_step + 1,
                                 number_of_elements,
                                 vector_to_permute,
                                 current_solution);
        }

    }
}

int main() {
    vector<int> vector_to_permute;
    vector<int> current_solution;
    int number_of_elements;

    initializeData(number_of_elements, vector_to_permute);
    initializeSolutionVector(current_solution, number_of_elements);
    generatePermutations(0, number_of_elements, vector_to_permute, current_solution);

    return 0;
}
