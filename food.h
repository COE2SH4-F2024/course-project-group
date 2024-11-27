#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"

class food
{
    public:
        
        
        food(GameMechs *thisGMRef);
        ~food();
        
        objPos getFoodPos() const;
        void generateFood(objPos blockOff);   
    private:
        objPos foodPos;
        GameMechs *mainGameMechsRef;
        char foodSym;


};



#endif