#include "History.hpp"

#include <vector>
#include <string>
#include <sstream>
#include <filesystem>
#include <iostream>

#include <unistd.h>
#include <stdlib.h>

History *History::__instance = nullptr;

History::History()
{
  std::stringstream historyFilePathBuilder;

  historyFilePathBuilder << getenv("HOME") << "/.josh_history";

  this->file = historyFilePathBuilder.str();
}

History *History::getInstance()
{
  if (!History::__instance)
  {
    History::__instance = new History();
  }

  return History::__instance;
}

bool History::init()
{
  if (!std::filesystem::exists(this->file))
  {
    FILE *fp = fopen(this->file.c_str(), "w");
    if (!fp)
    {
      // This shouldn't really happen...
      std::cerr << "josh: ERROR! Unable to create history file " << this->file << " for reason: " << strerror(errno) << std::endl;

      // TODO: What do now?
      return false;
    }

    fclose(fp);
  }
  else
  {
    FILE *fp = fopen(this->file.c_str(), "r");
    if (!fp)
    {
      // This shouldn't really happen...
      std::cerr << "josh: ERROR! Unable to read history file " << this->file << " for reason: " << strerror(errno) << std::endl;

      // TODO: What do now?
      return false;
    }

    fclose(fp);
  }

  return true;
}

void History::emplace(std::string line)
{
  FILE *fp = fopen(this->file.c_str(), "a");

  if (!fp)
  {
    std::stringstream ss;

    ss << "josh: ERROR! Unable to open the history file (" << this->file << ") for writing. Reason: " << strerror(errno) << std::endl;

    throw std::runtime_error(ss.str());
  }

  fprintf(fp, "%s\n", line.c_str());

  fclose(fp);
}
