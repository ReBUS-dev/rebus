cmake_minimum_required(VERSION 3.16)
project(RebusDevBackup)

set(CMAKE_CXX_STANDARD 20)

add_executable(RebusDevBackup main.cpp RebusBackup/lib/WorkArchive.cpp RebusBackup/lib/header/WorkArchive.h RebusBackup/global_value.cpp RebusBackup/Core/lib/WorkFile.cpp RebusBackup/Core/lib/header/WorkFile.h)