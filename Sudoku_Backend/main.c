#include <stdio.h>
#include <stdbool.h>
#include "backend.h"


bool validSubGrid(int row, int col, int num, int puzzle[9][9])
{
    int r = row - row%3;
    int c = col - col%3;

    for (int i = r; i < r+3; i++)
    {
        for (int j = c; j < c+3; j++)
        {
            if (puzzle[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}


bool validCol(int col, int num, int puzzle[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        if(puzzle[i][col] == num)
        {
            return false;
        }
    }
    return true;
}

bool validRow(int row, int num, int puzzle[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        if(puzzle[row][i] == num)
        {
            return false;
        }
    }
    return true;
}


bool isValid(int row, int col, int num, int puzzle[9][9])
{
    return validRow(row, num, puzzle) && validCol(col, num, puzzle) && validSubGrid(row, col, num, puzzle);
}


bool solve(int puzzle[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (puzzle[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if(isValid(row, col, num, puzzle))
                    {
                        puzzle[row][col] = num;
                        if (solve(puzzle))
                        {
                            return true;
                        }
                        else
                        {
                            puzzle[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}


void displayPuzzle(int puzzle[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        if (i%3 == 0 && i != 0)
        {
            printf("---------------------------------\n");
        }
        for(int j = 0; j < 9; j++)
        {
            if (j%3 == 0 && j != 0)
            {
                printf(" | ");
            }
            printf(" %d ", puzzle[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int puzzle[9][9] =
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    solve(puzzle);
    displayPuzzle(puzzle);
}
