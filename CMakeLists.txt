cmake_minimum_required(VERSION 3.5)
project(CuckooHash)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CuckooTable.h HashFunction.h HashFunction.cpp)
add_executable(CuckooHash ${SOURCE_FILES})