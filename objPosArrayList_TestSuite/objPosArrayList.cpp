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
    if (listSize < arrayCapacity)
    {
        for (int i = listSize; i > 0; i--)
        {
            aList[i] = aList[i--];
        }

        aList[0].symbol = thisPos.symbol;
        listSize++;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize < arrayCapacity)
    {
        aList[listSize].symbol = thisPos.symbol;
        listSize++;
    }
}

void objPosArrayList::removeHead()
{
    for (int i = 0; i < listSize; i++)
    {
        aList[i].symbol = aList[i].symbol
    }
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