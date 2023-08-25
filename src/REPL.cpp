#include "REPL.hpp"

// TODO: Create wrapper for unicode since it's a PITA later on.
#include <iostream>
#include <string>
// </TODO>

#include <ctype.h>
#include <algorithm>

#include "BuiltinHandler.hpp"
#include "History.hpp"

REPL *REPL::__instance = nullptr;

REPL::REPL()
{
  this->running = false;

  if (!History::getInstance()->init())
  {
    // if we fail to create history -- then what?

    throw std::exception();
  }
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

// trim from start (in place)
static inline void ltrim(std::string &s)
{
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
            return !std::isspace(ch);
          }));
}

// trim from end (in place)
static inline void rtrim(std::string &s)
{
  s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
            return !std::isspace(ch);
          }).base(),
          s.end());
}

// TODO: Ignore extra whitespace if wrapped in string ' "
void remove_extra_whitespaces(const std::string &input, std::string &output)
{
  output.clear(); // unless you want to add at the end of existing sring...
  std::unique_copy(input.begin(), input.end(), std::back_insert_iterator<std::string>(output),
                   [](char a, char b) { return isspace(a) && isspace(b); });
}

void REPL::loop()
{
  while (this->running)
  {
    std::string line;

    std::cout << std::endl
              << "$ ";
    std::getline(std::cin, line);

    // TEMPORARY CODE UNTIL WE RE-IMPLEMENT READLINE
    std::string tempLine;
    ltrim(line);
    rtrim(line);
    remove_extra_whitespaces(line, tempLine);
    line = tempLine;

    // If blank line, just continue....
    if (line == "")
    {
      continue;
    }

    // Put into history.
    History::getInstance()->emplace(line);

    std::string cmd;
    std::vector<std::string> arguments;

    // THIS CODE IS BAD BECAUSE IT ASSUMES THAT WE'RE NOT RUNNING SOMETHING VIA ./ OR SOMETHING ELSE

    bool firstSegment = true;
    size_t startPos = 0;
    size_t endPos = 0;
    for (size_t i = 0; i < line.size(); ++i)
    {
      if (isspace(line[i]) || i == line.size() - 1)
      {
        if (i == line.size() - 1)
        {
          endPos = line.size();
        }
        else
        {
          endPos = i;
        }

        auto str = line.substr(startPos, endPos);

        startPos = i + 1;
        if (!firstSegment)
        {
          arguments.push_back(str);
        }
        else
        {
          cmd = str;
          firstSegment = false;
        }
      }
    }

    auto executionContext = ExecutionContext();
    executionContext.type = ExecutionContextType::REPL;

    // TODO: Parse command string first before doing this.
    auto builtinCmd = BuiltinHandler::getInstance()->lookupCommand(cmd);
    if (!builtinCmd)
    {
      // TODO: If not found in builtins, it may be in /bin; /usr/bin etc. so call out to the PATH or something like that
      std::cout << "Command not found -> " << cmd << std::endl;
      continue;
    }
    else
    {
      builtinCmd->commandInvocation(arguments, executionContext);
    }
  }
}

int REPL::endREPL()
{
  this->running = false;
  return 0;
}
