#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "food.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *mechanics_ptr;
Player *player;
food *food_ptr;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{
    Initialize();
    
    while(mechanics_ptr->getExitFlagStatus() == false && mechanics_ptr->getLoseFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
}

void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    mechanics_ptr = new GameMechs();
    food_ptr = new food(mechanics_ptr);
    player = new Player(mechanics_ptr, food_ptr);

    objPosArrayList playerpos = *player->getPlayerPos();
    food_ptr->generateFood(playerpos);
}

void GetInput(void)
{
    if (MacUILib_hasChar())
    {
        mechanics_ptr->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    char input = 'q';
    int i, pl_x, pl_y;
    char pl_sym;

    input = mechanics_ptr->getInput();


    objPosArrayList playerpos = *player->getPlayerPos();
    for(i=0; i < playerpos.getSize(); i++) {
        pl_x = playerpos.getElement(i).pos->x;
        pl_y = playerpos.getElement(i).pos->y;
        pl_sym = playerpos.getElement(i).getSymbol();
        mechanics_ptr->displaychar(pl_x,pl_y,pl_sym);

    }

    switch(input)
        {                      
            case ' ':  // exit
                mechanics_ptr->setExitTrue();
                break;
            case 'k':
                food_ptr->generateFood(playerpos);

            default:
                player->updatePlayerDir();
                player->movePlayer();
                break;
        }
    //PROCESS INPUT


    objPos foodPos = food_ptr->getFoodPos();
    int food_x = foodPos.pos->x;
    int food_y = foodPos.pos->y;
    char food_sym = foodPos.getSymbol();
    

    mechanics_ptr->displaychar(food_x,food_y,food_sym);
    
    mechanics_ptr->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    mechanics_ptr->printBoard();
    mechanics_ptr->clearBoard();
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{
    MacUILib_clearScreen();  
    if(mechanics_ptr->getLoseFlagStatus()) {
        MacUILib_printf("You Lost");
    }

    MacUILib_uninit();
    delete mechanics_ptr;
    delete player;
    delete food_ptr;
}
