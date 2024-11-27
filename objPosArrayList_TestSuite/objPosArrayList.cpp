#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction,
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = 200;
    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

objPosArrayList::objPosArrayList(const objPosArrayList &other)
    : listSize(other.listSize), arrayCapacity(other.arrayCapacity)
{
    aList = new objPos[arrayCapacity];

    for (int i = 0; i < listSize; ++i)
    {
        aList[i] = other.aList[i];
    }
}

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

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize == arrayCapacity)
    {
        resizeArray();
    }

    for (int i = listSize; i > 0; --i)
    {
        aList[i] = aList[i - 1];
    }

    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize == arrayCapacity)
    {
        resizeArray(); // Resize if the array is full
    }

    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
    if (listSize > 0)
    {
        for (int i = 0; i < listSize - 1; ++i)
        {
            aList[i] = aList[i + 1];
        }
        aList[listSize - 1] = objPos();
        listSize--;
    }
}

void objPosArrayList::removeTail()
{
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