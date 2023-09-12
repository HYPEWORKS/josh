#ifndef DM_JOSH_BUILTIN_HANDLER_HPP_
#define DM_JOSH_BUILTIN_HANDLER_HPP_

#include "builtins/IBuiltin.hpp"

#include <map>
#include <string>
#include <vector>

class BuiltinHandler
{
private:
	static BuiltinHandler* __instance;
	std::map<std::string, IBuiltin*> builtinsMap;

	BuiltinHandler();
	~BuiltinHandler();
	void loadBuiltin(std::string cmd, IBuiltin* impl);
	void loadBuiltins();

public:
	static BuiltinHandler* getInstance();

	void init();

	IBuiltin* lookupCommand(std::string cmd) const;
	std::vector<std::string> getListOfCommands() const;
};

#endif
