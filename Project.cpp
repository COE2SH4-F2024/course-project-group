#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *mechanics_ptr;
Player *player;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{   
    Initialize();
    
    while(mechanics_ptr->getExitFlagStatus() == false)  
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
    player = new Player(mechanics_ptr);


}

void GetInput(void)
{
   if (MacUILib_hasChar()) {
        mechanics_ptr->setInput(MacUILib_getChar());

    }   
}

void RunLogic(void)
{
    char input = 'b';
    input = mechanics_ptr->getInput();

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
    //PROCESS INPUT
    objPos playerpos = player->getPlayerPos();
    int x = playerpos.pos->x;
    int y = playerpos.pos->y;
    char sym = playerpos.getSymbol();

    mechanics_ptr->displaychar(x,y,'%');
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

    MacUILib_uninit();
    delete mechanics_ptr;
    delete player;

}
