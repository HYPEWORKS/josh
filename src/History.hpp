#ifndef DM_JOSH_HISTORY_HPP_
#define DM_JOSH_HISTORY_HPP_

#include <vector>

class History
{
private:
  static History *__instance;

public:
  static History *getInstance();

  void init();
};

#endif
