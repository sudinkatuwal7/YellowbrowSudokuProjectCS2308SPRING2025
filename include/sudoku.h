//Group name: YellowbrowSudokuProjectCS2308SPRING2025
//Members: Sudin Katuwal, Sugam Pandey, Nischal Rimal, Mandip Bastola


  /**
 * @file sudoku.h
 * @brief Core Sudoku solving and board generation functions.
 *
 * This header file declares functions essential for solving Sudoku puzzles
 * and validating board states. It includes:
 * - A backtracking Sudoku solver.
 * - A cell validation function to ensure valid number placement.
 * - A board generation stub for creating Sudoku puzzles.
 *
 * All functions operate on dynamically allocated 9x9 Sudoku boards
 * represented as `int**`, where empty cells are denoted by 0.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef SUDOKUPROJECT_SUDOKU_H
#define SUDOKUPROJECT_SUDOKU_H

#include <iostream>

/**
 * @brief Checks if placing a number at the given cell is valid.
 *
 * This function verifies whether placing the number `k` at position (r, c) in the
 * board does not violate Sudoku rules (i.e., uniqueness in row, column, and 3x3 grid).
 *
 * @param BOARD A 9x9 Sudoku board.
 * @param r The row index of the cell.
 * @param c The column index of the cell.
 * @param k The number to check for validity.
 * @return true if the placement is valid, false otherwise.
 */
bool isValid(int** BOARD, const int& r, const int& c, const int& k);

/**
 * @brief Solves the Sudoku board using basic backtracking.
 *
 * @param BOARD A 9x9 Sudoku board.
 * @param r Starting row index (default is 0).
 * @param c Starting column index (default is 0).
 * @return true if the board is successfully solved, false otherwise.
 */
bool solveBoard(int** BOARD, const int& r=0, const int& c=0);

/**
 * @brief Finds the next empty cell using Minimum Remaining Value (MRV) heuristic.
 *
 * @param BOARD A 9x9 Sudoku board.
 * @return std::tuple<int, int, int> A tuple of row index, column index, and number of valid options.
 */
std::tuple<int, int, int> findNextCell(int** BOARD);

/**
 * @brief Solves the Sudoku board using backtracking with the MRV heuristic.
 *
 * @param BOARD A 9x9 Sudoku board.
 * @return true if the board is successfully solved, false otherwise.
 */
bool solveBoardEfficient(int** BOARD);

/**
 * @brief Wrapper function to solve the board using basic or efficient method.
 *
 * @param board A 9x9 Sudoku board.
 * @param efficient If true, uses efficient method; otherwise, uses basic method.
 * @return true if the board is solved successfully.
 */
bool solve(int** board, const bool& efficient = false);

/**
 * @brief Deallocates a dynamically allocated 9x9 Sudoku board.
 *
 * @param board The board to deallocate.
 */
void deallocateBoard(int** board);

#endif //SUDOKUPROJECT_SUDOKU_H