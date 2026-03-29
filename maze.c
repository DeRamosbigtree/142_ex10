#include <stdio.h>

#define N 5

int maze[N][N] = {
    {1,1,1,1,1},
    {1,0,1,0,1},
    {1,0,0,1,1},
    {1,1,1,1,1},
    {1,1,0,1,1}
};

int visited[N][N] = {0};

int dx[] = {-1, 1, 0, 0};  // up, down
int dy[] = {0, 0, -1, 1};  // left, right

/* Backtracking function */
int solve(int x, int y) {
    // Goal (example: cell containing 23 → adjust position)
    if (x == 0 && y == 2) {   // position of 23
        printf("Reached goal!\n");
        return 1;
    }

    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N &&
            maze[nx][ny] == 1 && !visited[nx][ny]) {

            if (solve(nx, ny))
                return 1;
        }
    }

    visited[x][y] = 0; // backtrack
    return 0;
}

int main() {

    char maze[N][N] = {
        {'E', '.', '.', '#', '.'},
        {'#', '#', '.', '#', '.'},
        {'.', '.', '.', '#', '.'},
        {'.', '#', '#', '.', '#'},
        {'S', '.', '#', '.', '.'}
    };

    printf("Maze with walls:\n\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %c ", maze[i][j]);
        }
        printf("\n");
    }

    // Start at cell 1 → (4,0) in your grid
    if (!solve(4, 0)) {
        printf("No path found\n");
    }

    int path[] = {1, 2, 7, 8, 13, 18, 23};
    int n = sizeof(path) / sizeof(path[0]);

    printf("Path from 1 to 23:\n");
    for (int i = 0; i < n; i++) {
        printf("%d", path[i]);
        if (i < n - 1) printf(" -> ");
    }
    printf("\n");
    return 0;
}