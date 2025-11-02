<?php
define("N", 8);

// Possible moves of a Knight in chess
$moveX = [2, 1, -1, -2, -2, -1, 1, 2];
$moveY = [1, 2, 2, 1, -1, -2, -2, -1];

// Function to print the board
function printSolution($board) {
    for ($x = 0; $x < N; $x++) {
        for ($y = 0; $y < N; $y++) {
            printf("%3d ", $board[$x][$y]);
        }
        echo "\n";
    }
}

// Function to check if a move is valid
function isSafe($x, $y, $board) {
    return ($x >= 0 && $x < N && $y >= 0 && $y < N && $board[$x][$y] == -1);
}

// Recursive utility function to solve Knight’s Tour
function solveKTUtil($x, $y, $movei, &$board, $moveX, $moveY) {
    if ($movei == N * N)
        return true; // All squares are visited

    for ($k = 0; $k < 8; $k++) {
        $next_x = $x + $moveX[$k];
        $next_y = $y + $moveY[$k];
        if (isSafe($next_x, $next_y, $board)) {
            $board[$next_x][$next_y] = $movei;
            if (solveKTUtil($next_x, $next_y, $movei + 1, $board, $moveX, $moveY))
                return true;
            else
                $board[$next_x][$next_y] = -1; // backtrack
        }
    }

    return false;
}

// Main solver function
function solveKT($startX, $startY) {
    global $moveX, $moveY;

    // Initialize the board with -1
    $board = array_fill(0, N, array_fill(0, N, -1));

    // Start from user’s input
    $board[$startX][$startY] = 0;

    if (!solveKTUtil($startX, $startY, 1, $board, $moveX, $moveY)) {
        echo "Solution does not exist.\n";
        return;
    }

    printSolution($board);
}

// --- Program execution ---

// You can change the starting position here
$startX = 0;
$startY = 0;

// If run via CLI, optionally get coordinates from input
if (PHP_SAPI === 'cli' && isset($argv[1]) && isset($argv[2])) {
    $startX = intval($argv[1]);
    $startY = intval($argv[2]);
} else {
    echo "Using default starting position (0,0)\n";
}

solveKT($startX, $startY);
?>
