#include <iostream>
#include <cstdlib>

using namespace std;

int *current_solution;
int *vector_to_permute;

void initializeData(int &number_of_elements,
                    int *&vector_to_permute){

    cin >> number_of_elements;

    vector_to_permute = (int*)malloc(number_of_elements * sizeof(int));

    for(int i = 0; i < number_of_elements; i++)
        cin >> vector_to_permute[i];
}

bool isValid(int to_check){
    for(int i = 0; i < to_check; i++)
        if( current_solution[i] == current_solution[to_check])
            return false;
    return true;
}

bool isSolution(int current_step,
                int number_of_elements){
    return (current_step == (number_of_elements - 1));
}

void print(int number_of_elements){
    for(int i = 0; i < number_of_elements; i++){
        cout << vector_to_permute[current_solution[i]] << " ";
    }
    cout << endl;
}

void generatePermutations(int current_step,
                          int number_of_elements) {
    for (int i = 0; i < number_of_elements; i++) {
        current_solution[current_step] = i;

        if (isValid(current_step) &&
                isSolution(current_step, number_of_elements)) {

            if (isSolution(current_step, number_of_elements)) {
                print(number_of_elements);
            }
        }

        if (isValid(current_step)) {
            generatePermutations(current_step + 1, number_of_elements);
        }

    }
}

int main() {
    int number_of_elements;

    initializeData(number_of_elements, vector_to_permute);

    current_solution = (int*)malloc(number_of_elements*sizeof(int));

    generatePermutations(0, number_of_elements);

    return 0;
}