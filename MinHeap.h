//
// Created by Sami on 1/8/2018.
//

#ifndef WET_2_MINHEAP_H
#define WET_2_MINHEAP_H

#include "DynamicArray.h"

#define FIRST_INDEX_IN_ARRAY 1

/* ********************************************************************************************************************
 * ************************************    AN IMPLEMENTATION OF A MINIMUM HEAP    *************************************
 *
 *  ********* This is an implementation of a dynamic array based minimum heap. The array works as follows: *************
 *   **** One initiates the array heap with an array of desired elements.
 *
 *   **** The structure provides basic operations like finding minimal element, insertion, deleting minimal elements...
 *
 *   **** NOTE: Fill here with all the required constructors and overriden operators...
 * ********************************************************************************************************************/



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                          **                         **                                             //
//                                          ** DECLARATION             **                                             //
//                                          **                BEGIN    **                                             //
//                                          **                         **                                             //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN CLASS DEFINITIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

template<class T>
class MinHeap {
private:
    //CLASS ELEMENTS:
    DynamicArray<T> array;

    //CLASS PRIVATE FUNCTIONS:
    void siftDown(int index);

    void siftUp(int index);

public:
    //CLASS PUBLIC FUNCTIONS:
    /*
     * Constructs a min heap from given elements
     * Parameters:
     *      ~data: the data array to make a heap from.
     *      ~n: size of the array.
     *
     * Complexity:
     *      O(n)
     *      Using the semi-complete tree algortihm proven in class.
     */
    MinHeap(const T *data, int n);

    /*
     * Inserts a new element in the heap.
     * Parameters:
     *      ~element: the element to add.
     *
     * Complexity:
     *      O(logn)
     *      Using the sift up algorithm as proven in class.
     */
    void insert(const T &element);

    /*
    * Decreases the element in a given index.
    * Parameters:
    *      ~index: the index in of the element to change
    *      ~element: the new value of the element (key).
    *
    * Complexity:
    *      O(logn)
    *      Using the sift up algorithm as proven in class.
     */
    void decKey(int index, const T &element);

    /*
    * Returns the minimal element in the heap.
    * Parameters: NONE
    *
    * Complexity:
    *      O(1)
    */
    const T &findMin();

    /*
     * Deletes the minimal element in the heap
     * Parameters: NONE
     *
     * Complexity:
     *      O(logn)
     *      Using the sift down algorithm as proven in class.
     */
    void delMin();

    /*
     * Destructs the heap.
     * Parameters: NONE
     *
     * Complexity:
     *      O(1)
     */
    ~MinHeap();

    //DEBUG FUNCTIONS:
    bool isHeap();

    void printInfo();

    bool isInHeap(const T &element);

    //CLASS EXCEPTIONS:
    class MinHeapException : public std::exception {
    };

    class Empty : public MinHeapException {
    };

    class InvalidIndex : public MinHeapException {
    };

};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  STATIC FUNCTION DECLARATIONS:  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

template<class T>
static const T &min(const T &a, const T &b);


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                          **                         **                                             //
//                                          ** DECLARATION             **                                             //
//                                          **                END      **                                             //
//                                          **                         **                                             //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                          **                         **                                             //
//                                          ** IMPLEMENTATION          **                                             //
//                                          **                BEGIN    **                                             //
//                                          **                         **                                             //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  PUBLIC FUNCTIONS IMPLEMENTATION:  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


template<class T>
MinHeap<T>::MinHeap(const T *data, int n) : array(3 * n, AUTO, FIRST_INDEX_IN_ARRAY) {
    //INITIATION AND FILLING OF THE ARRAY:
    for (int i = 0; i < n; i++) {
        array.insert(data[i], i + 1); //INSERTED WITH i+1 TO EASE THE USE OF THE SIFT ALGORITHMS.
    }
    //SIFT DOWN ON EACH ELEMENT FROM N/2 TO 1:
    for (int i = n / 2; i > 0; i--) {
        siftDown(i);
    }
}

template<class T>
void MinHeap<T>::insert(const T &element) {
    int index = array.getNumOfUsedCells() + 1;
    assert(!isInHeap(element));
    assert(!array.isUsed(index));
    array.insert(element, index);
    siftUp(index);
}

template<class T>
void MinHeap<T>::decKey(int index, const T &element) {
    if (index < 1 || index > array.getNumOfUsedCells() || array[index] < element)
        throw InvalidIndex();

    array.insert(element,index);
    siftUp(index);
}

template<class T>
const T &MinHeap<T>::findMin() {
    if (!array.isUsed(1))
        throw Empty();
    return array[1];
}

template<class T>
void MinHeap<T>::delMin() {
    if (!array.isUsed(1)) {
        throw Empty();
    }
    int lastElementIndex = array.getNumOfUsedCells();
    array.swap(1, lastElementIndex);
    array.remove(lastElementIndex);
    siftDown(1);
}


template<class T>
MinHeap<T>::~MinHeap() {

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  PRIVATE FUNCTION IMPLEMENTATIONS:  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
template<class T>
void MinHeap<T>::siftDown(int index) {
    //CHECK IF THE INDEX PARAMETER IS LEGAL:
    int leftSon = 2 * index;
    int rightSon = 2 * index + 1;
    if (index < 1 || index > array.getNumOfUsedCells() || leftSon > array.getNumOfUsedCells() ||
        !array.isUsed(index) || !array.isUsed(leftSon))
        return;

    //CHECK IF INDEX ONLY HAS LEFT SON AND NO RIGHT SON.
    if (rightSon > array.getNumOfUsedCells() || !array.isUsed(rightSon)) {
        if (array[index] > array[leftSon]) {
            array.swap(index, leftSon);
        }
        return;
    }
//FINALLY, CHECK IF INDEX IS BIGGER THE SONS AND REPLACE IF IT IS.
    if (array[index] > min(array[leftSon], array[rightSon])) {
        int minSon = array[leftSon] < array[rightSon] ? leftSon : rightSon;
        array.swap(minSon, index);
        siftDown(minSon);
    }
}

template<class T>
void MinHeap<T>::siftUp(int index) {
    int father = index / 2;
    if (index < 1 || father < 1)
        return;
    else if (array[index] < array[father]) {
        array.swap(index, father);
        siftUp(father);
    }
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  DEBUG FUNCTION IMPLEMENTATIONS:  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
template<class T>
bool MinHeap<T>::isHeap() {
    for (int i = 1; i <= array.getNumOfUsedCells(); i++) {
        assert(array.isUsed(i));
        if (array.isUsed(2 * i) && array[i] > array[2 * i]) {
            std::cout << "Element number '" << i << "' in array is bigger than element number '" << 2 * i
                      << "'." << std::endl;
            return false;
        }
        if (array.isUsed(2 * i + 1) && array[i] > array[2 * i + 1]) {
            std::cout << "Element number '" << i << "' in array is bigger than element number '" << 2 * i + 1
                      << "'." << std::endl;
            return false;
        }
    }
    std::cout << " ---> VERY MUCH A HEAP!" << std::endl << std::endl;
    return true;
}

template<class T>
void MinHeap<T>::printInfo() {
    array.printInfo();
}

template<class T>
bool MinHeap<T>::isInHeap(const T &element) {
    for (int i = 1; i <= array.getNumOfUsedCells(); i++) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  STATIC FUNCTIONS IMPLEMENTATIONS:  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
template<class T>
static const T &min(const T &a, const T &b) {
    return (a < b ? a : b);
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                          **                         **                                             //
//                                          ** IMPLEMENTATION          **                                             //
//                                          **                END      **                                             //
//                                          **                         **                                             //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#endif //WET_2_MINHEAP_H