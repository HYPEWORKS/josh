#ifndef DM_JOSH_EXECUTION_CONTEXT_HPP_
#define DM_JOSH_EXECUTION_CONTEXT_HPP_

enum class ExecutionContextType : char
{
	// If we're at the prompt.
	REPL = 0,

	// If we're running in a script.
	SCRIPT = 1,

	// If we're running in a forked instance.
	SUBSHELL = 2
};

typedef struct
{
	ExecutionContextType type;
} ExecutionContext;

#endif
