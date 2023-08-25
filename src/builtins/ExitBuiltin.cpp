#include "ExitBuiltin.hpp"

#include "../REPL.hpp"

void ExitBuiltin::registerCommand()
{
  this->setCommandDescription("Exits the shell or terminates execution of a script");
}

void ExitBuiltin::deregisterCommand()
{
}

int ExitBuiltin::commandInvocation(std::vector<std::string> arguments, ExecutionContext ctx)
{
  if (ctx.type == ExecutionContextType::REPL)
  {
    REPL::getInstance()->endREPL();
  }
  else
  {
    // TODO:
    return 0;
  }

  return 0;
}
