#include <iostream>
#include "sudoku.h"

int main()
{
  Sudoku su;
  su.init();
  std::cout << "Hello world!" << std::endl;  
  su.show();
  std::cout << "Checking to see if a 5 would go in (5,5)..." << std::endl;
  if (su.check(5,5,5))
  {
      std::cout << "Invalid supposition." << std::endl;
  }
  else
  {
      std::cout << "Valid supposition." << std::endl;
  }
  
  std::cout << "Valid suppositions:" << std::endl;
  su.listsup(5,5);
  
  return 1;
}
