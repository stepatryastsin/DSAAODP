//#include"874.Walking_Robot_Simulation.h"
#include <stdio.h>
#include <stdlib.h>

struct point {
int x;
int y;
};

int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {

// Временное решение: увеличить размер выделенной памяти для массива `p`
struct point* p = malloc((commandsSize * 10) * sizeof(struct point)); // Увеличиваем размер для предотвращения выхода за границы
p[0] = (struct point){0, 0};

int ind = 0, j = 1;
int dir = 0, dircr = 0, dircl = 0;

while (ind < commandsSize) {
int speed = commands[ind];

if (speed >= 1 && speed <= 9) {
int xdir = p[j-1].x;
int ydir = p[j-1].y;

if (dir == 0) {
p[j] = (struct point) {xdir, ydir + speed};
} else if (dir == -1) {
p[j] = (struct point) {xdir - speed, ydir};
} else if (dir == -2) {
p[j] = (struct point) {xdir + speed, ydir};
} else if (dircl == 2 || dircr == 2) {
p[j] = (struct point) {xdir, ydir - speed};
dircl = 0;
dircr = 0;
}

for (int k = 0; k < obstaclesSize; k++) {
if (p[j].x == obstacles[k][0] && p[j].y == obstacles[k][1]) {
p[j] = p[j-1]; // Останавливаемся на предыдущей позиции, если встретили препятствие
break;
}
}

} else if (speed == -1) {
dir = -1;
dircl++;
} else if (speed == -2) {
dir = -2;
dircr++;
}

j++;
ind++;
}

int maxDistance = 0; // Возвращаем maxDistance как максимальное расстояние
for (int k = 0; k < j; k++) {
int dist = p[k].x * p[k].x + p[k].y * p[k].y;
if (dist > maxDistance) {
maxDistance = dist;
}
}

free(p);

return maxDistance; // Возвращаем квадрат максимального расстояния
}

int main() {
int commands[] = {6, -1, -1, 6};
int commandsSize = 4;
int* obstacles[0] = {}; // Нет препятствий
int obstaclesSize = 0;
int obstaclesColSize[0] = {};

int result = robotSim(commands, commandsSize, obstacles, obstaclesSize, obstaclesColSize);
printf("Max Distance: %d\n", result);
return 0;
}