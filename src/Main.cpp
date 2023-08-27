#include <iostream>

#include "BuiltinHandler.hpp"
#include "REPL.hpp"

int main(int argc, char *argv[])
{
  BuiltinHandler::getInstance()->init();

  REPL::getInstance()->startREPL();

  return 0;
}
