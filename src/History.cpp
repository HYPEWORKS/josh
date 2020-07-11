#include "History.hpp"

#include <vector>
#include <string>
#include <sstream>

#include <unistd.h>
#include <stdlib.h>

History *History::__instance = nullptr;

History *History::getInstance()
{
  if (!History::__instance)
  {
    History::__instance = new History();
  }

  return History::__instance;
}

void History::init()
{
  std::stringstream historyFilePathBuilder;

  historyFilePathBuilder << getenv("HOME") << "/.josh_history";

  auto historyFilePath = historyFilePathBuilder.str();

  // TODO: Check file exist, if not touch file.
}
