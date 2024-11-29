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
    mechanics_ptr = new GameMechs(); //Game Mechanics Pointer
    food_ptr = new food(mechanics_ptr); //Food pointer
    player = new Player(mechanics_ptr, food_ptr); //player pointer

    objPosArrayList playerpos = *player->getPlayerPos(); //get array of player locations
    objPosArrayList foodpos = *food_ptr->getFoodPos(); //get array of food locations


    food_ptr->generateFood(*player->getPlayerPos(), '/'); 
    food_ptr->generateFood(*player->getPlayerPos(), 'm'); 
    food_ptr->generateFood(*player->getPlayerPos(), 'o'); 
    food_ptr->generateFood(*player->getPlayerPos(), 'o'); 
    food_ptr->generateFood(*player->getPlayerPos(), 'o'); 

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
    char input;
    int i, pl_x, pl_y; //player coordinates
    char pl_sym; //player symbol

    int food_x, food_y;
    char food_sym;

    input = mechanics_ptr->getInput();


    objPosArrayList playerpos = *player->getPlayerPos();

    //change every player element on the board
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
            default:
                player->updatePlayerDir();
                player->movePlayer();
                break;
        }
        mechanics_ptr->clearInput(); //resets input to null

    objPosArrayList foodpos = *food_ptr->getFoodPos();
    
    //change every food element on the board
    for(i=0; i < foodpos.getSize(); i++) {
        food_x = foodpos.getElement(i).pos->x;
        food_y = foodpos.getElement(i).pos->y;
        food_sym = foodpos.getElement(i).getSymbol();
        mechanics_ptr->displaychar(food_x,food_y,food_sym);

    }
    
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    mechanics_ptr->printBoard();
    //Reset board to be blank besides borders
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
