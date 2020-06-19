#include <iostream>

#include "REPL.hpp"

int main(int argc, char* argv[])
{
  std::cout << "Wassup World!" << std::endl;

  REPL::getInstance()->startREPL();
  
  return 0;
}
