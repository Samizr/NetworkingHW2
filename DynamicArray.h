//
// Created by Sami on 1/7/2018.
//

#ifndef WET_2_DYNAMICARRAY_H
#define WET_2_DYNAMICARRAY_H

#include <cstdlib>
#include <cassert>
#include <iostream>

#define EXPANTION_RATIO 2
#define SHRINK_RATIO 0.5
#define MAXIMAL_USED_RATIO 0.5
#define MINIMAL_USED_RATIO 0.25
#define MINIMAL_SIZE 12
#define AUTO 0
#define MANUAL 1

#define EXPAND 0
#define SHRINK 1

typedef int Operation;


/* ********************************************************************************************************************
 * ************************************    AN IMPLEMENTATION OF A DYNAMIC ARRAY    ************************************
 *
 *  ***************    This is an implementation of a dynamic array. The array works as follows:    *******************
 *   **** One initiates the array with an initial size.
 *
 *   **** Then only within the given range can an element be inserted using the insert function.
 *
 *   **** When (MAXIMAL USED RATIO)*size of the allocated array has been used up, the array enlarges itself,
 *   ****   using the expansion ratio defined. One can then insert an element in any given index in the new range.
 *
 *   **** When (MINIMAL USED RATIO)*size of the allocated array has been used up, the array shrinks itself,
 *   ****   using the shrink ratio defined. One can then insert an element only to any given index in the new range.
 *
 *   **** Always make sure that when you are done with an element, make use of the remove function to remove it,
 *   ****   as this is essential to maintaining your array in an O(n) memory state.
 *
 *   **** NOTE: To make full use of this dynamic array, make sure you have an implemented constructr,
 *   ****    destructor, and a '=' operator.
 * ********************************************************************************************************************/



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                          **                         **                                             //
//                                          ** DECLARATION             **                                             //
//                                          **                BEGIN    **                                             //
//                                          **                         **                                             //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN CLASS DEFINITIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
template<class T>
class DynamicArray {
private:
    bool type;
    int size;
    int cellsUsedNum;
    int shrinkBeginIndex;
    T *head;
    bool *used;

public:
    /*
     * Constructor for the DynamicArray.
     * Parameters:
     *      ~size: the size desired of the initial array. (Note that he size changes as described above).
     *      ~shrinkBeginIndex: Upon shrinking the array copies all the elements in it to the beginning of the new array.
     *                         This index will determine where to start copying, as in from what index.
     *                         Note that is must be smaller than MinimalSize/2 for proper use.
     *
     * Complexity:
     *      O(n)
     *      Fills in the used array with false.
     */
    explicit DynamicArray(int size, bool type, int shrinkBeginIndex = 0);

    /*
     * Copy constructor for the DynamicArray
     * Parameters:
     *      ~da: the dynamic array you want to copy.
     *
     *
     * Complexity:
     *      O(n)
     *      We copy two arrays of size 'n'.
     */
    DynamicArray(const DynamicArray &da);

    /*
     * Inserts and element in the array.
     * Parameters:
     *      ~element: the element to insert.
     *      ~index: the index to insert in.
     *
     * Complexity:
     *      O(1)
     *
     * Throws:
     *      InvalidIndex(): If index is negative or out of bounds.
     */
    void insert(const T &element, int index);

    /*
     * Removes an element from the array
     * Parameters:
     *      ~index: the index to remove from.
     *
     * Complexity:
     *      O(1)
     *
     * Throws:
     *      InvalidIndex(): If index is negative or out of bounds.
     */
    void remove(int index);

    /*
     * Checks if the cell with a given index is being used.
     * Parameters:
     *      ~element: the element to check.
     *      ~index: the index to insert in.
     *
     * Complexity:
     *      O(1)
     *
     * Throws:
     *      InvalidIndex(): If index is negative or out of bounds.
     */
    bool isUsed(int index);

    /*
     * Swaps two given elements in the array.
     * Parameters:
     *      ~index1: the first index.
     *      ~index2: the second index.
     *
     * Complexity:
     *      O(1)
     *
     * Throws:
     *      InvalidIndex(): If either indexes are negative, out of bounds, or unused
     */
    void swap(int index1, int index2);

    /*
     * Returns the size of the array
     * Parameters: NONE
     *
     * Complexity:
     *      O(1)
     */
    int getSize();

    /*
     * Returns the number of used cells in an array.
     * Parameters: NONE
     *
     * Complexity:
     *      O(1)
     */
    int getNumOfUsedCells();

    /*
     * Returns the element in index
     * Parameters:
     *      ~index: the index to retrieve.
     *
     * Complexity:
     *      O(1)
     * Throws:
     *      InvalidIndex(): If index is negative, out of bounds or unused.
     */
    T &operator[](int index);

    const T &operator[](int index) const;

    /*
     * Destructor for the dynamic array
     * Parameters: NONE
     *
     * Complexity:
     *      O(1)
     *      Simple frees the two arrays.
     */    ~DynamicArray();

    void expand();

    void shrink();

    //DEBUG HELPING FUNCTIONS:
    void printInfo();

    //CLASS EXCEPTION UNIT:
    class DAException : public std::exception {
    };

    class InvalidIndex : public DAException {
    };
};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  STATIC FUNCTION DECLARATIONS:  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

template<class T>
static void initiateNewArrays(int newSize, T **newHead, bool **newUsed);


template<class T>
static void fillNewArrays(int size, int newSize, T *head, T *newHead, bool *used, bool *newUsed, int shrinkBeginIndex,
                          Operation operation);
#ifndef NDEBUG
static int countUsedCells(int size, bool *used);
#endif

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
DynamicArray<T>::DynamicArray(int size, bool type, int shrinkBeginIndex) :
        type(type), size(size), cellsUsedNum(0), shrinkBeginIndex(shrinkBeginIndex){

    if (size < 0 || shrinkBeginIndex > MINIMAL_SIZE / 2)
        throw InvalidIndex();
    else if (size < MINIMAL_SIZE) {
        this->size = MINIMAL_SIZE;
    }
    head = new T[this->size];
    used = new bool[this->size];

    for (int i = 0; i < this->size; i++) {
        used[i] = false;
    }
}


template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray &da) : type(da.type), size(da.size),
                                                        cellsUsedNum(da.cellsUsedNum), shrinkBeginIndex(da.shrinkBeginIndex), head(new T[da.size]),
                                                        used(new bool[da.size]) {
    for (int i = 0; i < size; i++) {
        if (da.used[i]) {
            head[i] = da[i];
            used[i] = true;
        } else {
            used[i] = false;
        }
    }
    assert(cellsUsedNum == countUsedCells(size, used));
}

template<class T>
void DynamicArray<T>::insert(const T &element, int index) {
    if (index < 0 || index >= size)
        throw InvalidIndex();

    head[index] = element;
    if (!used[index]) {
        used[index] = true;
        cellsUsedNum++;
    }

    assert(cellsUsedNum == countUsedCells(size, used));
    if (cellsUsedNum >= static_cast<int>(MAXIMAL_USED_RATIO * size) && type==AUTO)
        expand();
}

template<class T>
void DynamicArray<T>::remove(int index) {
    if (index < 0 || index >= size)
        throw InvalidIndex();

    if (used[index]) {
        used[index] = false;
        cellsUsedNum--;
    }

    assert(cellsUsedNum == countUsedCells(size, used));
    if (cellsUsedNum < static_cast<int>(MINIMAL_USED_RATIO * size) && type==AUTO)
        shrink();
}

template<class T>
bool DynamicArray<T>::isUsed(int index) {
    if (index < 0 || index > size)
        throw InvalidIndex();
    return used[index];
}

template<class T>
void DynamicArray<T>::swap(int index1, int index2) {
    if (index1 < 0 || index2 < 0 || index1 > size || index2 > size || !used[index1] || !used[index2])
        throw InvalidIndex();
    if (index1 == index2)
        return;

    T temp = head[index2];
    insert(head[index1], index2);
    insert(temp, index1);
}

template<class T>
int DynamicArray<T>::getSize() {
    return size;
}

template<class T>
int DynamicArray<T>::getNumOfUsedCells() {
    return cellsUsedNum;
}

template<class T>
T &DynamicArray<T>::operator[](int index) {
    if (index < 0 || index >= size || !used[index])
        throw InvalidIndex();
    return head[index];
}


template<class T>
const T &DynamicArray<T>::operator[](int index) const {
    if (index < 0 || index >= size || !used[index])
        throw InvalidIndex();
    return head[index];
}


template<class T>
DynamicArray<T>::~DynamicArray() {
    delete[] head;
    delete[] used;
}

template<class T>
void DynamicArray<T>::printInfo() {
    using std::cout;
    using std::endl;
    const char *options[] = {"NOT USED", "USED"};
    cout << "Begin print data for given Dynamic Array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element number '" << i << "' in array is " << options[used[i]] << ". ";
        if (used[i]) {
            cout << "Field '" << i << "' has element: " << head[i];
        }
        cout << endl;
    }
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  PRIVATE FUNCTIONS IMPLEMENTATIONS:  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

template<class T>
void DynamicArray<T>::expand() {
    //ALLOCATION OF THE TWO NEW ARRAYS WHILE MAINTAINING A NO MEMORY LEAK ENVIROMENT:
    T *newHead = NULL;
    bool *newUsed = NULL;
    int newSize = size * EXPANTION_RATIO;
    initiateNewArrays(newSize, &newHead, &newUsed);
    //FILLING OF THE newUsed AND newHead ARRAYS;
    fillNewArrays(size, newSize, head, newHead, used, newUsed, shrinkBeginIndex, EXPAND);
    //IMPLEMENTATION OF NEW HEAD AND USED, DELETION OF THE PREVIOUS HEAD AND USED:
    delete[] head;
    delete[] used;
    head = newHead;
    used = newUsed;
    size = newSize;
}

template<class T>
void DynamicArray<T>::shrink() {
    if (size/2 <= MINIMAL_SIZE)
        return;
    //ALLOCATION OF THE TWO NEW ARRAYS WHILE MAINTAINING A NO MEMORY LEAK ENVIROMENT:
    T *newHead = NULL;
    bool *newUsed = NULL;
    int newSize = static_cast<int>(size * SHRINK_RATIO);
    initiateNewArrays(newSize, &newHead, &newUsed);

    //FILLING OF THE newUsed AND newHead ARRAYS;
    fillNewArrays(size, newSize, head, newHead, used, newUsed, shrinkBeginIndex, SHRINK);

    //IMPLEMENTATION OF NEW HEAD AND USED, DELETION OF THE PREVIOUS HEAD AND USED:
    delete[] head;
    delete[] used;
    head = newHead;
    used = newUsed;
    size = newSize;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  STATIC FUNCTIONS IMPLEMENTATIONS:  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
template<class T>
static void initiateNewArrays(int newSize, T **newHead, bool **newUsed) {
    try {
        *newHead = new T[newSize];
        *newUsed = new bool[newSize];
    } catch (std::bad_alloc) {
        delete[] *newHead;
        delete[] *newUsed;
        throw;
    }
    return;
}

template<class T>
static void fillNewArrays(int size, int newSize, T *head, T *newHead, bool *used, bool *newUsed, int shrinkBeginIndex,
                          Operation operation) {
    //OPTION ONE: FILL NEW ARRAYS AS WE EXPAND THE ARRAY:
    if (operation == EXPAND) {
        for (int i = 0; i < size; i++) {
            if (used[i]) {
                newHead[i] = head[i];
                newUsed[i] = true;
            } else {
                newUsed[i] = false;
            }
        }
        for (int i = size; i < newSize; i++) {
            newUsed[i] = false;
        }
    }
        //OPTION ONE: FILL NEW ARRAYS AS WE SHRINK THE ARRAY:
    else if (operation == SHRINK) {
        int oldIndex = 0, newIndex = shrinkBeginIndex;
        while (oldIndex < size) {
            assert(newIndex < newSize);
            if (used[oldIndex]) {
                newHead[newIndex] = head[oldIndex];
                newUsed[newIndex++] = true;
            }
            oldIndex++;
        }
        for (int i = 0; i < newSize; i++) {
            if (i == shrinkBeginIndex)
                i = newIndex;
            newUsed[i] = false;
        }
    }
}

#ifndef NDEBUG
static int countUsedCells(int size, bool *used) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (used[i])
            counter++;
    }
    return counter;
}
#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                          **                         **                                             //
//                                          ** IMPLEMENTATION          **                                             //
//                                          **                END      **                                             //
//                                          **                         **                                             //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#endif //WET_2_DYNAMICARRAY_H