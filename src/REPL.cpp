#include "REPL.hpp"

// TODO: Create wrapper for unicode since it's a PITA later on.
#include <iostream>
#include <string>
// </TODO>

#include "BuiltinHandler.hpp"

REPL *REPL::__instance = nullptr;

REPL::REPL()
{
  this->running = false;
}

REPL *REPL::getInstance()
{
  if (REPL::__instance == nullptr)
  {
    REPL::__instance = new REPL();
  }

  return REPL::__instance;
}

void REPL::startREPL()
{
  this->running = true;

  this->loop();
}

void REPL::loop()
{
  while (this->running)
  {
    std::string cmd;

    std::cout << std::endl << "$ ";
    std::getline(std::cin, cmd);

    // TODO: Parse command string first before doing this.
    auto builtinCmd = BuiltinHandler::getInstance()->lookupCommand(cmd);
    if (!builtinCmd)
    {
      std::cout << "Command not found -> " << cmd << std::endl;
      continue;
    }
    else
    {
      // TODO: Pass in parsed out arguments.
      builtinCmd->commandInvocation(std::vector<std::string>(), ExecutionContext::REPL);
    }
  }
}

int REPL::endREPL()
{
  this->running = false;
  return 0;
}
