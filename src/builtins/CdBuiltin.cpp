#include "CdBuiltin.hpp"

#include <stdlib.h>
#include <iostream>

#include <string.h>

#if defined(_WIN32) || defined(_WIN64)
#include <direct.h>
#define chdir _chdir
#else
#include <unistd.h>
#endif

void CdBuiltin::registerCommand()
{
	this->setCommandDescription("Changes directory to the specified directory.");
}

void CdBuiltin::deregisterCommand()
{
}

int changeIntoHome()
{
	// Get the home directory
#if defined(_WIN32) || defined(_WIN64)
	const char* home = getenv("USERPROFILE");
#else
	const char* home = getenv("HOME");
#endif

	if (home == nullptr)
	{
		std::cout << "Could not find home directory." << std::endl;

		return 1;
	}

	// Change into the home directory
	if (chdir(home) != 0)
	{
		std::cout << "Could not navigate to '" << home << "'\n";
		std::cout << strerror(errno) << std::endl;

		return 1;
	}

	return 0;
}

int CdBuiltin::commandInvocation(std::vector<std::string> arguments, ExecutionContext ctx)
{
	// If no parameters, change into home (~)
	if (arguments.size() == 0)
	{
		return changeIntoHome();
	}

	// We just need the first argument right now
	auto dest = arguments[0];

	// TODO: Handle ~user as well.
	if (dest[0] == '~')
	{
		return changeIntoHome();
	}

	if (chdir(dest.c_str()) != 0)
	{
		std::cout << "Could not navigate to '" << dest << "'\n";
		std::cout << strerror(errno) << std::endl;

		return 1;
	}

	return 0;
}
