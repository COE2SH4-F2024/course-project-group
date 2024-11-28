#include "Player.h"

Player::Player(GameMechs *thisGMRef, food *thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    foodRef = thisFoodRef;

    myDir = STOP;
    objPos playerPos;
    //playerPos = objPos(14, 7, '*');
    playerPos = objPos(4, 2, '*');
    playerPosList = new objPosArrayList();

    int i;
    // for(i=0; i<8; i++) {
    //     objPos playerPoscopy;
    //     playerPoscopy = objPos(10+*2*i, 7, '*');
    //     playerPosList->insertHead(playerPoscopy);

    // }
    playerPosList->insertHead(playerPos);


    // more actions to be included
}

Player::~Player()
{
    // delete any heap members here
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos array list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logicif (input != 0) // if not null character

    if(mainGameMechsRef->getInput() != 0)  // if not null character
    {
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
}

void Player::movePlayer()
{
    objPos foodPos = foodRef->getFoodPos();
    int food_x = foodPos.pos->x;
    int food_y = foodPos.pos->y;


    // PPA3 Finite State Machine logic
    objPos player = playerPosList->getHeadElement();
    int x = playerPosList->getHeadElement().pos->x;
    int y = playerPosList->getHeadElement().pos->y;
    char sym = playerPosList->getHeadElement().getSymbol();

    //
    int i;
    objPos test_col;
    int test_col_x, test_col_y;

    for(i=1; i < playerPosList->getSize(); i++) {
        test_col_x = playerPosList->getElement(i).pos->x;
        test_col_y = playerPosList->getElement(i).pos->y;
        if(test_col_x == x && test_col_y == y) {
            mainGameMechsRef->setLoseFlag();
        }
    }

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

    if ((mainGameMechsRef->getBoardSizeX() - 1) == x)
    {
        x = 1;
    }
    else if ((mainGameMechsRef->getBoardSizeY() - 1) == y)
    {
        y = 1;
    }
    else if (y == 0)
    {
        y = mainGameMechsRef->getBoardSizeY() - 2;
    }
    else if (x == 0)
    {
        x = mainGameMechsRef->getBoardSizeX() - 2;
    }

    objPos moved_player = objPos(x,y,sym);


    if(x == food_x && y == food_y) {
        playerPosList->insertHead(moved_player);
        foodRef->generateFood(*playerPosList);
        mainGameMechsRef->incrementScore();
    
    }
    else {
        playerPosList->insertHead(moved_player);
        playerPosList->removeTail();
    }


    

}

// More methods to be added