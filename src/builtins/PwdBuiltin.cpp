#include "PwdBuiltin.hpp"

#include <iostream>

#include <stdlib.h>

// TODO: Create compat layer for non POSIX systems
#include <unistd.h>

void PwdBuiltin::registerCommand()
{
  this->setCommandDescription("Presents the current working directory to stdout.");
}

void PwdBuiltin::deregisterCommand()
{
}

int PwdBuiltin::commandInvocation(std::vector<std::string> arguments, ExecutionContext ctx)
{
  long size;
  char *buf;
  char *ptr;

  size = pathconf(".", _PC_PATH_MAX);

  if ((buf = (char *)malloc((size_t)size)) != NULL)
    ptr = getcwd(buf, (size_t)size);

  std::cout << ptr << std::endl;

  free(ptr);
  
  return 0;
}
