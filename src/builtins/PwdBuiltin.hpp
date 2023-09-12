#ifndef DM_JOSH_PWD_BUILTIN_HPP_
#define DM_JOSH_PWD_BUILTIN_HPP_

#include "IBuiltin.hpp"

class PwdBuiltin : public IBuiltin
{
public:
	void registerCommand();
	void deregisterCommand();
	int commandInvocation(std::vector<std::string> arguments, ExecutionContext ctx);
};

#endif
