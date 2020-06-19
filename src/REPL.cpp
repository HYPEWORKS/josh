#include "REPL.hpp"

// TODO: Create wrapper for unicode since it's a PITA later on.
#include <iostream>
#include <string>
// </TODO>

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
  while(this->running)
  {
    std::string cmd;

    std::cout << "$ ";
    std::getline(std::cin, cmd);

    // TODO: Not do this.
    if (cmd.compare("exit") == 0) {
      this->endREPL();
    }
  }
}

int REPL::endREPL()
{
  this->running = false;
  return 0;
}
