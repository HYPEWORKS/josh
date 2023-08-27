#include "ExitBuiltin.hpp"

#include "../REPL.hpp"

#include <iostream>

void ExitBuiltin::registerCommand()
{
	this->setCommandDescription("Exits the shell or terminates execution of a script with a default exit code of 0.");
}

void ExitBuiltin::deregisterCommand()
{
}

int ExitBuiltin::commandInvocation(std::vector<std::string> arguments, ExecutionContext ctx)
{
	// Show the help if "--help" is passed as an argument.
	if (arguments.size() == 1 && arguments[0] == "--help")
	{
		std::cout << this->getCommandDescription() << std::endl;

		return 0;
	}

	// Get the exit code from the arguments if it exists.
	int exitCode = 0;

	if (arguments.size() > 0)
	{
		try
		{
			exitCode = std::stoi(arguments[0]);
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid exit code: " << arguments[0] << std::endl;

			return 1;
		}
	}

	if (ctx.type == ExecutionContextType::REPL)
	{
		REPL::peekInstance()->endREPL(exitCode);
	}
	else
	{
		// TODO:
		return exitCode;
	}

	return exitCode;
}
