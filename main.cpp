#include <iostream>
#include "sudoku.h"

int main()
{
  Sudoku su;
  su.init();
  std::cout << "Hello world!" << std::endl;  
  su.show();
  return 1;
}
