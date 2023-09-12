#ifndef DM_JOSH_EXIT_BUILTIN_HPP_
#define DM_JOSH_EXIT_BUILTIN_HPP_

#include "IBuiltin.hpp"

class ExitBuiltin : public IBuiltin
{
public:
	void registerCommand();
	void deregisterCommand();
	int commandInvocation(std::vector<std::string> arguments, ExecutionContext ctx);
};

#endif
