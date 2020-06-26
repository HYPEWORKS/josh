cmake_minimum_required(VERSION 3.0.2)

project(josh)

set(CMAKE_CXX_STANDARD 17)

add_executable(
  josh

  builtins/IBuiltin.hpp
  builtins/ExitBuiltin.hpp
  builtins/ExitBuiltin.cpp
  builtins/PwdBuiltin.hpp
  builtins/PwdBuiltin.cpp
  builtins/CdBuiltin.hpp
  builtins/CdBuiltin.cpp
  builtins/HelpBuiltin.hpp
  builtins/HelpBuiltin.cpp

  BuiltinHandler.hpp
  BuiltinHandler.cpp

  REPL.hpp
  REPL.cpp
  Main.cpp
)
