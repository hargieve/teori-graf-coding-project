# ♞ Knight’s Tour 

This project implements the **Knight’s Tour Problem** using the **Backtracking Algorithm** in the C programming language.  
The Knight’s Tour is a classic problem in chess and computer science where a knight must visit every square on the chessboard **exactly once**.

---

## 📘 Problem Description

The **Knight’s Tour** asks:  
> “Can a knight move around an N×N chessboard such that it visits every square exactly once?”

A **solution** exists if the knight can make a sequence of moves that covers all squares without repeating any.

There are two types of tours:
- **Open tour** – the knight ends on a square different from the starting point.  
- **Closed tour** – the knight ends one knight’s move away from the starting point.

This program focuses on finding **one valid tour (open)** using backtracking.

---

## 🧠 Algorithm Used — Backtracking

The algorithm explores all possible moves step by step:

1. Place the knight on the starting square.
2. Mark the current square as visited.
3. Try all possible knight moves from the current square.
4. If a move leads to a dead-end (no unvisited squares left), **backtrack**.
5. Continue until all squares have been visited.

If all `N × N` squares are visited successfully, a solution is found.

---

## 🧩 Features

- Solves the **Knight’s Tour** using **recursive backtracking**.  
- User can input any **starting position** on the chessboard.  
- Displays the **full path** of the knight with move numbers.  
- Works on a standard **8×8 board** (can be resized by changing `#define N 8`).

---

## 🧾 Input and Output

### 🖥️ Input Format
- Two integers representing the **starting position** (row and column).
- Row and column are **0-indexed** (range: 0–7 for an 8×8 board).

### 📤 Output Format
- The program prints the chessboard grid where each cell shows the **move number** (starting from 0).
- If no tour exists, it prints:

Example Output:
0 59 38 33 30 17 8 63
37 34 31 60 9 62 29 16
58 1 36 39 32 27 18 7
35 48 41 26 61 10 15 28
42 57 2 49 40 23 6 19
47 50 45 54 25 20 11 14
56 43 52 3 22 13 24 5
51 46 55 44 53 4 21 12


