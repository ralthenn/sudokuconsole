#include <iostream>

class Sudoku
{
public:
  int setgrid(int row, int col, int set);
  int getgrid(int row, int col);
private:
  int grid[9][9][11]; // [0-8] = digits 1-9 suppositions, 9 = given, 10 = solved
};