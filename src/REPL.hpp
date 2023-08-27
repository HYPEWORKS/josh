
class REPL
{
private:
	static REPL* __instance;
	REPL();

	bool running;
	int exitCode;

	void read();
	void execute();
	void print();
	void loop();

public:
	static REPL* getInstance();
	static REPL* peekInstance();

	int startREPL();
	void endREPL(int exitCodeOverride = 0);
};
