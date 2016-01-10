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
    std::cout << "\t\t";
    for (j=0; j<9; j++)
	{
	  k = grid[i][j][9];
	  if (k==0)
	    std::cout << ".";
	  else
	    std::cout << k;
	}
	std::cout << std::endl;
  }
}

int Sudoku::check(int row, int col, int digit)
{
  int i,j,k,l, conflict_found=0;
  
  // check the row for conflicts
//  std::cerr << "\nrow";
  for (i=0; i<9; i++) 
  {
    if (i!=col)
	{
	  k=grid[row][i][10];
	  if (k == digit)
	  {
	    conflict_found=1;
//		std::cerr << "k=d(" << k << ")";
		grid[row][col][k-1]=1;
	  }
	  else
	  {
	    if (k != 0)
		{
		  grid[row][col][k-1]=1;
//		  std::cerr << "k!d(" << k << ")";
		}
	  }
	}
  }
  
  // check the column for conflicts
//  std::cerr << "\ncol";
  for (j=0; j<9; j++)
  {
    if (j!=row)
	{
	  k=grid[j][col][10];
	  if (k==digit)
	  {
	    conflict_found=1;
//		std::cerr << "k=d(" << k << ")";
		grid[row][col][k-1]=1;
	  }
	  else
	  {
	    if (k != 0)
		{
		  grid[row][col][k-1]=1;
//		  std::cerr << "k!d(" << k << ")";
		}
	  }
	}
  }
  // check the box for conflicts
//  std::cerr << "\nbox";
  for (i=row-(row%3); i<(row-(row%3)+3); i++)
  {
    for (j=col-(col%3); j<(col-(col%3)+3); j++)
	{
	  if (i!=row || j!=col)
	  {
//	    std::cerr << "[" << i << "," << j << "]";
	    k=grid[i][j][10];
		if (k==digit)
		{
		  conflict_found=1;
//		  std::cerr << "k=d(" << k << ")";
		  grid[row][col][k-1]=1;
		}
		else
		{
		  if (k != 0)
		  {
		    grid[row][col][k-1]=1;
//			std::cerr << "k!d(" << k << ")";
	      }
		}
	  }	  
	}
  }
  
//  std::cerr << "\n";
  
  return conflict_found;
}
  
int Sudoku::listsup(int row, int col)
{
  int i;
  for (i=0; i<9; i++)
  {
    if (grid[row][col][i]==1)
	{
      std::cout << "X";
	}
	else
	{
	  std::cout << i+1;
	}
  }
  std::cout << std::endl;
  return 1;
}
  
