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

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    for (int i = listSize; i < 0; i--)
    {
        aList[i]
    }
    if (listSize < arrayCapacity)
    {
        aList[0] listSize++
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize < arrayCapacity)
    {
        aList[] listSize++
    }
}

void objPosArrayList::removeHead()
{
}

void objPosArrayList::removeTail()
{
}

objPos objPosArrayList::getHeadElement() const
{
}

objPos objPosArrayList::getTailElement() const
{
}

objPos objPosArrayList::getElement(int index) const
{
}