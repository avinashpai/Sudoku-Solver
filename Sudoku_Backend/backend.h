#include <stdbool.h>

#ifndef BACKEND_H
#define BACKEND_H

bool validSubGrid(int row, int col, int num, int puzzle[9][9]);
bool validCol(int col, int num, int puzzle[9][9]);
bool validRow(int row, int num, int puzzle[9][9]);
bool isValid(int row, int col, int num, int puzzle[9][9]);
bool solve(int puzzle[9][9]);
void displayPuzzle(int puzzle[9][9]);

#endif // BACKEND_H
