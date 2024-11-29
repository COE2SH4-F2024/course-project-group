#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
private:
    objPos *aList;
    int listSize;
    int arrayCapacity;

    void resizeArray();

public:
    objPosArrayList();
    ~objPosArrayList();

    objPosArrayList(const objPosArrayList &other);
    objPosArrayList &operator=(const objPosArrayList &other);

    int getSize() const;
    void lengthenSnake(int num);
    void insertHead(objPos thisPos);
    void insertTail(objPos thisPos);
    void removeHead();
    void removeTail();
    void removeElement(int index);

    objPos getHeadElement() const;
    objPos getTailElement() const;
    objPos getElement(int index) const;
};

#endif