#include <stdio.h>
#include <string.h>
#include <stdlib.h>


const int LEN = 6;
const int MAX_LEN = 64;
const int MAX_SIZE = 2 * MAX_LEN + 1;
const char WALL = '#';
const char PATH = '.';
const int SEED = 42;

typedef enum CellState {
    VISITED,
    ISOLATED,
} CellState;

typedef struct Maze {
    char map[MAX_SIZE][MAX_SIZE];
    int size;
    char wall, path;
} Maze;

typedef struct Point {
    int i, j;
} Point;

const Point dps[] = { { 2, 0 }, { -2, 0}, { 0, 2 }, { 0, -2 } };


void initMaze(Maze *m, int size, char wall, char path) {
    m->size = size;
    m->wall = wall;
    m->path = path;

    for (int i = 0; i < m->size; i += 2) {
        memset(&m->map[i][0], m->wall, m->size);
    }

    for (int i = 1; i < m->size; i += 2) {
        for (int j = 1; j < m->size; j += 2) {
            m->map[i][j] = ISOLATED;
        }
        for (int j = 0; j < m->size; j += 2) {
            m->map[i][j] = m->wall;
        }
    }
}

void printMaze(Maze *m) {
    for (int i = 0; i < m->size; ++i) {
        printf("%.*s\n", (int) m->size, m->map[i]);
    }
}

int isValidPointMaze(const Maze *const m, Point p) {
    return p.i > 0 && p.i < m->size - 1 && 
            p.j > 0 && p.j < m->size - 1;
}

int sign(int x) {
    return (x > 0) - (x < 0);
}

void shuffle(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i)  {
        size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = arr[j];
        arr[j] = arr[i];
        arr[i] = t;
    }
}

void fillMazeDFS(Maze *const m, Point p) {
    m->map[p.i][p.j] = VISITED;

    // random shuffle neighbours
    int perm[] = { 0, 1, 2, 3 };
    shuffle(perm, sizeof(dps) / sizeof(dps[0]));

    // dfs
    Point dp, np;
    for (size_t i = 0; i < sizeof(dps) / sizeof(dps[0]); ++i) {
        dp = dps[perm[i]];
        np = (Point) { p.i + dp.i, p.j + dp.j };

        if (isValidPointMaze(m, np) && m->map[np.i][np.j] == ISOLATED) {
            // remove wall
            m->map[p.i + sign(dp.i)][p.j + sign(dp.j)] = m->path;

            // recurse
            fillMazeDFS(m, np);
        }
    }

    // set visited cells to ways
    for (int i = 0; i < m->size; ++i) {
        for (int j = 0; j < m->size; ++j) {
            if (m->map[i][j] == VISITED) {
                m->map[i][j] = m->path;
            }
        }
    }
}

void generateRandomMaze(Maze *m, int seed) {
    srand(seed);
    fillMazeDFS(m, (Point) { 1, 1 });
}

int main() {
    int len = LEN;
    int size = 2 * len + 1; 
    int seed = SEED;
    char wall = WALL, path = PATH;

    Maze maze;
    initMaze(&maze, size, wall, path);
    generateRandomMaze(&maze, seed);
    printMaze(&maze);
}
