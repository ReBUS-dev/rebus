cmake_minimum_required(VERSION 3.16)
project(RebusDevBackup)

set(CMAKE_CXX_STANDARD 20)

add_executable(RebusDevBackup main.cpp core/Core.cpp core/header/Core.h)