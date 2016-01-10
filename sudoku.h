#include <iostream>

class Sudoku
{
public:

// basic commands
  int init();
  int show();

// grid manipulation
  int setgrid(int row, int col, int set);
  int getgrid(int row, int col);
 
// checking functions
  int check(int row, int col, int digit); 
  int listsup(int row, int col);

private:
  int grid[9][9][11]; // [0-8] = digits 1-9 suppositions, 9 = given, 10 = solved
};
