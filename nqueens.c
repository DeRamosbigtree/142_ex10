#include <stdio.h>
#include <stdlib.h>

#define N 4   // change this to 8, 5, etc.

int board[N][N];

/* Print one solution */
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

/* Check if placing a queen at board[row][col] is safe */
int isSafe(int row, int col) {
    int i, j;

    /* Check same column above */
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return 0;
    }

    /* Check upper-left diagonal */
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    /* Check upper-right diagonal */
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

/* Backtracking function */
int solveNQueens(int row) {
    /* Base case: all queens placed */
    if (row == N) {
        printBoard();
        return 1;   // found one solution
    }

    int foundSolution = 0;

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;              // choose
            foundSolution = solveNQueens(row + 1) || foundSolution;
            board[row][col] = 0;              // backtrack (undo)
        }
    }

    return foundSolution;
}

int main() {
    /* Initialize board to 0 */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (!solveNQueens(0)) {
        printf("No solution exists.\n");
    }

    return 0;
}