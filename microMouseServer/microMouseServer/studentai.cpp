// Solution for Un-islanded maze.
// Author: SimaritS.

#include "micromouseserver.h"

//Initializing the variable
int rtCount = 0;

void microMouseServer::studentAI()
{
    //Store the wall positions.
    bool wL = isWallLeft();
    bool wR = isWallRight();
    bool wF = isWallForward();

    // Walls on all 3 sides. Deadend ahead. Turn back.
    if (wL && wF && wR) {
        turnLeft();
        turnLeft();
        rtCount=0;
    }

    // Right turn only. Turn right.
    if (wL && wF && !wR) {
        turnRight();
        rtCount++;
    }

    // If no wall on Left. Always turn left.
    if (!wL) {
        turnLeft();
        rtCount=0;
    }

    //If wall on left & no wall in front no change.
    if (wL && !wF){
        rtCount=0;
    }

    //Mouse direction already set, Move fwd.
    moveForward();

    //The right turn counter. When it reaches 3 the mouse should stop.
    if(rtCount==3){
       printUI("Congratulations! You've reached the end!");
       foundFinish();
    }    
}
