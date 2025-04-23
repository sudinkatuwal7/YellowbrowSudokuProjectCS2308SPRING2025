//Group name: YellowbrowSudokuProjectCS2308SPRING2025
//Members: Sudin Katuwal, Sugam Pandey, Nischal Rimal


/**
 * @file sudoku.cpp
 * @brief Implementation of core Sudoku solving and validation functions.
 *
 * Contains the logic for validating moves and solving Sudoku puzzles using
 * a backtracking algorithm. Detailed function descriptions are provided in
 * the corresponding header file.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
*/

#include "../include/sudoku.h"
#include <iostream>
#include <tuple>
#include <climits>
using namespace std;

bool isValid(int** BOARD, const int& r, const int& c, const int& k)
{
    for (int i = 0; i < 9; i++)
    {
        if (k == BOARD[r][i] || k == BOARD[i][c])
            return false;
    }

    int startRow = 3 * (r / 3);
    int startCol = 3 * (c / 3);

    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (k == BOARD[i][j])
                return false;
        }
    }

    return true;
}

bool solveBoard(int** BOARD, const int& r, const int& c)
{
    if (r == 9)
        return true;

    if (c == 9)
        return solveBoard(BOARD, r + 1, 0);

    if (BOARD[r][c] != 0)
        return solveBoard(BOARD, r, c + 1);

    for (int k = 1; k <= 9; k++)
    {
        if (isValid(BOARD, r, c, k))
        {
            BOARD[r][c] = k;
            if (solveBoard(BOARD, r, c + 1))
                return true;
            BOARD[r][c] = 0;
        }
    }

    return false;
}

tuple<int, int, int> findNextCell(int** BOARD) {
    int minOptions = INT_MAX;
    int bestRow = -1, bestCol = -1;

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (BOARD[r][c] == 0) {
                int options = 0;
                for (int k = 1; k <= 9; k++) {
                    if (isValid(BOARD, r, c, k)) {
                        options++;
                    }
                }
                if (options < minOptions) {
                    minOptions = options;
                    bestRow = r;
                    bestCol = c;
                    if (minOptions == 1)
                        return {bestRow, bestCol, minOptions};
                }
            }
        }
    }
    return {bestRow, bestCol, minOptions};
}

bool solveBoardEfficient(int** BOARD)
{
    auto [row, col, options] = findNextCell(BOARD);
    if (row == -1)
        return true;

    for (int k = 1; k <= 9; k++) {
        if (isValid(BOARD, row, col, k)) {
            BOARD[row][col] = k;
            if (solveBoardEfficient(BOARD))
                return true;
            BOARD[row][col] = 0;
        }
    }
    return false;
}

bool solve(int** board, const bool& efficient) {
    if (efficient)
        return solveBoardEfficient(board);
    else
        return solveBoard(board, 0, 0);
}

void deallocateBoard(int** board) {
    if (!board) return;
    for (int i = 0; i < 9; i++) {
        delete[] board[i];
    }
    delete[] board;
}
