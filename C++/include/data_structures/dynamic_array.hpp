#include <cstdlib> // std::malloc(), std::realloc()

/*
	Brief
	-------
	Dynamic Array is an implementation from scratch based
	off of the SDL std::vector
*/

template<class T>
class DynamicArray
{
private:
	unsigned arrSize;
	unsigned numOfItems;
	T* itemList;
public:
	DynamicArray();
	~DynamicArray();
	int push_back(T);
	int pop_back();
	unsigned size();
	unsigned capacity();
	int resize(unsigned);
	int insert(unsigned, T);
	T& operator[](unsigned);
	T& at(unsigned);
	T& front();
	T& back();
	bool empty();
};

template<class T>
DynamicArray<T>::DynamicArray() : arrSize(0), numOfItems(0), itemList(nullptr) {}

template<class T>
DynamicArray<T>::~DynamicArray()
{
	if (itemList != nullptr) {
		std::free(itemList);
	}
}

template<class T>
int DynamicArray<T>::push_back(T item)
{
	if (arrSize == 0 && itemList == nullptr) {
		itemList = (T*) std::malloc(sizeof(T));
		arrSize++;
		itemList[0] = item;
		numOfItems = 1;
	} else if (arrSize == numOfItems) {
		arrSize *= 2;
		itemList = (T*) std::realloc(itemList, sizeof(T) * arrSize);
		itemList[numOfItems++] = item;
	} else {
		itemList[numOfItems++] = item;
	}

	return !!itemList; // If itemlist is NULL return 1
}

template<class T>
int DynamicArray<T>::pop_back()
{
	if (numOfItems > 0) {
		numOfItems--;
	}
}

template<class T>
unsigned DynamicArray<T>::size() { return numOfItems; }

template<class T>
unsigned DynamicArray<T>::capacity() { return arrSize; }

template<class T>
int DynamicArray<T>::resize(unsigned newSize)
{
	if (newSize < numOfItems) {
		return 1;
	} else {
		arrSize = newSize;
		itemList = (T*) std::realloc(itemList, sizeof(T) * arrSize);
		return 0;
	}
}

template<class T>
int DynamicArray<T>::insert(unsigned index, T item)
{
	if ((numOfItems + 1) < arrSize) {
		arrSize *= 2;
		itemList = (T*) std::realloc(itemList, sizeof(T) * arrSize);
	}
	// Move all elements over one making room for item
	for (unsigned i = numOfItems; i > index; i--) {
		itemList[i] = itemList[i - 1];
	}
	itemList[index] = item;
	return 0;
}

template<class T>
T& DynamicArray<T>::operator[](unsigned index) { return itemList[index]; }

template<class T>
T& DynamicArray<T>::at(unsigned index) { return itemList[index]; }

template<class T>
T& DynamicArray<T>::front()
{
	if (numOfItems > 0)
		return itemList[0];
}

template<class T>
T& DynamicArray<T>::back()
{
	if (numOfItems > 0)
		return itemList[numOfItems - 1];
}

template<class T>
bool DynamicArray<T>::empty() { return !numOfItems; }
