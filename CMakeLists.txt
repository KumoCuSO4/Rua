cmake_minimum_required(VERSION 3.10)

project(Rua)

include_directories(compiler)
include_directories(utils)
include_directories(core)

add_executable(RuaExe test.cpp)