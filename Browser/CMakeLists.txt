cmake_minimum_required(VERSION 3.8)
project(Browser)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Console.h Browser.h ../String/String.cpp ../String/String.h ../List/List.h Tab.h Program.h)
add_executable(Browser ${SOURCE_FILES})