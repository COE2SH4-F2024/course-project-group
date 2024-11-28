#include "food.h"
#include "time.h"
#include <stdlib.h>

food::food(GameMechs *thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    foodPos = objPos();
    foodSym = 'o'; //Food symbol
}

food::~food()
{
}

void food::generateFood(objPosArrayList blockOff) {
    //Time set for randomnesss
    srand(time(NULL));

    int i, j;
    int xRange = mainGameMechsRef->getBoardSizeX();
    int yRange = mainGameMechsRef->getBoardSizeY();
    int pos_bitV[xRange][yRange];
    int test_x;
    int test_y;

    //Initialize bit vector to 0
    for (i = 0; i < xRange; i++)
        for (j = 0; j < yRange; j++)
            pos_bitV[i][j] = 0;

    //Set all locations of the player to 1
    for(i=0; i < blockOff.getSize(); i++) {
        objPos player = blockOff.getElement(i);
        int player_x = player.pos->x;
        int player_y = player.pos->y;
        pos_bitV[player_x][player_y] = 1;

    }
    
    

   
    do 
    {
        //Generate a random value in the range of the board
        test_x = (rand() % (xRange - 3)) + 1;
        test_y = (rand() % (yRange - 3)) + 1;
    } while (pos_bitV[test_x][test_y] == 1);

    foodPos.setObjPos(test_x, test_y, foodSym);
    //Conceptual sake for future iterations
    pos_bitV[test_x][test_y] = 1;
}

objPos food::getFoodPos() const
{
    return foodPos;
}