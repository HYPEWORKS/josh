#include "ExitBuiltin.hpp"

#include "../REPL.hpp"

void ExitBuiltin::registerCommand()
{
}

void ExitBuiltin::deregisterCommand()
{
}

int ExitBuiltin::commandInvocation(std::vector<std::string> arguments)
{
  // TODO: Get context if running in script or REPL.
  REPL::getInstance()->endREPL();

  return 0;
}
