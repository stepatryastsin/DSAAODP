#include <stdio.h>
#include <stdlib.h>
#include"set.h"

struct point {
    int x;
    int y;
};

int isObstacle(int x, int y, set* obstacleSet) {
    char buffer[20];
    snprintf(buffer, sizeof(buffer), "%d,%d", x, y); 
    return set_contains(obstacleSet, buffer);  
}


int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    struct point p = { 0, 0 };
    int distance = 0, dir = 0;
    int diry[4] = { 1, 0, -1, 0 };
    int dirx[4] = { 0, 1, 0, -1 };

  
    set obstacleSet;
    set_init(&obstacleSet, obstaclesSize);

 
    for (int i = 0; i < obstaclesSize; i++) {
        char buffer[20];
        snprintf(buffer, sizeof(buffer), "%d,%d", obstacles[i][0], obstacles[i][1]);
        set_add(&obstacleSet, buffer);
    }

   
    for (int i = 0; i < commandsSize; i++) {
        if (commands[i] == -1) {
            dir = (dir + 1) % 4;  
        }
        else if (commands[i] == -2) {
            dir = (dir + 3) % 4; 
        }
        else {
            for (int step = 0; step < commands[i]; step++) {
                int nextX = p.x + dirx[dir];
                int nextY = p.y + diry[dir];
                if (!isObstacle(nextX, nextY, &obstacleSet)) {
                    p.x = nextX;
                    p.y = nextY;
                    int dist = p.x * p.x + p.y * p.y;
                    if (dist > distance) {
                        distance = dist;
                    }
                }
                else {
                    break;  
                }
            }
        }
    }


    set_destroy(&obstacleSet);

    return distance;
}