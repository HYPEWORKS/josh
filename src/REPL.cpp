#include "REPL.hpp"

// TODO: Create wrapper for unicode since it's a PITA later on.
#include <iostream>
#include <string>
// </TODO>

#include "BuiltinHandler.hpp"

REPL *REPL::__instance = nullptr;

REPL::REPL()
{
  this->running = false;
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

void REPL::loop()
{
  while (this->running)
  {
    std::string line;

    std::cout << std::endl
              << "$ ";
    std::getline(std::cin, line);

    // TEMPORARY CODE UNTIL WE RE-IMPLEMENT READLINE
    ltrim(line);
    rtrim(line);

    std::string cmd;
    std::vector<std::string> arguments;

    // THIS CODE IS BAD BECAUSE IT ASSUMES THAT WE'RE NOT RUNNING SOMETHING VIA ./ OR SOMETHING ELSE

    bool firstSegment = true;
    size_t startPos = 0;
    size_t endPos = 0;
    for (size_t i = 0; i < line.size(); ++i)
    {
      if (line[i] == ' ' || i == line.size() - 1)
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
      builtinCmd->commandInvocation(arguments, ExecutionContext::REPL);
    }
  }
}

int REPL::endREPL()
{
  this->running = false;
  return 0;
}
