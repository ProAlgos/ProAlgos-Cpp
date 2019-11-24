#include <iostream>
#include <algorithm>
#include <vector>

template<class T, bool (*comparator)(T&, T&) >
class Heap{
    private:
        std::vector<T> vector;		  //base vector of heap

        int size;					  //number of elements
        
        void heapify(int i);          //auxiliar function to maintain the heap structure when a element is removed 

    public:
        Heap();                       //constructor of the heap

        ~Heap();                      //destructor of the heap
        
        void insert(T key);        //function to insert a element into heap

        T remove();                 //function to remove a element from heap

        T top();                  //function to get the element on the top of heap

        int get_size();               //function to return the size of heap
       
};  

//method to get the size value    
template< class T, bool (*comparator)(T&, T&) >
int Heap<T, comparator>::get_size(){
    return this->size;
}

//function that returns the T element on the top of heap
//the complexity of this function is O(1)
template< class T, bool (*comparator)(T&, T&) >
T Heap<T, comparator>::top(){

    //if the heap is empty, throws exception -1, meaning that the heap is empty
    if (this->size <= 0) throw -1;

    //return the first element in the vector
    return this->vector[0];
}

//constructor method of heap
template< class T, bool (*comparator)(T&, T&) >
Heap<T, comparator>::Heap(){
    //sets the atributte size to 0
    this->size = 0;
}

//destructor method
template< class T, bool (*comparator)(T&, T&) >
Heap<T, comparator>::~Heap(){

}

/*
insert
-------------------
Function that inserts the key in the heap. This algorithm inserts the key at the end of the vector, and build the heap
(min or max) using the comparator function, by comparing the key element with its parent and swap they when necessary.

Time complexity
---------------
Average case: O(1) 
Worst case: O(logn), where n is the number of the elements of the heap

Space complexity
----------------
O(n), where n is the number of elements of the heap 
*/

template< class T, bool (*comparator)(T&, T&) >
void Heap<T, comparator>::insert(T key){ 
    //insert the key in the vector
    this->vector.push_back(key);

    //increments the attribute size   
    this->size++;

    //i receives the position where the key was inserted, the last position in this case
    int i = this->size - 1;    
    
    //parent receives the index of the node parent of the key
    int parent = (int)(i-1)/2;

    /*if the parent is smaller or greater (depends on comparator function) than the key, 
    so they are swapped and the variables i and parent receives it's recalculated values. 
    This will repeat until the key reaches the first position in the vector*/
    while (i != 0 && comparator(this->vector[parent], this->vector[i])) { 
       std::swap(this->vector[i], this->vector[parent]); 
       i = parent; 
       parent = (int)(i-1)/2;
    } 
}

/*
remove
-------------------
Function that removes the element of the top in the heap and return it. The function removes the element in the top 
and to maintain the struct correctily, puts the last element of the vector in the first position, and calls the heapify
function that will comparare the root with its sons searching for elements in wrong position, recursively, to maintain 
the structured desired. 

Time complexity
---------------
Average case: O(logn), where n is the number of the elements of the heap 
Worst case: O(logn)

Space complexity
----------------
O(n), where n is the number of elements of the heap 
*/

template< class T, bool (*comparator)(T&, T&) >
T Heap<T, comparator>::remove(){
    
    //if the heap is empty, throws exception -1, meaning that the heap is empty
    if (this->size <= 0) throw -1;

    //the smaller or greater (its depends on the comparator function) element is copied to root
    T root = this->vector[0]; 

    //the root of the heap receives the element with minor priority in the heap (the last position in the vector)
    this->vector[0] = this->vector[this->size-1];

    //the atribute size is decremented, because one of the elements of the heap is removed 
    this->size--; 

    //vector chages its size to the necessary size to comport the elements in the heap
    this->vector.resize(this->size);

    /*after the remotion of the smallest or greatest element (this depends on the comparator function),
    the heap is reorganized to maintain the structure desired*/
    this->heapify(0); 
    
    //return the the smaller or greater element in the heap
    return root; 
}

/*
heapify
----------------
Rebuild the structure after a element is removed from the heap. It does it selecting the smaller or 
grater element (depends on comparator funtion) between the root and it's sons. After that, if the element 
selected its not the root, this element and the root are swapped. This function is called recursively until 
the root becames the last element in the vector.

Time complexity
---------------
Worst case: O(logn), where n is the number of the elements of the heap 

Space complexity
----------------
O(n), where n is the number of elements of the heap 
*/

//int i - the index of the root
template< class T, bool (*comparator)(T&, T&) >
void Heap<T, comparator>::heapify(int i){

    //calculates the index of the left son
    int l = 2*i + 1; 

    //calculates the index of the right son
    int r = 2*i + 2; 

    //index of the element that has to be swapped
    int elem_to_change = i; 
    
    /*if the index of the left son its in the limits of vector and if it's smaller or greater (depends on your comparator function)
    than the root, elem_to_change receives the index of the left son*/
    if (l < this->size && comparator(this->vector[i], this->vector[l])) elem_to_change = l; 

    /*if the index of the right son its in the limits of vector and if it's smaller or greater (depends on your comparator function)
    than the value of the element that has to be changed, elem_to_change receives the index of the right son*/
    if (r < this->size && comparator(this->vector[elem_to_change], this->vector[r])) elem_to_change = r; 
    
    /*if the smaller or greater element between the root and the sons isn't the root, the root and this 
    element are swapped recursively until the vector reaches the end*/
    if (elem_to_change != i) { 
        std::swap(this->vector[i], this->vector[elem_to_change]); 
        this->heapify(elem_to_change); 
    } 
}
