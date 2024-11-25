#include "GameMechs.h"

GameMechs::GameMechs()
{
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
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;

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

// do you need a destructor?
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

// More methods should be added here