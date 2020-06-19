
class REPL
{
private:
  static REPL *__instance;
  REPL();

  bool running;

  void read();
  void execute();
  void print();
  void loop();

public:
  static REPL *getInstance();

  void startREPL();
  int endREPL();
};
