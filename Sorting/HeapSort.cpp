#include <iostream>
#include <vector>

#include "SortingUtils.h"

using namespace std;


void heapify(vector<int> &heap,int parent,int size, int order){
  int child = (parent*2)+1, temp;
  while(child<size){//travels down
      displayState(heap);
    if((order*heap[child])<(order*heap[child+1])&&(child+1<size)){
      child++;//child refers to the larger/smaller of the two children
    }
    else{}
    if((order*heap[parent])<(order*heap[child])){
      swap(heap[parent],heap[child]);
    }
    parent = child;
    child=(parent*2)+1;
  }
}
void heapsort(vector<int> &heap,int size, int order){
  int temp,n = size;
  while(n>0){
    temp = heap[n-1];
    heap[n-1] = heap[0];
    heap[0]=temp;
    n-=1;
    heapify(heap,0,n, order);
  }
}
void make_heap(vector<int> &heap, int size, int order){
    for(int x = (size/2)-1; x>=0;x--){ //Searches and reheaps all non-leaf node
    heapify(heap, x, size, order);
  }
}
int main(){
    size_t size;
    getInputSize(size);
    vector<int> values(size);
    getInputValues(values, size);
    int order;
    string orderText;
    getOrder(order, orderText);
    make_heap(values, size, order);
    heapsort(values, size, order);
    cout << "The result in " + orderText + " order is as follows : " << endl;
    displayState(values);
    return 0;
}
