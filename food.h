#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

class food
{
    public:
        
        
        food(GameMechs *thisGMRef);
        ~food();
        
        objPosArrayList* getFoodPos() const;
        void generateFood(objPosArrayList blockOff_pl, char foodType);   
    private:
        objPos firstfoodPos;
        GameMechs *mainGameMechsRef;
        objPosArrayList *foodBucket;
        char foodSym;


};



#endif