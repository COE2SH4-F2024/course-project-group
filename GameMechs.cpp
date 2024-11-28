#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    /* Default constructor that initializes the board to size(30,15)
    and fills the border with #'s
    */
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 30;
    boardSizeY = 15;

    int i,j;
    board = new int*[boardSizeX];

	for(int i = 0; i < boardSizeX; i++)
	{
		board[i] = new int[boardSizeY];
	}

    for(i=0; i < boardSizeX; i++) {
        for(j=0; j<boardSizeY; j++) {
            //if on the border set corresponding index to #
            if(i == 0 || i == (boardSizeX-1) || j == 0 || j == (boardSizeY-1)) {
                board[i][j] = '#';
            }
            else {
                board[i][j] = ' ';
            }
        }
    } 
}

GameMechs::GameMechs(int boardX, int boardY)
{
    /* Constructor that initializes the board to size given values
    and fills the border with #'s
    */
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;

    //If the board is too small set to default values
    if(boardSizeX < 3) {
        boardSizeX = 30;
    } 
    if(boardSizeY < 3) {
        boardSizeY = 15;
    }

    board = new int*[boardSizeX];

	for(int i = 0; i < boardSizeX; i++)
	{
		board[i] = new int[boardSizeY];
	}

    int i,j;
    for(i=0; i < boardSizeX; i++) {
        for(j=0; j<boardSizeY; j++) {
            if(i == 0 || i == (boardSizeX-1) || j == 0 || j == (boardSizeY-1)) {
                board[i][j] = '#';
            }
            else {
                board[i][j] = ' ';
            }
        }
    } 
}

GameMechs::~GameMechs()
{
    int i;
	for(i=0; i < boardSizeX; i++) {
		delete[] board[i];
	}
	delete[] board;

}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{ 
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{   
    input = 0;
}


//Sets a part of the board to a given value
void GameMechs::displaychar(int x, int y, char sym) {

    board[x][y] = sym;
}

void GameMechs::printBoard() {
    int i,j;
   
    for(i=0; i < boardSizeY; i++) {
        for(j=0; j<boardSizeX; j++) {
            MacUILib_printf("%c",board[j][i]);
        }
        MacUILib_printf("\n");      
    } 
    MacUILib_printf("Score: %d",score);
}

//Resets the board to only spaces while still keeping the borders intact
void GameMechs::clearBoard() {
    int i,j;
    for(i=1; i < boardSizeY-1; i++) 
        for(j=1; j<boardSizeX-1; j++)
            board[j][i] = ' ';
        
}