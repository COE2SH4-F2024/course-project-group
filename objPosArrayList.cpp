#include "objPosArrayList.h"

objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = 200; // default arraylist capacity
    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

// copy constructor
objPosArrayList::objPosArrayList(const objPosArrayList &other)
    : listSize(other.listSize), arrayCapacity(other.arrayCapacity)
{
    aList = new objPos[arrayCapacity];

    for (int i = 0; i < listSize; ++i)
    {
        aList[i] = other.aList[i];
    }
}

// copy assignment constructor
objPosArrayList &objPosArrayList::operator=(const objPosArrayList &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] aList;

    listSize = other.listSize;
    arrayCapacity = other.arrayCapacity;
    aList = new objPos[arrayCapacity];

    for (int i = 0; i < listSize; ++i)
    {
        aList[i] = other.aList[i];
    }

    return *this;
}

// returns size of snake
int objPosArrayList::getSize() const
{
    return listSize;
}

// inserts objPos object as head of snake
void objPosArrayList::insertHead(objPos thisPos)
{
    // resizes the array if it exceeds 200 elements
    if (listSize == arrayCapacity)
    {
        resizeArray();
    }

    // shift all elements right
    for (int i = listSize; i > 0; --i)
    {
        aList[i] = aList[i - 1];
    }

    // insert thisPos as head
    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize == arrayCapacity)
    {
        resizeArray(); // Resize if the array is full
    }

    // if array is not full, insert thisPos to the end.
    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
    if (listSize > 0)
    {
        // shifts all elements left.
        for (int i = 0; i < listSize - 1; ++i)
        {
            aList[i] = aList[i + 1];
        }

        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    // removes tail by decreasing list size
    if (listSize > 0)
    {
        listSize--;
    }
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}

// used to resize array if it exceeds 200 elements
void objPosArrayList::resizeArray()
{
    arrayCapacity *= 2;
    objPos *newArray = new objPos[arrayCapacity];

    for (int i = 0; i < listSize; ++i)
    {
        newArray[i] = aList[i];
    }

    delete[] aList;
    aList = newArray;
}