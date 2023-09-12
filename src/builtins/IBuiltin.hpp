#ifndef DM_JOSH_IBUILTIN_HPP_
#define DM_JOSH_IBUILTIN_HPP_

#include "../ExecutionContext.hpp"

// we're using ascii as a intentional limitation for now
#include <string>

#include <vector>

class IBuiltin
{
private:
	std::string description;

public:
	virtual void registerCommand() = 0;
	virtual void deregisterCommand() = 0;

	virtual int commandInvocation(std::vector<std::string> arguments, ExecutionContext ctx) = 0;

	void setCommandDescription(std::string desc) { this->description = desc; }
	std::string getCommandDescription() { return this->description; }
};

#endif
