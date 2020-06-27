#include "CdBuiltin.hpp"

#include <stdlib.h>
#include <iostream>

// TODO: Create compat layer for non POSIX systems
#include <unistd.h>
#include <string.h>

void CdBuiltin::registerCommand()
{
  this->setCommandDescription("Changes directory to the specified directory.");
}

void CdBuiltin::deregisterCommand()
{
}

int CdBuiltin::commandInvocation(std::vector<std::string> arguments, ExecutionContext ctx)
{
  // If no parameters, change into home (~)
  if (arguments.size() == 0)
  {
    chdir(getenv("HOME"));

    return 0;
  }

  // We just need the first argument right now
  auto dest = arguments[0];

  // TODO: Handle ~user as well.
  if (dest[0] == '~')
  {
    chdir(getenv("HOME"));

    return 0;
  }

  if (chdir(dest.c_str()) != 0)
  {
    std::cout << "Could not navigate to -> " << dest << std::endl;
    std::cout << strerror(errno) << std::endl;

    return 1;
  }

  return 0;
}
