#include "food.h"
#include "time.h"
#include <stdlib.h>


food::food(GameMechs *thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    foodPos = objPos();
    foodSym = 'o';
}

food::~food()
{

}

void food::generateFood(objPos blockOff) {
    srand(time(NULL));
    int i,j;
    int xRange = mainGameMechsRef->getBoardSizeX();
    int yRange = mainGameMechsRef->getBoardSizeY();
    int pos_bitV[xRange][yRange];
    int test_x;
    int test_y;

    for(i=0; i < xRange; i++)
        for(j=0; j < yRange; j++)
            pos_bitV[i][j] = 0;

    objPos player = blockOff.getObjPos();
    int player_x = player.pos->x;
    int player_y = player.pos->y;
    pos_bitV[player_x][player_y] = 1;

   
    do 
    {
        test_x = (rand () % (xRange-3))+1;
        test_y = (rand () % (yRange-3))+1;
    } 
    while (pos_bitV[test_x][test_y] == 1);
    
    foodPos.setObjPos(test_x,test_y,foodSym);
    pos_bitV[test_x][test_y] = 1;

    




}

objPos food::getFoodPos() const
{
    return foodPos;
}