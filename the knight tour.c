#include <stdio.h>

#define N 8  // Board size (8x8)

// All possible moves for a knight
int moveX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int moveY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Function to print the solution board
void printSolution(int board[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            printf(" %2d ", board[x][y]);
        printf("\n");
    }
}

// Function to check if move is valid
int isSafe(int x, int y, int board[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Recursive utility to solve Knight Tour problem
int solveKTUtil(int x, int y, int movei, int board[N][N],
                int moveX[8], int moveY[8]) {
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;  // All squares visited

    for (k = 0; k < 8; k++) {
        next_x = x + moveX[k];
        next_y = y + moveY[k];
        if (isSafe(next_x, next_y, board)) {
            board[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, board, moveX, moveY))
                return 1;
            else
                board[next_x][next_y] = -1; // backtrack
        }
    }
    return 0;
}

// Solves the Knight Tour problem using Backtracking
int solveKT() {
    int board[N][N];

    // Initialize the board
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            board[x][y] = -1;

    // Starting position (can be changed)
    int startX, startY;
    printf("Enter starting position (row col, 0-7): ");
    scanf("%d %d", &startX, &startY);

    // Start from the user’s position
    board[startX][startY] = 0;

    // Start recursive search
    if (solveKTUtil(startX, startY, 1, board, moveX, moveY) == 0) {
        printf("Solution does not exist.\n");
        return 0;
    } else
        printSolution(board);

    return 1;
}

// Main function
int main() {
    solveKT();
    return 0;
}
