#include <cstdlib> // std::malloc(), std::realloc()

/*
    Author
    ------
    Ryan Young (github.com/ryoung9550)

    Brief
    -------
    Dynamic Array is an implementation from scratch based
    off of the STL std::vector
*/

template<class T>
class DynamicArray
{
private:
    size_t arrSize;
    size_t numOfItems;
    T* itemList;
public:
    DynamicArray();
    ~DynamicArray();
    int push_back(const T&);
    int pop_back();
    size_t size() const;
    size_t capacity() const;
    int resize(const size_t&);
    int insert(const size_t&, const T&);
    T& operator[](const size_t&) const;
    T& at(const size_t&) const;
    T& front() const;
    T& back() const;
    bool empty() const;
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
int DynamicArray<T>::push_back(const T& item)
{
    if (arrSize == 0 and itemList == nullptr) {
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
size_t DynamicArray<T>::size() const { return numOfItems; }

template<class T>
size_t DynamicArray<T>::capacity() const { return arrSize; }

template<class T>
int DynamicArray<T>::resize(const size_t& newSize)
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
int DynamicArray<T>::insert(const size_t& index, const T& item)
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
T& DynamicArray<T>::operator[](const size_t& index) const { return itemList[index]; }

template<class T>
T& DynamicArray<T>::at(size_t index) const { return itemList[index]; }

template<class T>
T& DynamicArray<T>::front() const
{
    if (numOfItems > 0)
        return itemList[0];
    else
        return null;
}

template<class T>
T& DynamicArray<T>::back() const
{
    if (numOfItems > 0)
        return itemList[numOfItems - 1];
    else
        return null
}

template<class T>
bool DynamicArray<T>::empty() const { return !numOfItems; }
