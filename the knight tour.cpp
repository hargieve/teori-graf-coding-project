#include <iostream>
#include <iomanip>
using namespace std;

#define N 8 // You can change this to any board size, e.g., 5, 6, 8, 10

// Moves a knight can make
int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// Function to check if a position is valid and not yet visited
bool isSafe(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

// Function to print the solution board
void printSolution(int sol[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << setw(3) << sol[x][y] << " ";
        cout << endl;
    }
}

// Recursive utility function to solve Knight’s Tour
bool solveKTUtil(int x, int y, int movei, int sol[N][N], int moveX[N], int moveY[N]) {
    int nextX, nextY;
    if (movei == N * N)
        return true; // All squares visited

    // Try all possible moves
    for (int k = 0; k < 8; k++) {
        nextX = x + moveX[k];
        nextY = y + moveY[k];
        if (isSafe(nextX, nextY, sol)) {
            sol[nextX][nextY] = movei;
            if (solveKTUtil(nextX, nextY, movei + 1, sol, moveX, moveY))
                return true;
            else
                sol[nextX][nextY] = -1; // backtracking
        }
    }

    return false;
}

// Main function to solve the Knight’s Tour problem
bool solveKT() {
    int sol[N][N];

    // Initialize the solution matrix
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    // Knight’s starting position
    int startX, startY;
    cout << "Enter starting position (x y): ";
    cin >> startX >> startY;

    // Place the knight on the starting square
    sol[startX][startY] = 0;

    // Try to solve the Knight’s Tour
    if (!solveKTUtil(startX, startY, 1, sol, moveX, moveY)) {
        cout << "No solution exists." << endl;
        return false;
    } else
        printSolution(sol);

    return true;
}

int main() {
    cout << "=== Knight's Tour Problem (C++) ===" << endl;
    solveKT();
    return 0;
}
