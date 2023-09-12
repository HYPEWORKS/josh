#include <iostream>

#include "BuiltinHandler.hpp"
#include "REPL.hpp"

int main(int argc, char* argv[])
{
	// TODO: Parse command line arguments.

	BuiltinHandler::getInstance()->init();

	return REPL::getInstance()->startREPL();
}
