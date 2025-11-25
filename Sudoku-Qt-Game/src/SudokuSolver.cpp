#include "sudokuwindow.h"
#include "SudokuSolver.h"

// UNASSIGNED is used for empty
// cells in sudoku arr[N][N]
#define UNASSIGNED 0

// N is used for the size of Sudoku arr[N][N].
// Size will be NxN
static const int N = 9;


// This function finds an entry in arr[N][N]
// that is still unassigned
bool FindUnassignedLocation(int arr[N][N], int& row, int& col);

// Checks whether it will be legal
// to assign num to the given row, col
bool isSafe(int arr[N][N], int row, int col, int num);

/* Takes a partially filled-in arr[N][N] and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
bool SolveSudoku(int arr[9][9]){
    int row, col;

    // If there is no unassigned location,
    // we are done
    if (!FindUnassignedLocation(arr, row, col)){
        // success!
        return true;
    }

    // Consider digits 1 to 9
    for (int num = 1; num <= 9; num++)
    {

        // Check if looks promising
        if (isSafe(arr, row, col, num))
        {

            // Make tentative assignment
            arr[row][col] = num;

            // Return, if success
            if(SolveSudoku(arr)){


                return true;
            }

            // Failure, unmake & try again
            arr[row][col] = UNASSIGNED;
        }
    }

    // This triggers backtracking
    return false;
}

/* Searches the arr[N][N] to find an entry that is
still unassigned. If found, the reference
parameters row, col will be set the location
that is unassigned, and true is returned.
If no unassigned entries remain, false is returned. */
bool FindUnassignedLocation(int arr[N][N],
                            int& row, int& col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (arr[row][col] == UNASSIGNED)
                return true;
    return false;
}

/* Returns a boolean which indicates whether
an assigned entry in the specified row matches
the given number. */
bool UsedInRow(int arr[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (arr[row][col] == num)
            return true;
    return false;
}

/* Returns a boolean which indicates whether
an assigned entry in the specified column
matches the given number. */
bool UsedInCol(int arr[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if(arr[row][col] == num)
            return true;
    return false;
}

/* Returns a boolean which indicates whether
an assigned entry within the specified 3x3 box
matches the given number. */
bool UsedInBox(int arr[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (arr[row + boxStartRow]
                    [col + boxStartCol] ==
                num)
                return true;
    return false;
}

/* Returns a boolean which indicates whether
it will be legal to assign num to the given
row, col location. */
bool isSafe(int arr[N][N], int row, int col, int num)
{
    /* Check if 'num' is not already placed in
    current row, current column
    and current 3x3 box */
    return !UsedInRow(arr, row, num)
           && !UsedInCol(arr, col, num)
           && !UsedInBox(arr, row - row % 3,
                         col - col % 3, num)
           && arr[row][col] == UNASSIGNED;
}
