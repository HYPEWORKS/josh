#include "IBuiltin.hpp"

class ExitBuiltin : public IBuiltin
{
public:
  void registerCommand();
  void deregisterCommand();
  int commandInvocation(std::vector<std::string> arguments, ExecutionContext ctx);
};
