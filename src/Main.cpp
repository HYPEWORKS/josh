#include <iostream>

#include "BuiltinHandler.hpp"
#include "REPL.hpp"

int main(int argc, char *argv[])
{
  BuiltinHandler::getInstance()->init();

  return REPL::getInstance()->startREPL();
}
