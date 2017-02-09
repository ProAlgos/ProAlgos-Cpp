#include <iostream>
#include <vector>

#include "SortingUtils.h"

using namespace std;


void maxheapify(vector<int> &heap,int parent,int size){
  int child = (parent*2)+1, temp;
  while(child<size){//travels down
    if(heap[child]<heap[child+1]&&(child+1<size)){
      child++;//child refers to the larger of the two children
    }
    if(heap[parent]<heap[child]){
      temp = heap[parent];
      heap[parent] = heap[child];
      heap[child] = temp;
    }
    parent = child;
    child= (parent*2)+1;
  }
}
void heapsort(vector<int> &heap,int size){
  int temp,n = size;
  while(n>0){
    temp = heap[n-1];
    heap[n-1] = heap[0];
    heap[0]=temp;
    n-=1;
    maxheapify(heap,0,n);
  }
}
void make_heap(vector<int> &heap, int size){
    for(int x = (size/2)-1; x>=0;x--){ //Searches and reheaps all non-leaf node
    maxheapify(heap, x, size);
  }
}

int main(){
    size_t size;
    getInputSize(size);
    vector<int> values(size);
    getInputValues(values, size);
    //get order here when main code complete
    make_heap(values, size);
    heapsort(values, size);
    displayState(values);
    return 0;
}
