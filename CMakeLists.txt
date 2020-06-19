cmake_minimum_required(VERSION 3.0.2)

project(josh)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_BUILD_TYPE MATCHES DEBUG)
  add_compile_definitions(_DEBUG)
endif(CMAKE_BUILD_TYPE MATCHES DEBUG)

if(CMAKE_BUILD_TYPE MATCHES RELEASE)
  add_compile_definitions(_NDEBUG)
endif(CMAKE_BUILD_TYPE MATCHES RELEASE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../output/bin)

add_subdirectory(src)
