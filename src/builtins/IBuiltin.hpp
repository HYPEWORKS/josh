#ifndef DM_JOSH_IBUILTIN_HPP_
#define DM_JOSH_IBUILTIN_HPP_

// we're using ascii as a intentional limitation
#include <string>

#include <vector>

class IBuiltin
{
public:
  virtual void registerCommand() = 0;
  virtual void deregisterCommand() = 0;

  virtual int commandInvocation(std::vector<std::string> arguments) = 0;
};

#endif
