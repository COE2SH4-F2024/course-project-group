#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs mechanics = GameMechs();

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{   
    Initialize();
    
    while(mechanics.getExitFlagStatus() == false)  
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



}

void GetInput(void)
{
   if (MacUILib_hasChar()) {
        mechanics.setInput(MacUILib_getChar());

    }   
}

void RunLogic(void)
{
    char input;
    input = mechanics.getInput();

    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
                mechanics.setExitTrue();
                break;
            case 'w':
                //
                break;
            case 's':
                //k;
            case 'd':
                //
                break;
            case 'a':
                //
                break;

            default:
                break;
        }
    }
    //PROCESS INPUT
    mechanics.clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
          
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();

}
