#include "PwdBuiltin.hpp"

#include <iostream>

#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#include <direct.h>
#define getcwd _getcwd
#else
#include <unistd.h>
#endif

void PwdBuiltin::registerCommand()
{
	this->setCommandDescription("Presents the current working directory to stdout.");
}

void PwdBuiltin::deregisterCommand()
{
}

int PwdBuiltin::commandInvocation(std::vector<std::string> arguments, ExecutionContext ctx)
{
	long size;
	char* buf;
	char* ptr;

#if defined(_PC_PATH_MAX)
	size = pathconf(".", _PC_PATH_MAX);
#else
	size = _MAX_PATH;
#endif

	if ((buf = (char*)malloc((size_t)size)) != NULL)
		ptr = getcwd(buf, (size_t)size);

	std::cout << buf << std::endl;

	free(buf);

	return 0;
}
