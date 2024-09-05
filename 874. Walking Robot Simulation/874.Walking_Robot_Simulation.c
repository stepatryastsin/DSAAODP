#include <stdio.h>
#include <stdlib.h>
#include"set.h"
// Point structure for robot coordinates
struct point {
    int x;
    int y;
};

// Check if a point is an obstacle using the set
int isObstacle(int x, int y, set* obstacleSet) {
    char buffer[20];
    snprintf(buffer, sizeof(buffer), "%d,%d", x, y); // Create a string of "x,y"
    return set_contains(obstacleSet, buffer);  // Check if it exists in the set
}

// Robot simulation function
int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    struct point p = { 0, 0 };
    int distance = 0, dir = 0;
    int diry[4] = { 1, 0, -1, 0 };
    int dirx[4] = { 0, 1, 0, -1 };

    // Initialize a set for obstacles
    set obstacleSet;
    set_init(&obstacleSet, obstaclesSize);

    // Add all obstacles to the set
    for (int i = 0; i < obstaclesSize; i++) {
        char buffer[20];
        snprintf(buffer, sizeof(buffer), "%d,%d", obstacles[i][0], obstacles[i][1]);
        set_add(&obstacleSet, buffer);
    }

    // Process each command
    for (int i = 0; i < commandsSize; i++) {
        if (commands[i] == -1) {
            dir = (dir + 1) % 4;  // Turn right
        }
        else if (commands[i] == -2) {
            dir = (dir + 3) % 4;  // Turn left
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
                    break;  // Stop if there's an obstacle
                }
            }
        }
    }

    // Clean up the obstacle set
    set_destroy(&obstacleSet);

    return distance;
}