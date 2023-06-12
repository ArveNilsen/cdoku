/*
 * Sudoku solver in C with recursive backtracking.
 *
 * A C implementation of the algorithm from Computerphile
 * found here: https://www.youtube.com/watch?v=G_UYXzGuqvM
 *
 * Implemented using a one-dimensional array to represent the board.
 * Rows and colums are calculated based on the cells distance from the 0 index.
 *
 * Author: Arve Nilsen, June 2023.
 */
#include "../include/cdoku.h"

int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main(void)
{
    int puzzle[81] = {0, 1, 9, 0, 0, 2, 0, 0, 0,
                      4, 7, 0, 6, 9, 0, 0, 0, 1,
                      0, 0, 0, 4, 0, 0, 0, 9, 0,
                      8, 9, 4, 5, 0, 7, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 2, 0, 1, 9, 5, 8,
                      0, 5, 0, 0, 0, 6, 0, 0, 0,
                      6, 0, 0, 0, 2, 8, 0, 7, 9,
                      0, 0, 0, 1, 0, 0, 8, 6, 0};

    // int validPuzzle[] = {7, 8, 0, 4, 0, 0, 1, 2, 0,
    //                      6, 0, 0, 0, 7, 5, 0, 0, 9,
    //                      0, 0, 0, 6, 0, 1, 0, 7, 8,
    //                      0, 0, 7, 0, 4, 0, 2, 6, 0,
    //                      0, 0, 1, 0, 5, 0, 9, 3, 0,
    //                      9, 0, 4, 0, 6, 0, 0, 0, 5,
    //                      0, 7, 0, 3, 0, 0, 0, 1, 2,
    //                      1, 2, 0, 0, 0, 7, 4, 0, 0,
    //                      0, 4, 9, 2, 0, 6, 0, 0, 7};

    printPuzzle(&puzzle[0]);

    printf("\n\n");

    solveCdoku(&puzzle[0]);

    printPuzzle(&puzzle[0]);

    return 0;
}

void printPuzzle(int *pzl)
{
    int i;

    /* Top border */
    printf("-------------------------------\n");

    for (i = 0; i < SIZE_ROWS * SIZE_COLUMNS; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            printf("|");
        }
        if (i % 9 == 0 && i != 0)
        {
            printf("\n");
        }
        if (i == 27 || i == 54)
        {
            printf("-------------------------------\n");
        }
        if (i % 9 == 0)
        {
            printf("|");
        }
        printf(" %d ", pzl[i]);
    }
    printf("|\n-------------------------------\n");
}

int findEmpty(int *pzl)
{
    int i;
    for (i = 0; i < SIZE_ROWS * SIZE_COLUMNS; i++)
    {
        if (pzl[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

int toColumn(int emptyCellId)
{
    return emptyCellId % 9;
}

int toRow(int emptyCellId)
{
    return emptyCellId / 9;
}

bool isValid(int *pzl, int emptyCellId, int number)
{
    int i, j, box_x, box_y, startOfBox, x, y;

    int row, column;
    row = toRow(emptyCellId);
    column = toColumn(emptyCellId);

    /*
     * Initialise i to the first cell of the row.
     * Then check if number exists in the row.
     */
    for (i = row * SIZE_ROWS; i < row * SIZE_ROWS + SIZE_ROWS; i++)
    {
        if (pzl[i] == number)
        {
            return false;
        }
    }

    /* Check column */
    for (j = 0; j < SIZE_COLUMNS; j++)
    {
        if (pzl[column] == number)
        {
            return false;
        }
        column += SIZE_COLUMNS;
    }
    column = toColumn(emptyCellId);

    /* Check boxes */
    box_x = (row / 3) * 3;
    box_y = (column / 3) * 3;
    startOfBox = box_x * SIZE_ROWS + box_y;

    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            if (pzl[startOfBox + y] == number)
            {
                return false;
            }
        }
        startOfBox += SIZE_ROWS;
    }
    return true;
}

bool solveCdoku(int *pzl)
{
    int i;

    int nextEmpty = findEmpty(pzl);

    /*
     * Base case. If findEmpty returns -1 then no more empty cells exists
     * and the game is complete.
     */
    if (nextEmpty == -1)
    {
        return true;
    }

    /* Loop through all possible numbers 1-9, inclusive */
    for (i = 1; i < 10; i++)
    {
        if (isValid(pzl, nextEmpty, i))
        {
            pzl[nextEmpty] = i;
            if (solveCdoku(pzl))
            {
                return true;
            }

            // /* Backtrack if not solvable */
            pzl[nextEmpty] = 0;
        }
    }
    return false;
}
