#include "Player.h"

Player::Player(GameMechs *thisGMRef, food *thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    foodRef = thisFoodRef;

    myDir = STOP;
    objPos playerPos;

    //Starts player in roughly the middle of the board
    playerPos = objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');

    playerPosList = new objPosArrayList();

    //Inserts player at the front  
    playerPosList->insertHead(playerPos);


}

Player::~Player()
{
    delete playerPosList;
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
    //Get the position and symbol of the head of the player
    int x = playerPosList->getHeadElement().pos->x; 
    int y = playerPosList->getHeadElement().pos->y;
    char sym = playerPosList->getHeadElement().getSymbol();


    int i;
    //testing collision with other parts of the snake body
    objPos test_col;
    int test_col_x, test_col_y;

    for(i=1; i < playerPosList->getSize(); i++) {
        test_col_x = playerPosList->getElement(i).pos->x;
        test_col_y = playerPosList->getElement(i).pos->y;
        if(test_col_x == x && test_col_y == y) {
            //if any part of the snake body collides, lose game
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

    //new poistion of the head
    objPos moved_player = objPos(x,y,sym);


    if(x == food_x && y == food_y) {
        //if the head collids with the food
        playerPosList->insertHead(moved_player);
        //generate new food
        foodRef->generateFood(*playerPosList);
        //increment score
        mainGameMechsRef->incrementScore();
        //DONT remove tail
    
    }
    else {
        playerPosList->insertHead(moved_player);
        playerPosList->removeTail();
    }


    

}
