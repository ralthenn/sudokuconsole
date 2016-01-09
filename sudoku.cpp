#include <iostream>
#include "sudoku.h"

int Sudoku::init()
{
  int initialization[81] = {	5, 3, 0, 0, 7, 0, 0, 0, 0,
							6, 0, 0, 1, 9, 5, 0, 0, 0,
							0, 9, 8, 0, 0, 0, 0, 6, 0,
							8, 0, 0, 0, 6, 0, 0, 0, 3,
							4, 0, 0, 8, 0, 3, 0, 0, 1,
							7, 0, 0, 0, 2, 0, 0, 0, 6,
							0, 6, 0, 0, 0, 0, 2, 8, 0,
							0, 0, 0, 4, 1, 9, 0, 0, 5,
							0, 0, 0, 0, 8, 0, 0, 7, 9 };
							
  int i,j,k=0, l;
  
  for (i=0; i<9; i++)
  {
    for (j=0; j<9; j++)
	{
	   for (l=0; l<9; l++)
	   {
	     grid[i][j][l] = 0;
	   }
	   grid[i][j][9] = initialization[k];
	   grid[i][j][10] = initialization[k];
	   k++;
	}
  }
}

int Sudoku::setgrid(int row, int col, int set)
{
  if (row<1 || row>9)
    return -1;
  if (col<1 || col>9)
    return -1;
  if (set<1 || set>9)
    return -1;
  grid[row-1][col-1][10] = set;
  return 1;
}

int Sudoku::getgrid(int row, int col)
{
  if (row<1 || row>9)
    return -1;
  if (col<1 || col>9)
    return -1;
  return grid[row-1][col-1][10];
}

int Sudoku::show()
{
  int i,j,k=0;
  for (i=0; i<9; i++)
  {
    for (j=0; j<9; j++)
	{
	  std::cout << grid[row-1][col-1][9];
	}
	std::cout << endl;
  }
}


  
