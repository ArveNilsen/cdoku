#include <stdio.h>
#include <stdbool.h>

/* Size of the rows */
extern int SIZE_ROWS;
/* Size of the columns */
extern int SIZE_COLUMNS;

/* Takes a pointer to a puzzle and prints the puzzle to the terminal */
void printPuzzle(int *pzl);

/*
 * Finds the next empty cell and returns the distance from index 0.
 * Return -1 if theres no empty cells left
 */
int findEmpty(int *pzl);

/* Helper function to calculate column number from findEmpty */
int toColumn(int emptyCellId);

/* Helper function to calculate row number from findEmpty */
int toRow(int emptyCellId);

/*
 * Checks if inserting a given number is valid for the current puzzle state.
 * First checks rows, then columns and finally the nine sub squares of the puzzle.
 * Returns false if the given number in the given position leads to violating the rules.
 *
 * @param
 * int *pzl: a pointer to the current puzzle.
 * int emptyCellId: the array index of the current position.
 * int number: the number to be tested.
 */
bool isValid(int *pzl, int emptyCellId, int number);

/* Solves the sudoku puzzle using a recursive backtracking algorithm */
bool solveCdoku(int *pzl);