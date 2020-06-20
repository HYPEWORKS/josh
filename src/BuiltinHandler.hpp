#ifndef DM_JOSH_BUILTIN_HANDLER_HPP_
#define DM_JOSH_BUILTIN_HANDLER_HPP_

#include "builtins/IBuiltin.hpp"

#include <map>
#include <string>

class BuiltinHandler
{
private:
  static BuiltinHandler *__instance;
  std::map<std::string, IBuiltin *> builtinsMap;

  BuiltinHandler();
  ~BuiltinHandler();
  void loadBuiltin(std::string cmd, IBuiltin *impl);

public:
  static BuiltinHandler *getInstance();

  void loadBuiltins();
};

#endif
