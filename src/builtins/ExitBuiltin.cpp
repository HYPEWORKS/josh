#include "ExitBuiltin.hpp"

#include "../REPL.hpp"

void ExitBuiltin::registerCommand()
{
}

void ExitBuiltin::deregisterCommand()
{
}

int ExitBuiltin::commandInvocation(std::vector<std::string> arguments, ExecutionContext ctx)
{
  if (ctx == ExecutionContext::REPL) {
    REPL::getInstance()->endREPL();
  }
  else {
    // TODO:
    return 0;
  }

  return 0;
}
