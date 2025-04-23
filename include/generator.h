//Group name: YellowbrowSudokuProjectCS2308SPRING2025
//Members: Sudin Katuwal, Sugam Pandey, Nischal Rimal


/**
* @file generator.h
 * @brief Function prototypes for generating random solvable Sudoku boards.
 *
 * This header defines functions to:
 * - Create empty Sudoku boards.
 * - Fill independent diagonal boxes.
 * - Solve and generate a complete Sudoku board.
 * - Randomly delete cells to create a solvable puzzle.
 * - Generate a complete Sudoku puzzle with a specific number of empty cells.
 *
 * Detailed function descriptions and parameters are provided below.
 *
 * @note Caller is responsible for deallocating any returned board using deallocateBoard().
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>

/**
 * @brief Creates an empty 9x9 Sudoku board initialized with zeros.
 * @return int** Dynamically allocated 9x9 board.
 * @note Caller is responsible for deallocating the returned board using deallocateBoard().
 */
int** getEmptyBoard();

/**
 * @brief Returns a vector of numbers 1-9 shuffled randomly.
 * @return std::vector<int> Shuffled numbers from 1 to 9.
 *
 * Example Output: {3, 1, 4, 2, 7, 6, 5, 9, 8}
 */
std::vector<int> getShuffledVector();

/**
 * @brief Fills the three diagonal 3x3 boxes of the Sudoku board with unique shuffled numbers.
 * @param BOARD The 9x9 Sudoku board to fill.
 */
void fillBoardWithIndependentBox(int** BOARD);

/**
 * @brief Deletes n unique random cells from the Sudoku board by setting them to 0.
 * @param BOARD The 9x9 Sudoku board.
 * @param n Number of cells to delete (1-81).
 */
void deleteRandomItems(int** BOARD, const int& n);

/**
 * @brief Generates a Sudoku board with a specified number of empty cells.
 * @param empty_boxes Number of empty cells to create.
 * @return int** The generated Sudoku board.
 * @note Caller is responsible for deallocating the returned board using deallocateBoard().
 */
int** generateBoard(const int& empty_boxes);

#endif // GENERATOR_H
