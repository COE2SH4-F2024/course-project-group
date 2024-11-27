#include "Player.h"

Player::Player(GameMechs *thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    objPos playerPos = objPos(7, 14, '*');

    // more actions to be included
}

Player::~Player()
{
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos array list
    return playerPos;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logicif (input != 0) // if not null character

    switch (mainGameMechsRef->getInput())
    {
    case 'w':
        if (myDir == DOWN)
        {
            break;
        }
        else
        {
            myDir = UP;
            break;
        }

    case 's':
        if (myDir == UP)
        {
            break;
        }
        else
        {
            myDir = DOWN;
            break;
        }

    case 'a':
        if (myDir == RIGHT)
        {
            break;
        }
        else
        {
            myDir = LEFT;
            break;
        }

    case 'd':
        if (myDir == LEFT)
        {
            break;
        }
        else
        {
            myDir = RIGHT;
            break;
        }
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    objPos player = playerPos.getObjPos();
    int x = player.pos->x;
    int y = player.pos->y;
    char sym = player.getSymbol();

    switch (myDir)
    {
    case STOP:
        break;

    default:
    case LEFT:
        x--;
        break;

    case RIGHT:
        x++;
        break;

    case DOWN:
        y++;
        break;

    case UP:
        y--;
        break;
    }

    if (mainGameMechsRef->(getBoardSizeX() - 1) == x)
    {
        x = 0;
    }
    else if (mainGameMechsRef->(getBoardSizeY() - 1) == y)
    {
        y = 0;
    }
    else if (y == 0)
    {
        y = getBoardSizeY() - 2;
    }
    else if (x == 0)
    {
        x = getBoardSizeX() - 2;
    }
    playerPos.setObjPos(x, y, sym);
}

// More methods to be added