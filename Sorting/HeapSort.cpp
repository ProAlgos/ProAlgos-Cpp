#include <iostream>
#include <vector>

#include "SortingUtils.h"

using namespace std;


void heapify(vector<int> &heap,int parent,int size, int order, bool showState){
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
    displayState(heap);
  }
}
void heapsort(vector<int> &heap,int size, int order,bool showState){
  int temp,n = size;
  while(n>0){
    swap(heap[0], heap[n-1]);
    n-=1;
    heapify(heap,0,n, order, showState);
  }
}
void make_heap(vector<int> &heap, int size, int order, bool showState){
    for(int x = (size/2)-1; x>=0;x--){ //Searches and reheaps all non-leaf node
    heapify(heap, x, size, order, showState);
    if(showState) displayState(heap);
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
    bool showState;
    getWhetherToShowState(showState);
    if(showState) cout << endl << "Showing stages of making heap" << endl;
    make_heap(values, size, order, showState);
    if (showState){
        cout << "Initial Heap Has been Made" << endl << endl;
        cout <<"Now Showing State During Heapify Operation" << endl;
    }
    heapsort(values, size, order, showState);
    cout << "The result in " + orderText + " order is as follows : " << endl;
    displayState(values);
    return 0;
}
