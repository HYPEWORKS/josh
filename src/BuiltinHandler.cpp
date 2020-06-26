#include "BuiltinHandler.hpp"

#include <algorithm>

#include "builtins/ExitBuiltin.hpp"
#include "builtins/PwdBuiltin.hpp"
#include "builtins/CdBuiltin.hpp"
#include "builtins/HelpBuiltin.hpp"

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

  this->builtinsMap.clear();
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
  // TODO: Is this the best place to statically initialize our builtins?
  this->loadBuiltin("exit", new ExitBuiltin());
  this->loadBuiltin("pwd", new PwdBuiltin());
  this->loadBuiltin("cd", new CdBuiltin());
  this->loadBuiltin("help", new HelpBuiltin());
}

void BuiltinHandler::init()
{
  this->loadBuiltins();
}

IBuiltin *BuiltinHandler::lookupCommand(std::string cmd)
{
  size_t count = this->builtinsMap.count(cmd);

  if (count == 0)
  {
    return nullptr;
  }
  else
  {
    return this->builtinsMap[cmd];
  }
}

std::vector<std::string> BuiltinHandler::getListOfCommands() const
{
  std::vector<std::string> temp;

  std::for_each(this->builtinsMap.begin(), this->builtinsMap.end(), [&](std::pair<std::string, IBuiltin *> pair) {
    temp.push_back(pair.first);
  });

  return temp;
}
