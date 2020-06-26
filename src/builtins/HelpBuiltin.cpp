#include "HelpBuiltin.hpp"

#include "../BuiltinHandler.hpp"

#include <iostream>

void HelpBuiltin::registerCommand()
{
}

void HelpBuiltin::deregisterCommand()
{
}

int HelpBuiltin::commandInvocation(std::vector<std::string> arguments, ExecutionContext ctx)
{
  // TODO: provide better help than this
  std::cout << "You don't need no stinkin' help! :^)\n" << std::endl;

  std::cout << "Here's a list of built-in functions:\n";
  for (std::string cmd : BuiltinHandler::getInstance()->getListOfCommands())
  {
    std::cout << "\t* " << cmd << std::endl;
  }

  return 0;
}
