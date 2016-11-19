cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 14)

add_subproject(tree)

list(SOURCES main.cpp)

add_executable(hello $(SOURCES))
