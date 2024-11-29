#include "food.h"
#include "time.h"
#include <stdlib.h>

food::food(GameMechs *thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    //firstfoodPos = objPos(4,4,'o');
    foodSym = 'o'; //Food symbol
    foodBucket = new objPosArrayList();
    //foodBucket->insertHead(firstfoodPos);

}

food::~food()
{
    delete foodBucket;
}

void food::generateFood(objPosArrayList blockOff, char foodType) {
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

    //Set all locations of the player in the bitvector to 1
    for(i=0; i < blockOff.getSize(); i++) {
        objPos player = blockOff.getElement(i);
        int player_x = player.pos->x;
        int player_y = player.pos->y;
        pos_bitV[player_x][player_y] = 1;
    }

    //Set all locations of the food in the bitvector to 1
    for(i=0; i < foodBucket->getSize(); i++) {
        objPos food = foodBucket->getElement(i);
        int food_x = food.pos->x;
        int food_y = food.pos->y;
        pos_bitV[food_x][food_y] = 1;
    }
    
   
    do 
    {
        //Generate a random value in the range of the board
        test_x = (rand() % (xRange - 3)) + 1;
        test_y = (rand() % (yRange - 3)) + 1;
    } while (pos_bitV[test_x][test_y] == 1);

    objPos foodPos = objPos(test_x, test_y, foodType);
    foodBucket->insertHead(foodPos);
}

objPosArrayList* food::getFoodPos() const
{
    return foodBucket;
}