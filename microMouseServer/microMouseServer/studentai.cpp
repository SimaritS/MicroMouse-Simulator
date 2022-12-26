
#include "micromouseserver.h"

void microMouseServer::studentAI()
{
/*
 * The following are the eight functions that you can call. Feel free to create your own fuctions as well.
 * Remember that any solution that calls moveForward more than once per call of studentAI() will have points deducted.
 *
 *The following functions return if there is a wall in their respective directions
 *bool isWallLeft();
 *bool isWallRight();
 *bool isWallForward();
 *
 *The following functions move the mouse. Move forward returns if the mouse was able to move forward and can be used for error checking
 *bool moveForward();
 *void turnLeft();
 *void turnRight();
 *
 * The following functions are called when you need to output something to the UI or when you have finished the maze
 * void foundFinish();
 * void printUI(const char *mesg);
*/
    bool wL = isWallLeft();
    bool wR = isWallRight();
    bool wF = isWallForward();

    // Walls on all 3 sides. Deadend ahead. Turn back.
    if (wL && wF && wR) {
        turnLeft();
        turnLeft();
    }

    // Right turn only. Walls on Left and Front sides. Turn right.
    if (wL && wF && !wR) {
        turnRight();
    }

    // If no wall on Left. Always turn left.
    if (!wL) {
        turnLeft();
    }

    //Keep moving forward
    moveForward();
}
