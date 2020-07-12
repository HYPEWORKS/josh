#ifndef DM_JOSH_HISTORY_HPP_
#define DM_JOSH_HISTORY_HPP_

#include <vector>
#include <string>

class History
{
private:
  static History *__instance;
  std::string file;
  History();

public:
  static History *getInstance();

  bool init();

  void emplace(std::string line);
};

#endif
