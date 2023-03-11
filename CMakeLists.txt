cmake_minimum_required(VERSION 3.0.0)
project(DataStruct VERSION 0.1.0)

set(CMAKE_C_FLAGS -fexec-charset=GBK)
set(CMAKE_CXX_FLAGS -fexec-charset=GBK)

add_subdirectory(Experiment)
add_subdirectory(Graph)
add_subdirectory(List)
add_subdirectory(Search)
add_subdirectory(Sort)
add_subdirectory(Stack)
add_subdirectory(ClassDesign)

add_executable(tmp tmp.cpp)