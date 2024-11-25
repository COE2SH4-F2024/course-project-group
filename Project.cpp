#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;
char board[20][10];

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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
    int i,j;
    for(i=0; i < 20; i++) {
        for(j=0; j<10; j++) {
            if(i == 0 || i == 19 || j == 0 || j == 9) {
                board[i][j] = '#';
            }
            else {
                board[i][j] = ' ';
            }
        }
    } 

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    int i,j;
    for(i=0; i < 10; i++) {
        for(j=0; j<20; j++) {
            MacUILib_printf("%c",board[j][i]);
        }
        MacUILib_printf("\n");
    } 
          
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
