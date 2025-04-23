//Group name: YellowbrowSudokuProjectCS2308SPRING2025
//Members: Sudin Katuwal, Sugam Pandey, Nischal Rimal


//
// Created by Keshav Bhandari on 2/19/25.
//

/**
 * @file generator.cpp
 * @brief Implementation of functions to generate random solvable Sudoku boards.
 *
 * This file should contain logic to:
 * - Create empty Sudoku boards.
 * - Fill independent diagonal boxes.
 * - Solve the filled board to complete it.
 * - Randomly remove cells to create solvable Sudoku puzzles.
 *
 * - Replace the dummy code section with appropriate logic
 *
 * You should provide detailed function descriptions in the corresponding header file.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#include "../include/generator.h"
#include "../include/sudoku.h"
#include "../include/sudoku_io.h"
#include <random>
#include <bitset>
#include <algorithm>
#include <ctime>
#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

// Shared random number generator to avoid reseeding multiple times
namespace {
    std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
}

int** getEmptyBoard() {
    int** board = new int*[9];
    for(int i = 0; i < 9; i++){
        board[i] = new int[9]{0};
    }
    return board;
}

// Hint 1:  Implement a function to return shuffled vectors
// Function to return a randomly shuffled vector from 1 to 9
std::vector<int> getShuffledVector() {
    /**
     * - Create a vector with numbers 1 to 9.
     * - Apply a shuffling algorithm to randomize the order.
     * - Return the shuffled vector.
     *
     * Example Output: {3, 1, 4, 2, 7, 6, 5, 9, 8}
     *
     * @return std::vector<int> Shuffled numbers from 1 to 9.
     */
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    shuffle(vec.begin(), vec.end(), rng);
    return vec;
}

// Hint 2:  Random Independent Box fill:
void fillBoardWithIndependentBox(int** BOARD) {
    for(int box = 0; box < 3; box++) {
        vector<int> numbers = getShuffledVector();
        int startRow = box * 3;
        int startCol = box * 3;
        int idx = 0;
        for(int r = startRow; r < startRow+3; r++) {
            for(int c = startCol; c < startCol+3; c++) {
                BOARD[r][c] = numbers[idx++];
            }
        }
    }
}

// Function to randomly delete 'n' items from a 9x9 Sudoku board using bitsets
void deleteRandomItems(int** BOARD, const int& n) {
    if (!BOARD) {
        cerr << "Board pointer is null." << endl;
        return;
    }
    if(n < 1 || n > 81) {
        cerr << "Invalid number of cells to delete: " << n << endl;
        return;
    }
    vector<int> positions(81);
    iota(positions.begin(), positions.end(), 0);
    shuffle(positions.begin(), positions.end(), rng);
    for(int i = 0; i < n; i++) {
        int pos = positions[i];
        int row = pos / 9;
        int col = pos % 9;
        BOARD[row][col] = 0;
    }
}

// Finally return the board
int** generateBoard(const int& empty_boxes){
    int** BOARD = getEmptyBoard();
    fillBoardWithIndependentBox(BOARD);
    if(!solve(BOARD, true)) {
        cerr << "Failed to solve generated board" << endl;
        deallocateBoard(BOARD);
        return nullptr;
    }
    deleteRandomItems(BOARD, empty_boxes);
    return BOARD;
}
