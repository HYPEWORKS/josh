#include "HelpBuiltin.hpp"

#include "../BuiltinHandler.hpp"

#include <iostream>

void HelpBuiltin::registerCommand()
{
	this->setCommandDescription("Displays some helpful info about stuff");
}

void HelpBuiltin::deregisterCommand()
{
	// Nothing to do here.
}

int HelpBuiltin::commandInvocation(std::vector<std::string> arguments, ExecutionContext ctx)
{
	auto cmdList = BuiltinHandler::getInstance()->getListOfCommands();

	if (arguments.size() == 1)
	{
		auto cmd = BuiltinHandler::getInstance()->lookupCommand(arguments[0]);

		if (!cmd)
		{
			std::cout << "Unable to get help for " << arguments[0] << std::endl;

			return 1;
		}
		else
		{
			if (cmd == this)
			{
				// yo dawg, I heard you like help
				std::cout << "yo dawg" << std::endl;
				return 0;
			}
			// TODO: Fetch "rich" help for the command.
			std::cout << cmd->getCommandDescription() << "\n"
				<< std::endl;

			return 0;
		}
	}

	std::cout << "Here's a list of built-in functions:\n";
	for (std::string cmd : cmdList)
	{
		std::cout << "\t* " << cmd << std::endl;
	}

	return 0;
}
