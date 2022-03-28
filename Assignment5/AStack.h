#include "Stack.h"
#include <string>
#include <iostream>

#ifndef ASTACK_H
#define ASTACK_H

template <typename E>

class AStack : public Stack<E>
{
private:
    int maxSize; // max size of Stack (size of allocated array)
    int stackSize; // number of elements in the Stack right now
    E* stackArray; // pointer of type E (will become the array)
    void IncreaseArraySize();
public:
    AStack(); // defualt constructor
    AStack(int size); // overloaded constructor
    ~AStack(); // destructor


    // reinitializes the stack
    void clear();


    // push an element onto the top of the stack
    // @param item: element being pushed
    void push(const E& item);

    //remove the element from the top of the stack
    // return: the element at the top
    E pop();

    E topValue();


    int length();
};


template <typename E>
void AStack<E>::IncreaseArraySize()
{
    if (stackSize >= maxSize)
    {
        E* tempStackArray;
        tempStackArray = new E[maxSize * 2]; // doubles the size of the array
        for (int i = 0; i < maxSize; i++)
        {
            tempStackArray[i] = stackArray[i];
        }
        delete[] stackArray;
        stackArray = tempStackArray;
    }
}


template <typename E>
AStack<E>::AStack(int size)
{
    maxSize = size;
    stackSize = 0;
    stackArray = new E[maxSize];
}

template <typename E>
AStack<E>::~AStack()
{
    delete[] stackArray;
}

template <typename E>
void AStack<E>::clear()
{
    delete[] stackArray;
    stackSize = 0;
    stackArray = new E[maxSize];
}

template <typename E>
void AStack<E>::push(const E& item)
{
    IncreaseArraySize();

    for (int i = stackSize; i > 0;  i--) { // moving the elements to the right of the array before inserting value
        stackArray[i] = stackArray[i-1];
    }
    stackArray[0] = item;
    stackSize++;
}

template <typename E>
E AStack<E>::pop()
{
    if (stackSize == 0)
    {
       std::cerr << "Stack is empty.";
       return 0;
    }
    E item = stackArray[0];
    for (int i = 0; i < stackSize - 1;  i++)
    { // moving the elements to the right of the array before inserting value
        stackArray[i] = stackArray[i+1];
    }
    stackSize--;
    return item;
}

template <typename E>
E AStack<E>::topValue()
{
    return stackArray[0];
}

template <typename E>
int AStack<E>::length()
{
    return stackSize;
}

#endif