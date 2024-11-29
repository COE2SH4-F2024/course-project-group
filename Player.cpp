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
    // objPos foodPos = foodRef->getFoodPos();
    int food_x,food_y;
    int collided = 0;
    char food_sym;

    int food_num; //random number for food generation


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
    //Wrap around conditions

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

    for(i=0; i < foodRef->getFoodPos()->getSize(); i++) {
        //x and y values for certain food
        test_col_x = foodRef->getFoodPos()->getElement(i).pos->x;
        test_col_y = foodRef->getFoodPos()->getElement(i).pos->y;
        if(x == test_col_x && y == test_col_y) {
            collided = 1;
            //get symbol of certain food
            food_sym = foodRef->getFoodPos()->getElement(i).getSymbol();
            
            //increment score
            

            if(food_sym == '/') {
                //add 50 to score but inc length by 10
                mainGameMechsRef->addToScore(50);
                playerPosList->lengthenSnake(10);
            }
            else if(food_sym == 'm') {
                //add 10 to score and dont inc length
                mainGameMechsRef->addToScore(10);
            }
            else {
                //default food
                mainGameMechsRef->incrementScore();
                playerPosList->insertHead(moved_player);
            }

            

            //if the head collides with the food
            foodRef->getFoodPos()->removeElement(i);

            //generate new food (1-5)incl
            food_num = (rand() % (5)) + 1;
            if(food_num == 1) {
                //1/5 of the time create / food
                foodRef->generateFood(*playerPosList, '/');
                
    
            }
            else if (food_num == 2) {
                //1/5 of the time create m food
                foodRef->generateFood(*playerPosList, 'm');
            }
            else {
                //3/5 of the time create default food
                foodRef->generateFood(*playerPosList, 'o');   
            }
                
            break; //Cant collide with multiple objects at once, saves computing power
        }
    }
    if(!collided) {
        //If no collision takes place treat as normal
        playerPosList->insertHead(moved_player);
        playerPosList->removeTail();
    }
    
    
        
    //Rewrite [0][0] as border when it gets replaced from default objPos
    mainGameMechsRef->displaychar(0,0,'#');
    


}

