// Solution for Islanded maze.
// Author: SimaritS.

#include "micromouseserver.h"
#include <iostream>
using namespace std;

//Initializing the variable
int rtCount = 0;
int totCount = 0;

//Initialize array for node marking.
int visitArray[MAZE_HEIGHT][MAZE_WIDTH] = { 0 };

void microMouseServer::studentAI() {
    //Store the wall & mouse positions.
    bool wL = isWallLeft();
    bool wR = isWallRight();
    bool wF = isWallForward();
    int posX = (this->maze->mouseX() - 1);
    int posY = (this->maze->mouseY() - 1);

    // Walls on all 3 sides. Deadend. Turn back. 111
    if (wL && wF && wR) {
        turnLeft();
        turnLeft();
        rtCount=0;
    }

    // Right turn only. Turn right. 110
    if (wL && wF && !wR) {
        turnRight();
        rtCount++;
    }

    // Left turn only. Turn left. 011
    if (!wL && wF && wR) {
        turnLeft();
        rtCount=0;
    }

    // No wall in front no change. 101
    if (wL && !wF && wR) {
        rtCount=0;
    }

    // No wall in F and R. 100
    if (wL && !wF && !wR) {
        rtCount=0;
        if(visitArray[posX][posY] > 0) {
            for(int i=1; i < (visitArray[posX][posY])%4; i++){
                turnRight();
            }
        }
        //Mark node
        visitArray[posX][posY]++;
    }

    //If no wall on Left. Always turn left. 001
    if ( (!wL && !wF && wR)) {
        turnLeft();
        rtCount=0;
        if(visitArray[posX][posY] > 0) {
            for(int i=1; i < (visitArray[posX][posY])%4; i++){
                turnRight();
            }
        }
        //Mark node
        visitArray[posX][posY]++;
    }

    //If no wall on Left. Always turn left. 010
    if ((!wL && wF && !wR)) {
        turnLeft();
        rtCount=0;
        if(visitArray[posX][posY] > 0) {
            for(int i=1; i < (visitArray[posX][posY])%4; i++){
                turnRight();
            }
        }
        //Mark node
        visitArray[posX][posY]++;
    }

    //No wall. 000
    if ((!wL && !wF && !wR)) {
        turnLeft();
        rtCount=0;
        if(visitArray[posX][posY] > 0) {
            for(int i=1; i < (visitArray[posX][posY])%4; i++){
                turnRight();
            }
        }
        //Mark node
        visitArray[posX][posY]++;
    }

    //Mouse direction already set, Move fwd.
    moveForward();

    //The right turn counter. When it reaches 3 the mouse should stop.
    if(rtCount==3) {
       printUI("Congratulations! You've reached the end!");
       foundFinish();
    }

    cout << "Total Mouse Moves:" << totCount++ <<endl;
}
