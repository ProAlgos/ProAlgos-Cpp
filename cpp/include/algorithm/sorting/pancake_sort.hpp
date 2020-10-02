// CPP code of Pancake Sorting Algorithm

#include <bits/stdc++.h>
using namespace std;

int maxNum(int arr[], int size){
    
    int max = 0;

    for(int i = 0; i < size; ++i) {

        if(arr[max] < arr[i]) {

            max = i;
        }
    }

    return max;
}

void flipArr(int *arr, int index) {
    
    int begin = 0;

    while(begin < index) {

        swap(arr[begin], arr[index]);
        begin++;
        index--;    
    }
}

void pancakeSort(int *arr, int size) {

    for(int i = size-1; i > 0; --i) {
         
        if(maxNum(arr, i+1) != i) {

            flipArr(arr, maxNum(arr, i+1));
            flipArr(arr, i);
        }
    }
}

void printArr(int arr[], int size) {

    for(int i = 0; i < size; ++i) {

        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main() {

    int size;

    cin>>size;

    int arr[size];

    for(int i = 0; i < size; ++i) {

        cin>>arr[i];
    }

    cout<<"Unsorted Array:";
    printArr(arr, size);
    
    pancakeSort(arr, size);

    cout<<"Sorted Array:";
    printArr(arr, size);

    return 0;
}