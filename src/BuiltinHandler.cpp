#include "BuiltinHandler.hpp"

#include <algorithm>

#include "builtins/ExitBuiltin.hpp"

BuiltinHandler *BuiltinHandler::__instance = nullptr;

BuiltinHandler *BuiltinHandler::getInstance()
{
  if (BuiltinHandler::__instance == nullptr)
  {
    BuiltinHandler::__instance = new BuiltinHandler();
  }

  return BuiltinHandler::__instance;
}

BuiltinHandler::BuiltinHandler()
{
  this->builtinsMap = std::map<std::string, IBuiltin *>();
}

BuiltinHandler::~BuiltinHandler()
{
  std::for_each(this->builtinsMap.begin(), this->builtinsMap.end(), [](std::pair<std::string, IBuiltin *> pair) {
    pair.second->deregisterCommand();

    free(pair.second);
  });
}

void BuiltinHandler::loadBuiltin(std::string cmd, IBuiltin *impl)
{
  if (!impl)
  {
    return;
  }

  // Call the builtin's registration logic.
  impl->registerCommand();

  this->builtinsMap.emplace(cmd, impl);
}

void BuiltinHandler::loadBuiltins()
{
  this->loadBuiltin("exit", new ExitBuiltin());
}
