#ifndef DM_JOSH_HELP_BUILTIN_HPP_
#define DM_JOSH_HELP_BUILTIN_HPP_

#include "IBuiltin.hpp"

class HelpBuiltin : public IBuiltin
{
public:
	void registerCommand();
	void deregisterCommand();
	int commandInvocation(std::vector<std::string> arguments, ExecutionContext ctx);
};

#endif
